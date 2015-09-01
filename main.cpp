/* 
 * File name:   Unix File System Simulator
 * Author:      Connor Stanford 
 * Due Date :   February 23, 2015
 * Due Time :   10:00 pm                             
 * 
 * 
 * Problem Description:
 * Name: Unix File System Simulator
 * Problem Statement: 
 * This program will read data from a text file and sort the data appropriately
 * to resemble the Unix file system. Once sorted, the program will be able to
 * generate and display to the user two different types of directory listings. 
 * 
 * 
 * Problem Specification:
 * The program is intended to read specifically formatted data from a text file
 * one input at a time. Three consecutive inputs will be referred to as a file. 
 * After a file has been received, the program must first interpret the name of 
 * the file and if it is a directory file or plain file. If it is a directory
 * file the program must take into account how many sub files are in the
 * directory. If the file is a plain file, the program must take into account
 * the size of each file.  The program must process and properly link each file 
 * together to resemble the structure of the Unix file system. Once the file
 * system has been assembled, the program must be able to perform both a
 * postOrder and preOrder traversal of the file system and generate a properly
 * formatted directory listing for each that can be displayed to the user. 
 */

#include "FileSystem.h"

using namespace std;
void displayMenu();


int main()
{
    
    FileSystem test; 
    
    //reads input file "filelistings.txt"
    test.scanDisk();
    
    string userSelection;
    while(true)
        //displays a menu for the user. Will repeat until the user enters < 0 >.
    {
        cout << setw(0) << endl;
        displayMenu();  
        cin >> userSelection;
        if(userSelection == "ls")
        {
            test.ls();
        }
        else if(userSelection == "du")
        {
            test.du();
            cout << endl;
        }
        else if(userSelection == "0")
        {
            exit(0);
        }
        else
        {
            cout << endl;
            cout << "Invalid command. Please enter < ls >, < ds >, or < 0 >"
                 << endl;
        }
        
        
    }
}
void displayMenu()
{ 
    // displays a menu to user
    char border = '-';
    for (int i = 0; i < 60; i++)
    {
        cout << border;
    }
    cout << endl;
    
    cout <<"Enter[ ls ]to perform a preOrder traversal of the file system."
         << endl << endl;
    cout <<"Enter[ du ]to perform a postOrder traversal of the file system."
         << endl << endl;
    cout << "Enter[ 0 ]to exit the program." << endl;
    
    for (int i = 0; i < 60; i++)
    {
        cout << border;
    }
    cout << endl;
    
}
