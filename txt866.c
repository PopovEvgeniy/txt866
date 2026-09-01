#include "txt866.h"
#include "exitcode.h"

void show_intro();
void show_error(const char *message);
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
  exit(COMMAND_LINE_ARGUMENTS_ERROR);
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
 puts("TXT866 2.2.1");
 puts("The Windows-1251 to DOS-866 code page converter by Popov Evgeniy Alekseyevich,2010-2026 years");
 puts("This software is distributed under the GNU GENERAL PUBLIC LICENSE");
 putchar('\n');
}

void show_error(const char *message)
{
 fputc('\n',stderr);
 fputs(message,stderr);
 fputc('\n',stderr);
}

FILE *open_input_file(const char *name)
{
 FILE *target=NULL;
 if (name!=NULL)
 {
  target=fopen(name,"rt");
 }
 if (target==NULL)
 {
  show_error("Can't open the input file");
  exit(OPEN_FILE_ERROR);
 }
 return target;
}

FILE *create_output_file(const char *name)
{
 FILE *target=NULL;
 if (name!=NULL)
 {
  target=fopen(name,"wt");
 }
 if (target==NULL)
 {
  show_error("Can't create the output file");
  exit(CREATE_FILE_ERROR);
 }
 return target;
}

int read_data(FILE *input)
{
 int source=0;
 source=fgetc(input);
 if (ferror(input)!=0)
 {
  show_error("Can't read data!");
  exit(READ_DATA_ERROR);
 }
 return source;
}

void write_data(const int target,FILE *output)
{
 if (fputc(target,output)==EOF)
 {
  show_error("Can't write data!");
  exit(WRITE_DATA_ERROR);
 }

}

int convert_code(const int target)
{
 int result=0;
 result=target;
 if (target==168)
 {
  result=240;
 }
 if (target==184)
 {
  result=241;
 }
 if ((target>=192) && (target<=239))
 {
  result-=64;
 }
 if (target>=240)
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
 for (original=read_data(input);original!=EOF;original=read_data(input))
 {
  write_data(convert_code(original),output);
 }
 fclose(input);
 fclose(output);
}