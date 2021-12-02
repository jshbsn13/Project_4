//
// Created by jshbs on 11/10/2021.
//
#include <iostream>
#include "DelimiterStack.h"
using namespace std;

DelimiterStack::~DelimiterStack()
{
    DelimiterNode *nodePtr = nullptr, *nextNode = nullptr;

    //move ptr to top of stack
    nodePtr = top;

    //delete nodes from list
    while (nodePtr != nullptr)
    {
        nextNode = nodePtr->nextNode;
        delete nodePtr;
        nodePtr = nextNode;
    }
}

void DelimiterStack::push(char delimChar, int lineNum, int charCounter)
{
    DelimiterNode *newNode = nullptr; //points to new node

    //allocate new node store data in it
    newNode = new DelimiterNode;
    newNode->character = delimChar;
    newNode->lineNumber = lineNum;
    newNode->charCount = charCounter;

    //if list is empty
    if(isEmpty())
    {
        top = newNode; //new node is the top
        newNode->nextNode = nullptr; //new node is the only node so the next pointer is null
    }
    else //it is not empty
    {
        newNode->nextNode = top;
        top = newNode;
    }
}

void DelimiterStack::popDelimiter(char &delimChar, int &lineNum, int &charCounter)
{
    DelimiterNode *temp = nullptr; //temp pointer

    //make sure stack isn't empty
    if(isEmpty())
    {
        cout << "The stack is empty!" << endl;
    }
    else
    {
        delimChar = top->character;
        lineNum = top->lineNumber;
        charCounter = top->charCount;
        temp = top->nextNode;
        delete top;
        top = temp;

    }
}

bool DelimiterStack::isEmpty()
{
    bool status;

    if (!top)
    {
        status = true;
    }
    else
    {
        status = false;
    }

    return status;
}

