# unix-filesystem-simulator
===========================


This program reads a text file, constructs a filesystem, and uses both a breadthfirst and depthfirst search to mimmick the "ls" and "du" unix commands. 


 Problem Description:
 
Name: Unix File System Simulator
Problem Statement: 
This program will read data from a text file and sort the data appropriately
to resemble the Unix file system. Once sorted, the program will be able to
generate and display to the user two different types of directory listings. 


Problem Specification

The program is intended to read specifically formatted data from a text file
one input at a time. Three consecutive inputs will be referred to as a file. 
After a file has been received, the program must first interpret the name of 
the file and if it is a directory file or plain file. If it is a directory
file the program must take into account how many sub files are in the
directory. If the file is a plain file, the program must take into account
the size of each file.  The program must process and properly link each file 
together to resemble the structure of the Unix file system. Once the file
system has been assembled, the program must be able to perform both a
postOrder and preOrder traversal of the file system and generate a properly
formatted directory listing for each that can be displayed to the user.
