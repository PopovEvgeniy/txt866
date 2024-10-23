                             TXT866
                           
                           Version 2.0.7.1
                            
           Win-1251 to Dos-866 code-page converter for text files by Popov Evgeniy Alekseyevich

Description

This program lets you convert text file content from the Win-1251 to the Dos-866 code-page.

License

This program is distributed under GNU GENERAL PUBLIC LICENSE.

Command-line arguments

This program takes an input file name and output file name as the command-line arguments.
The output file will be created if needed.

Exit codes

0: Operation was successfully completed.
1: Can't open the input file.
2: Can't create the output file.
3: Invalid command-line arguments.

Source code

The code was compiled under Open Watcom.
You can compile it with any modern C compiler.
The source code can compile for a wide range of operating systems, but you need to create a makefile or a build script by yourself.
I provide the binary files (Dos and Windows) and the makefile for Linux.

Install and uninstall under Linux

Follow these steps:

1. Extract the content of the source code archive.
2. Open a terminal and go to the source code directory.
3.
Run as root to install: make install
Run as root to uninstall: make uninstall

Contact

You can send me a letter at tuzik87@inbox.ru.

Changelog

0.1: Initial version.
0.2-1.0: The small changes.
1.1: The program was totally rewritten.
1.2-2.0: The small changes.
2.0.1: The makefile updated.
2.0.1.1: The Windows version of TXT866 was recompiled under Open Watcom.
2.0.1.2: The makefile updated.
2.0.2: The small changes.
2.0.2.1: Documentation updated.
2.0.3-2.0.5: The small changes.
2.0.6: Visual C++ support improved.
2.0.6.1-2.0.6.2: Documentation updated.
2.0.7: The small changes.
2.0.7.1: Documentation updated.