#include "txt866.h"

void show_intro();
FILE *open_input_file(const char *name);
FILE *create_output_file(const char *name);
int read_data(FILE *input);
void write_data(const int target,FILE *output);
int convert_code(const int target);
void work(const char *source,const char *target);

int main(int argc, char *argv[])
{
 show_intro();
 if (argc<3)
 {
  puts("You must give an input file name and an output file name as the command-line arguments");
  exit(5);
 }
 else
 {
  puts("Working.Please wait...");
  work(argv[1],argv[2]);
  puts("The work has been finished");
 }
 return 0;
}

void show_intro()
{
 putchar('\n');
 puts("TXT866");
 puts("Version 2.1.5");
 puts("The Windows-1251 to DOS-866 code page converter by Popov Evgeniy Alekseyevich,2010-2026 years");
 puts("This software is distributed under the GNU GENERAL PUBLIC LICENSE");
 putchar('\n');
}

FILE *open_input_file(const char *name)
{
 FILE *target=NULL;
 if (name==NULL)
 {
  puts("Can't open the input file");
  exit(1);
 }
 target=fopen(name,"rt");
 if (target==NULL)
 {
  puts("Can't open the input file");
  exit(1);
 }
 return target;
}

FILE *create_output_file(const char *name)
{
 FILE *target=NULL;
 if (name==NULL)
 {
  puts("Can't create the output file");
  exit(2);
 }
 target=fopen(name,"wt");
 if (target==NULL)
 {
  puts("Can't create the output file");
  exit(2);
 }
 return target;
}

int read_data(FILE *input)
{
 int source=0;
 source=fgetc(input);
 if (ferror(input)!=0)
 {
  puts("Can't read data!");
  exit(3);
 }
 return source;
}

void write_data(const int target,FILE *output)
{
 if (fputc(target,output)==EOF)
 {
  puts("Can't write data!");
  exit(4);
 }

}

int convert_code(const int target)
{
 int result=0;
 result=target;
 if ((result>=192) && (result<=239))
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
 FILE *input=NULL;
 FILE *output=NULL;
 int original=0;
 input=open_input_file(source);
 output=create_output_file(target);
 while (!feof(input))
 {
  original=read_data(input);
  write_data(convert_code(original),output);
 }
 fclose(input);
 fclose(output);
}