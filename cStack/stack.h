
// stack class
#pragma once
#include <iostream>
#include <string.h>
#include "Node.h"
using namespace std;
class stack
{
private:// private members
	Node* top;
	int size;
public:// public members
	// constructors
	stack():top(0),size(0){}
	stack(int num);
	stack(Node* newNode);
	// 
	void push(int num);
	int pop();
	int get();
	int getSize();
	void displayStack();
	bool isEmpty();
};

