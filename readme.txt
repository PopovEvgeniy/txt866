                             TXT866
                           
                           Version 2.0.1.1
                            
           Win-1251 to Dos-866 codepage convertor for text files by Popov Evgeniy Alekseyevich

Description

This program let you convert text files content from Win-1251 to Dos-866 codepage.

License

This program distributed under GNU GENERAL PUBLIC LICENSE.

Command line arguments

This program take an input file name and output file name as command line arguments.
The output file will create if it not exists.

Exit codes

0 - Operation successfully complete.
1 - Can't open input file.
2 - Can't create output file.
3 - Invalid command line arguments.

Source code

This program compiled under Open Watcom.
Source code can be compiled for wide range operation systems, but you need create to makefile or build script by yourself.
I provide only three things: compiled binary files for Windows and Dos, makefile for Linux.

Install and uninstall under Linux

Follow these steps:

1.Extract content of source code archive.
2.Open terminal and go to source code directory.
3.
Run as root for install: make install
Run as root for uninstall: make uninstall

Contact

You can send me a letter to tuzik87@inbox.ru

Changelog

0.1 - initial version.
0.2 - 1.0 - Small changes.
1.1 - Program totally rewritten.
1.2 - 2.0 - Small changes.
2.0.1 - Makefile updated.
2.0.1.1 - Windows version of TXT866 recompiled under Open Watcom.