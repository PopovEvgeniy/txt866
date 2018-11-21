#include <stdio.h>
#include <stdlib.h>

void show_intro();
void command_line_help();
void show_start_message();
void show_end_message();
FILE *open_input_file(const char *name);
FILE *create_output_file(const char *name);
void show_progress(const long int start,const long int stop);
long int get_file_size(FILE *file);
void work(const char *source,const char *target);

int main(int argc, char *argv[])
{
 show_intro();
 if (argc==3)
 {
  work(argv[1],argv[2]);
 }
 else
 {
  command_line_help();
  exit(3);
 }
 return 0;
}

void show_intro()
{
 putchar('\n');
 puts("TXT866");
 puts("Version 1.9");
 puts("Win-1251 to Dos-866 codepage convertor for text files by Popov Evgeniy Alekseyevich,2010-2018 years");
 puts("Distributed under GNU GENERAL PUBLIC LICENSE");
 putchar('\n');
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
 putchar('\n');
 puts("Work finish");
}

FILE *open_input_file(const char *name)
{
 FILE *file;
 file=fopen(name,"rb");
 if (file==NULL)
 {
  putchar('\n');
  puts("Can't open input file");
  exit(1);
 }
 return file;
}

FILE *create_output_file(const char *name)
{
 FILE *file;
 file=fopen(name,"wb");
 if (file==NULL)
 {
  putchar('\n');
  puts("Can't create output file");
  exit(2);
 }
 return file;
}

void show_progress(const long int start,const long int stop)
{
 long int progress;
 progress=(start+1)*100;
 progress/=stop;
 putchar('\r');
 printf("Processing %ld byte from %ld.Progress:%ld%%",start+1,stop,progress);
}

long int get_file_size(FILE *file)
{
 long int length;
 fseek(file,0,SEEK_END);
 length=ftell(file);
 rewind(file);
 return length;
}

void work(const char *source,const char *target)
{
 long int index,length;
 unsigned char data;
 FILE *input;
 FILE *output;
 input=open_input_file(source);
 output=create_output_file(target);
 length=get_file_size(input);
 show_start_message();
 for(index=0;index<length;++index)
 {
  fread(&data,1,1,input);
  if((data>=192)&&(data<=239))
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