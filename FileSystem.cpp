/* 
 * File:   FileSystem.cpp
 * Author: Connor Stanford
 */

#include "FileSystem.h"
using namespace std;

FileSystem::FileSystem() {
    root = new TreeNode;
    //root will not have a sibling - set sibling pointer to NULL by default
    root->nextSibling = NULL;
    root->firstChild = NULL;
}


FileSystem::~FileSystem() {
    delete root;
}

void FileSystem::scanDisk() {
    //simulates reading the drive and building the directory tree
    inFile.open("filelistings.txt");

    /*numOfFiles will be used to check if there is data in the file. If there 
    is data in the file, numOfFiles will also store the number of children
    each input has, if any.*/
    int children, fileSize = 0;
    string fileName;

    //assigns first three inputs to root
    inFile >> children >> fileName >> fileSize;
    
    root->fileName = fileName;
    root->size = fileSize;

    for(int k = 1;k<=children;k++){
        constructTree(inFile, root);}
}

void FileSystem::constructTree(fstream & inFile, TreeNode *currentNode) {
    
    int children, size;
    string name;
    
    if(currentNode->firstChild == NULL) {
        currentNode->firstChild = new TreeNode;
        inFile >> children >> name >> size;
        currentNode->firstChild->fileName = name;
        currentNode->firstChild->size = size;
        if(children != 0) {
            for(int k=1;k<=children;k++) {
                constructTree(inFile, currentNode->firstChild);
            }
        }
    }
    else {
        TreeNode *siblingCheck;
        siblingCheck = currentNode->firstChild;
        while(siblingCheck->nextSibling != NULL){
            siblingCheck = siblingCheck->nextSibling;
        }
        
        siblingCheck->nextSibling = new TreeNode;
        inFile >> children >> name >> size;
        siblingCheck->nextSibling->fileName = name;
        siblingCheck->nextSibling->size = size;
        if(children != 0) {
            for(int k=1;k<=children;k++) {
                constructTree(inFile, siblingCheck->nextSibling);
            }
        }
    }
}

void FileSystem::ls() {
    
    cout << setw(50) << setfill('-') << "\n";
    cout << root->fileName << "/\n";
    int indentCounter = 1;
    preOrder(root->firstChild, indentCounter);
    cout << setw(50) << setfill('-') << "\n";
}

void FileSystem::preOrder(TreeNode* currentNode,int &indentCounter) {
    
    if(currentNode){
        for(int k=0;k<indentCounter;k++) cout << "    ";
        if(isDirectory(currentNode)) {
            cout << currentNode->fileName << '/' << endl;
            indentCounter++;
        }
        else {
            cout << currentNode->fileName << endl;
            if(currentNode->nextSibling == NULL) indentCounter--;
        }
        preOrder(currentNode->firstChild,indentCounter);
        preOrder(currentNode->nextSibling,indentCounter);
    }
}

void FileSystem::du() {
    
    cout << setw(55) << setfill('-') << "\n" << setfill(' ');
    int total = 0, indentCounter = 1;
    postOrder(root->firstChild, total, indentCounter);
    cout << setw(50) << left << root->fileName + '/';
    cout << right << total << endl;
    cout << setw(55) << setfill('-') << "\n";
}

void FileSystem::postOrder(TreeNode* currentNode,int &total, int indentCounter) {
    
    if(currentNode){
        if(isDirectory(currentNode)) {
            int folderTotal = 0;
            postOrder(currentNode->firstChild, folderTotal, indentCounter + 1);
            
            for(int k=0;k<indentCounter;k++) cout << "    ";
      
            cout << setw(50 - indentCounter * 4) << left << currentNode->fileName
            + '/' << right << folderTotal << endl;
            
            total += folderTotal;
        }
        else {
            postOrder(currentNode->firstChild, total, indentCounter + 1);
            for(int k=0;k<indentCounter;k++) cout << "    ";
            cout << setw(50 - indentCounter * 4) << left << currentNode->fileName
                 << right << currentNode->size << endl;
        }
        postOrder(currentNode->nextSibling, total, indentCounter);
        total += currentNode->size;
    }

}

bool FileSystem::isDirectory(TreeNode *ptr) {
    if (ptr->size == 0)
        return true;
    else
        return false;
}







