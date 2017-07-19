#include <stdio.h>
#include <stdlib.h>

void show_intro();
void command_line_help();
void show_start_message();
void show_end_message();
FILE *open_input_file(char *name);
FILE *create_output_file(char *name);
void show_progress(unsigned long int start, unsigned long int stop);
unsigned long int get_file_size(FILE *file);
void work(char *source,char *target);

int main(int argc, char *argv[])
{
 show_intro();
 if (argc<3)
 {
  command_line_help();
  exit(2);
 }
 else
 {
  work(argv[1],argv[2]);
 }
 return 0;
}

void show_intro()
{
 printf("\n");
 puts("TXT866");
 puts("Version 1.6");
 puts("Win-1251 to Dos-866 codepage convertor for text files by Popov Evgeniy Alekseyevich,2010-2016 years");
 puts("Distributed under GNU GENERAL PUBLIC LICENSE");
 printf("\n");
}

void command_line_help()
{
 puts("You must give a input file name and output file name as command line arguments");
}

void show_start_message()
{
 puts("Working.Please wait...");
}

void show_end_message()
{
 puts(" ");
 puts("Work finish");
}

FILE *open_input_file(char *name)
{
 FILE *file;
 file=fopen(name,"rb");
 if (file==NULL)
 {
  puts(" ");
  puts("File operation error");
  exit(1);
 }
 return file;
}

FILE *create_output_file(char *name)
{
 FILE *file;
 file=fopen(name,"wb");
 if (file==NULL)
 {
  puts(" ");
  puts("File operation error");
  exit(1);
 }
 return file;
}

void show_progress(unsigned long int start, unsigned long int stop)
{
 unsigned long int progress;
 progress=start+1;
 progress*=100;
 progress/=stop;
 printf("\r");
 printf("Processing %ld byte from %ld.Progress:%ld%%",start+1,stop,progress);
}

unsigned long int get_file_size(FILE *file)
{
 unsigned long int length;
 fseek(file,0,SEEK_END);
 length=ftell(file);
 rewind(file);
 return length;
}

void work(char *source,char *target)
{
 unsigned long int index,length;
 unsigned char data;
 FILE *input;
 FILE *output;
 input=open_input_file(source);
 output=create_output_file(target);
 length=get_file_size(input);
 show_start_message();
 for(index=0;index<length;index++)
 {
  fread(&data,1,1,input);
  if(data>=192&&data<=239)
  {
   data-=64;
  }
  if(data>=240)
  {
   data-=16;
  }
  show_progress(index,length);
  fwrite(&data,1,1,output);
 }
 fclose(input);
 fclose(output);
 show_end_message();
}