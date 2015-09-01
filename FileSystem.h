/* 
 * File:   FileSystem.h
 * Author: Connor Stanford
*/

#ifndef FILESYSTEM_H
#define	FILESYSTEM_H
//#include "TreeNode.h"

#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

using namespace std;

struct TreeNode
{
    string fileName;
    int size;
    TreeNode *firstChild;
    TreeNode *nextSibling;
};

class FileSystem {
public:
    FileSystem();
    ~FileSystem();
    void scanDisk();
    void ls();
    void du();
    TreeNode *getRoot();

private:
    fstream inFile;
    TreeNode *root;
    void constructTree(fstream &inFile, TreeNode *currentNode);
    void preOrder(TreeNode *currentNode, int &indentCounter);
    void postOrder(TreeNode *currentNode, int &total, int indentCounter);
    bool isDirectory(TreeNode *ptr);


};

#endif	/* FILESYSTEM_H */

