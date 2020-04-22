#include "DialogueTree.h"

DialogueNode::DialogueNode(string Text)
{
	text = Text;
}
DialogueOption::DialogueOption(string Text, DialogueNode* NextNode, int ReturnCode)
{			//doubt we are passing here memory address or value
	text = Text;
	nextNode = NextNode;
	returnCode = ReturnCode;

}

void DialogueTree::init()
{
	//creating references in the stack
	DialogueNode* node0 = new DialogueNode("Hello Brave Warrior"); //in the heap(allocation)
	DialogueNode* node1 = new DialogueNode("I don't want to talk to you" );
	DialogueNode* node2 = new DialogueNode("I have a quest for you");
	DialogueNode* node3 = new DialogueNode("Her's your gold you greedy swine");
	DialogueNode* node4 = new DialogueNode("Collect ten Dandallions");
	(*node0).dialogueOptions.push_back(DialogueOption("Sup Noob\n", node1, 0));
	(*node0).dialogueOptions.push_back(DialogueOption("Hello Strange Voice\n", node2, 0));
	dialogueNode.push_back(node0); //In the heap. 17:15We passed a pointer, not whole DialogueNode!!
	//pushing back helps in deleting memory leak 
	
	node1->dialogueOptions.push_back(DialogueOption("Aww\n", node1, 0));
	dialogueNode.push_back(node1); //In the heap. 17:15We passed a pointer, not whole DialogueNode!!

	(*node2).dialogueOptions.push_back(DialogueOption("K bye\n", nullptr, 0));
	(*node2).dialogueOptions.push_back(DialogueOption("What is it?\n", node4, 0));
	(*node2).dialogueOptions.push_back(DialogueOption("What's the pay\n", node3, 0));
	dialogueNode.push_back(node2); //In the heap. 17:15We passed a point
	
	(*node3).dialogueOptions.push_back(DialogueOption("OK What is it?", node4, 0));
	(*node3).dialogueOptions.push_back(DialogueOption("That sucks I am out\n", nullptr, 0));
	dialogueNode.push_back(node3);

	(*node4).dialogueOptions.push_back(DialogueOption("Let's do it", nullptr, 1));
	(*node4).dialogueOptions.push_back(DialogueOption("No way\n", nullptr, 0));
	dialogueNode.push_back(node4);
}

void DialogueTree::destroyTree()
{
	for (int i = 0; i < dialogueNode.size(); i++) {
		delete dialogueNode[i];
	}
	dialogueNode.clear();
}

int DialogueTree::performDialogue()
{
	
		if (dialogueNode.size() == 0) {
			return -1;
		}
	DialogueNode *currentNode = dialogueNode[0];
	while (true) {
		cout << currentNode->text << "\n\n";
		for (int i = 0; i < currentNode->dialogueOptions.size(); i++) {
			cout << i + 1 << ":  " << currentNode->dialogueOptions[i].text << endl;


		}
		cout << endl;
		int input;
		cin >> input;
		input--;
		if (input<0 || input>currentNode->dialogueOptions.size()) {
			cout << "Invalid input";
		}
		else {
			if (currentNode->dialogueOptions[input].nextNode == nullptr) {
				return currentNode->dialogueOptions[input].returnCode;
			}
			currentNode = currentNode->dialogueOptions[input].nextNode;
			
		}
		cout << "\n";
	}
		return 0;
	}
