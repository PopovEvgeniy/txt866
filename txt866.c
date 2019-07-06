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
unsigned char read_byte(FILE *target);
void write_byte(FILE *target,const unsigned char data);
unsigned char convert_code(const unsigned char target);
void work(const char *source,const char *target);

int main(int argc, char *argv[])
{
 show_intro();
 if (argc==3)
 {
  show_start_message();
  work(argv[1],argv[2]);
  show_end_message();
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
 puts("Version 2.0");
 puts("Win-1251 to Dos-866 codepage convertor for text files by Popov Evgeniy Alekseyevich,2010-2019 years");
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

unsigned char read_byte(FILE *target)
{
 unsigned char data;
 data=0;
 fread(&data,sizeof(unsigned char),1,target);
 return data;
}

void write_byte(FILE *target,const unsigned char data)
{
 fwrite(&data,sizeof(unsigned char),1,target);
}

unsigned char convert_code(const unsigned char target)
{
 unsigned char result;
 result=target;
 if ((result>=192)&&(result<=239))
 {
  result-=64;
 }
 if (result>=240)
 {
  result-=16;
 }
 return result;
}

void work(const char *source,const char *target)
{
 unsigned char original,converted;
 long int index,length;
 FILE *input;
 FILE *output;
 input=open_input_file(source);
 output=create_output_file(target);
 length=get_file_size(input);
 for(index=0;index<length;++index)
 {
  original=read_byte(input);
  converted=convert_code(original);
  write_byte(output,converted);
  show_progress(index,length);
 }
 fclose(input);
 fclose(output);
}