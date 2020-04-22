// ConsoleApplication3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

#include "DialogueTree.h"

int main()
{
    DialogueTree dialogueTree;
    dialogueTree.init();
    int rv = dialogueTree.performDialogue();
    //cout << "This is the rv " << rv << endl;
    
    if (rv == 1) {
        cout << "\n you accepted \n";
    }
    dialogueTree.destroyTree();
    cout << "Enter any key to continue  \n";
    int tmp;
    cin >> tmp;
    return 0;
}
