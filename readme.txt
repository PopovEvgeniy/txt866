                             TXT866
                           
                           Version 2.0.6.2
                            
           Win-1251 to Dos-866 code-page convertor for text files by Popov Evgeniy Alekseyevich

Description

This program lets you convert text file content from Win-1251 to Dos-866 code-page.

License

This program is distributed under GNU GENERAL PUBLIC LICENSE.

Command-line arguments

This program takes an input file name and output file name as command-line arguments.
The output file will be created if needed.

Exit codes

0 — Operation successfully completed.
1 — Can't open input file.
2 — Can't create output file.
3 — Invalid command line arguments.

Source code

The code was compiled under Open Watcom.
You can compile it with any modern C compiler.
The source code can compile for a wide range of operating systems, but you need to create a makefile or build a script by yourself.
I provide the binary files (Dos and Windows) and the makefile for Linux.

Install and uninstall under Linux

Follow these steps:

1. Extract the content of the source code archive.
2. Open a terminal and go to the source code directory.
3.
Run as root to install: make install
Run as root to uninstall: make uninstall

Contact

You can send me a letter to tuzik87@inbox.ru.

Changelog

0.1 — initial version.
0.2 — 1.0 — Small changes.
1.1 — Program was totally rewritten.
1.2 — 2.0 - Small changes.
2.0.1 — Makefile updated.
2.0.1.1 — Windows version of TXT866 recompiled under Open Watcom.
2.0.1.2 — Makefile updated.
2.0.2 — Small changes.
2.0.2.1 — Documentation updated.
2.0.3 — 2.0.5 — Small changes.
2.0.6 — Visual C++ support improved.
2.0.6.1— 2.0.6.2— Documentation updated.