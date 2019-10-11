#include "stack.h"

// parametric constructor
stack::stack(int num)
{
	Node* newNode = new Node();
	newNode->setValue(num);
	top = newNode;
	size++;
}

// parametric constructor
stack::stack(Node* newNode)
{
	top = newNode;
	size++;
}
// function for adding new Node to Stack
void stack::push(int num)
{
	Node* newNode = new Node;
		newNode->setNextNode(top);
		top = newNode;
		top->setValue(num);
	size++;
}
// function for removing and returning top Node
int stack::pop()
{
		Node* newNode = new Node;
		newNode = top;
		top = top->getNextNode();
		size--;
		return newNode->getValue();	
}
// function for getting value of top Node
int stack::get()
{
	return top->getValue();
}
// for getting size of stack
int stack::getSize()
{
	return size;
}
// Displaying Nodes of stack
void stack::displayStack()
{
	if (isEmpty())
	{
		cout << "There are no Nodes in Stack.\n";
	}
	// when stack is Not Empty
	else
	{
		Node* ptr;
		ptr = top;
		cout << "Nodes in stack are:/n";
		for (int i = 0; i < size; i++)
		{
			cout << ptr->getValue() << endl;
			ptr = ptr->getNextNode();
		}
	}
}

// for checking if stack is Empty
bool stack::isEmpty()
{
	if (size == 0)
		return true;
	return false;
}




