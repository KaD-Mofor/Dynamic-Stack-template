#include <iostream>
#include "DynamicStack.h"
#include <string>

using namespace std;

//Constants for the menu choice
const int PUSH_CHOICE = 1,
POP_CHOICE = 2,
DISPLAY_CHOICE = 3,
QUIT_CHOICE = 0;

//Function Prototype
void menu(int&);
int getStackSize();
void pushStackItem(DynamicStack<string>&);
void popStackItem(DynamicStack<string>&);
void displayStackItems(DynamicStack<string>&);


int main()
{
	int choice;

	//Create the stack
	DynamicStack<string> newStack;

	do
	{
		//Get the user's mwnu choice
		menu(choice);

		try
		{
		//Perform the user's choice
				if (choice != QUIT_CHOICE)
				{
					switch (choice) 
					{
					case PUSH_CHOICE: pushStackItem(newStack); break;
					case POP_CHOICE: popStackItem(newStack); break;
					case DISPLAY_CHOICE: displayStackItems(newStack); break;
					}
				}
		}
		catch (bool ex)
		{
			cout << "\nThe stack is empty!\n" << endl;
		}

		
	} while (choice != QUIT_CHOICE);

	return 0;
}

void menu(int& choice)
{
	cout << "What do you want to do?\n"
		<< "[" << PUSH_CHOICE
		<< "] Push an item onto the stack\n"
		<< "[" << POP_CHOICE
		<< "] Pop top item from the stack\n"
		<< "[" << DISPLAY_CHOICE
		<< "] Display items in stack\n"
		<< "[" << QUIT_CHOICE
		<< "] Quit the program\n" << endl;
	cout << "Enter your choice: ";
	cin >> choice;

	//Input validation
	while (choice <QUIT_CHOICE|| choice >DISPLAY_CHOICE)
	{
		cout << "Enter a valid choice: ";
		cin >> choice;
	}
}

int getStackSize()
{
	int stackSize;
	cout << "\nHow many items do you want to push onto stack? ";
	cin >> stackSize;

	return stackSize;
}

//Pushing items onto stack
void pushStackItem(DynamicStack<string>& newStack)
{
	string item;

	int stackSize = getStackSize();
	cin.ignore();   //clear the input console

	for (int i = 0; i < stackSize; i++)
	{
		cout << "\nEnter an item: ";
		getline(cin, item);
		newStack.push(item);
	}
	cout << endl;
}

//Popping items off the top from a stack
void popStackItem(DynamicStack<string>& newStack)
{
	string item = " ";

	newStack.pop(item);
	if (item != " ") {
		cout<<"\n"<<item << " was popped from stack.\n"<<endl;
	}
}


void displayStackItems(DynamicStack<string>& newStack) {

	string item = " ";

	newStack.display(item);
	if (item != " ") {
		cout << "\n" << item << endl;
	}
}

