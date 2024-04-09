#include "txt866.h"

void show_intro();
FILE *open_input_file(const char *name);
FILE *create_output_file(const char *name);
int convert_code(const int target);
void work(const char *source,const char *target);

int main(int argc, char *argv[])
{
 show_intro();
 if (argc==3)
 {
  puts("Working.Please wait...");
  work(argv[1],argv[2]);
  puts("Work finish");
 }
 else
 {
  puts("You must give a input file name and output file name as command line arguments");
  exit(3);
 }
 return 0;
}

void show_intro()
{
 putchar('\n');
 puts("TXT866");
 puts("Version 2.0.6");
 puts("Win-1251 to Dos-866 code-page convertor for text files by Popov Evgeniy Alekseyevich,2010-2024 years");
 puts("Distributed under GNU GENERAL PUBLIC LICENSE");
 putchar('\n');
}

FILE *open_input_file(const char *name)
{
 FILE *file;
 file=fopen(name,"rt");
 if (file==NULL)
 {
  puts("Can't open input file");
  exit(1);
 }
 return file;
}

FILE *create_output_file(const char *name)
{
 FILE *file;
 file=fopen(name,"wt");
 if (file==NULL)
 {
  puts("Can't create output file");
  exit(2);
 }
 return file;
}

int convert_code(const int target)
{
 int result;
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
 FILE *input;
 FILE *output;
 int original;
 input=open_input_file(source);
 output=create_output_file(target);
 while (!feof(input))
 {
  original=fgetc(input);
  fputc(convert_code(original),output);
 }
 fclose(input);
 fclose(output);
}