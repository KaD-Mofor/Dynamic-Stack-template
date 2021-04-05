#ifndef DYNAMICSTACK_H
#define DYNAMICSTACK_H
#include <iostream>

using namespace std;

//Stack template
template <class T>
class DynamicStack
{
public:
	//Default constructor
	DynamicStack() {
		top = nullptr;
	};

	//Destructor
	~DynamicStack();


	//Operations
	void push(T);
	void pop(T &);
	void display(T &);
	bool isEmpty();

private:
	//Structure for stack nodes
	struct StackNode
	{
		T value;   //value in node
		StackNode* next;  //ptr to next node
	};

	StackNode* top;    //ptr to the head/top node
};

template<class T>
DynamicStack<T>::~DynamicStack()
{
	StackNode* nodePtr, * nextNode;

	//Position nodePtr at the top
	nodePtr = top;

	//Traverse the list deleting the node
	while (nodePtr != nullptr)
	{
		nextNode = nodePtr->next;
		delete nodePtr;
		nodePtr = nextNode;
	}
}

template <class T>
void DynamicStack<T>::push(T obj) {
	StackNode* newNode = nullptr;  //create a newNode ptr

	//Allocate new node to store the obj
	newNode = new StackNode;
	newNode->value = obj;

	//if new node is the first item, it heads the top of the list
	if (isEmpty())
	{
		top = newNode;
		newNode->next = nullptr;
	}
	else
	{
		newNode->next = top;
		top = newNode;
	}
}

template<class T>
void DynamicStack<T>::pop(T& obj)
{
	StackNode* temp = nullptr;    //temp ptr

	bool ex = isEmpty();

	if (ex) {
		throw ex;
	}
	else
	{
		obj = top->value;
		temp = top->next;
		delete top;
		top = temp;
	}
}

template<class T>
void DynamicStack<T>::display(T& obj)
{
	StackNode* temp = nullptr;    //temp ptr

	bool ex = isEmpty();
	if (ex)
	{
		throw ex;
	}
	else
	{
		StackNode* Top = top;   //Top holds the original size of top
		cout << "\nHere are the values in the stack: " << endl;
		while (top != nullptr)
		{
			cout << top->value << endl;
			obj = top->value;
			temp = top->next;
			top = temp;
		}

		top = Top;   // top's value is reinstated to the original value.
	}
}

template<class T>
bool DynamicStack<T>::isEmpty()
{
	if (!top)
		return true;
	else
		return false;
}


#endif // !DYNAMICSTACK_H