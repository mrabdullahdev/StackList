// cStack.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string.h>
#include "Node.h"
#include "stack.h"

using namespace std;

// functions used in program
bool isAlpha(char chr);
int sizeOfString(string str);
int charToNum(char chr);
void postSolving(string str);


// main function ***********************************************************
int main()
{
	string str;
	cout << "Enter the postfix expression to solve:\n";
	cin >> str;	// taking input from user
	postSolving(str);	//calling function for solving postfix expression
	
	return 0;
}
// main ended***************************************************************

// function for checking if character is a number or not
bool isAlpha(char chr)
{
	if (chr > 47 && chr < 58)
		return true;
	else
		return false;
}


// function to find size of string
int sizeOfString(string str)
{
	int size = 0;
	for (int i = 0; str[i] != '\0'; i++)
		size++;
	return size;
}
// function for converting character to Number
int charToNum(char chr)
{
	int num;
	num = chr - 48;
	return num;
}
// function for solving postfix expression
void postSolving(string str)
{
	int opr1, opr2, result, finalResult;
	char e;
	stack s1;	// stack class object created
	for (int i = 0; i < sizeOfString(str); i++)	// moving through the string
	{
		e = str[i];
		if (isAlpha(e))	// condition for checking if character is a digit
		{
			s1.push(charToNum(e));
		}
		// in case not a digit
		else
		{
			if (s1.getSize() >= 2)	// checking number of Nodes in List
			{
				opr2 = s1.pop();
				opr1 = s1.pop();
				switch (e)	// switch for performing different mathematical operations
				{
				case '*':	// for multiplying
					result = opr1 * opr2;
					break;
				case '/':	// dividing
					if (opr2 == 0)	// in case divident is 0
						cout << "cant divide by 0\n";
					else
						result = opr1 / opr2;
					break;
				case '+':	// adding
					result = opr1 + opr2;
					break;
				case '-':	// subtracting
					result = opr1 - opr2;
					break;
				case '%':	// taking mod
					result = opr1 % opr2;
					break;
				default:	// when wrong input is given
					cout << "string is incorrect.So putting default value as 0.\n";
					result = 0;
				}
				s1.push(result);
			}
			else
			{
				cout << "string is incorrect\n";
				break;
			}
		}
	}
	if (s1.getSize() == 1)	// checking stack size
	{
		finalResult = s1.pop();
		cout << "Result is: ";
		cout << finalResult << endl;	// displaying result
	}
	else
	{
		cout << "string is incorrect\n";
	}
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
