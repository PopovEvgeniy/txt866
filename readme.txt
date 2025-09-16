                             TXT866
                           
                           Version 2.0.9.1
                            
           Win-1251 to DOS-866 code page converter by Popov Evgeniy Alekseyevich

The description.

This program lets you convert the text file content from the Win-1251 to the DOS-866 code page.
This program takes an input file name and output file name as the command-line arguments.
The output file will be created if needed.

License.

This program is distributed under the GNU GENERAL PUBLIC LICENSE.

Exit codes.

0: The operation was successfully completed.
1: Can't open the input file.
2: Can't create the output file.
3: The invalid command-line arguments.

The source code.

The code was compiled under Open Watcom.
You can compile it with any modern C compiler.
The source code can compile for a wide range of operating systems, but you need to create a makefile or a build script by yourself.
I provide the binary file for Windows and the makefile for Linux.

Install and uninstall under Linux.

Follow these steps:

1. Extract the content of the source code archive.
2. Open a terminal and go to the source code directory.
3.
Run as root to install: make install
Run as root to uninstall: make uninstall

Version history.

0.1: The initial version.
0.2-1.0: The small changes.
1.1: The program was totally rewritten.
1.2-2.0: The small changes.
2.0.1: The makefile has been updated.
2.0.1.1: The Windows version of TXT866 was recompiled under Open Watcom.
2.0.1.2: The makefile has been updated.
2.0.2: The small changes.
2.0.2.1: The documentation has been updated.
2.0.3-2.0.5: The small changes.
2.0.6: Visual C++ support has improved.
2.0.6.1-2.0.6.2: The documentation has been updated.
2.0.7: The small changes.
2.0.7.1-2.0.7.2: The documentation has been updated.
2.0.8: The source code was recompiled under Tiny C Compiler.
2.0.8.1: The makefile has been updated.
2.0.8.2: The documentation has been updated.
2.0.9: The small changes.
2.0.9.1: The documentation has been updated.