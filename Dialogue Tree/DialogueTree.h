#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;
class DialogueNode;

class DialogueOption { //This class ONLY manages the options('texts') within a NODE!
public:
	DialogueOption(string Text,DialogueNode *NextNode,int ReturnCode);
	string text;
	DialogueNode* nextNode;
	int returnCode;
};

class DialogueNode {
public:
	DialogueNode(string Text);
	string text;
	vector <DialogueOption> dialogueOptions; //This stores all the possible options.
};

class DialogueTree
{
public:
	
	void init();
	void destroyTree();
	int performDialogue();

private:
	vector <DialogueNode*> dialogueNode;
};

