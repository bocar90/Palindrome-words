#pragma once
#include"QueueInterface.h"
#include"StackInterface.h"
#include"PrecondViolatedExcept.h"
#include"ArrayQueue.h"
#include"ArrayStack.h"
#include<fstream>
#include<iostream>
#include<string>
using namespace std;
int main()
{
	string input;
	char ch;
	bool status = false;
	fstream inData;
	ArrayQueue <char> myQueue;
	ArrayStack <char> palindromeStack;
	inData.open("Pallindrome.txt"); //check if the file opens correctly
	if (!inData)
		cout << "Error opening file!" << endl;

	while (!inData.eof())
	{	
		getline(inData, input); //read data from file into a string
	}

	for (int i = 0; i < input.length(); i++) //push characters onto the stack and add them to the queue
	{
		ch = input[i];
		if (ch >= 'a' && ch <= 'z' || ch >= 'A' && ch <= 'Z')
		{
			myQueue.enqueue(ch);
			palindromeStack.push(ch);
		}
	}
	cout << "Your entry is: "<<input<<endl; //display original string 
	
	while (!myQueue.isEmpty() && !palindromeStack.isEmpty())
	{
		char q, s;
		q = myQueue.peekFront(); //store first character of queue into a char variable 
			myQueue.dequeue();  //move front pointer to the next element of the queue
		s = palindromeStack.peek(); //store top character of stack into a char variable 
			palindromeStack.pop();  //pop top of stack and move topPointer to the next character
		if (tolower(q) != tolower(s)) //convert both character to the same case
		{							 //and check if top character of stack is different from first character of queue	
			status = false;
			break;
		}
		else
			status = true;
	}
	if (status)
		cout << "Congrats, your word is a palindrome! " << endl;
	else
		cout << "Sorry, it's not a palindrome! " << endl;

	system("PAUSE");
	return 0;
}