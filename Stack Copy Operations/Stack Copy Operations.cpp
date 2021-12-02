// Stack Copy Operations.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;


class DynIntStack
{
struct StackNode
{
int value;
StackNode * next;
 // Constructor
 StackNode(int value1, StackNode * next1 = nullptr)
 {
    value = value1;
     next = next1;
  }
};


public:

    StackNode* top, *top1, *topcons;
    DynIntStack()
    {
        top = nullptr;
        top1 = nullptr;
    }
    //copy constructor for the copy stack
    DynIntStack(const DynIntStack& ptr)
    {
        topcons = ptr.top;
    }


    ~DynIntStack();
    void push(int);
    void push1(int);
    int copy();
    void pop(int&);
    void pop1(int&);
    void traverse();
    void traverse1();
    bool isEmpty() const;
 
    // Stack Exception
    class Underflow {};
      };

//push to original stack
void DynIntStack::push(int num)
{
    top = new StackNode(num, top);
}

//push to copy stack
void DynIntStack::push1(int num)
{
    top1 = new StackNode(num, top1);
}

//copy copies the element added to original stack
int DynIntStack::copy(void)
{
    int temp;
    temp = top->value;
    top = top->next;
    return temp;
}

//traverses the stack.
void DynIntStack::traverse(void)
{
    for (int i = 0; i < 5; i++)
    {
        cout << top1->value << endl;
        top1 = top1->next;
    }
}

void DynIntStack::traverse1(void)
{
    for (int i = 0; i < 5; i++)
    {
        cout << topcons->value << endl;
        topcons = topcons->next;
    }
}






void DynIntStack::pop(int& num)
{
StackNode* temp;
    
  if (isEmpty()) 
  { 
      throw DynIntStack::Underflow();
  }
  else
  {
     // Pop value off top of stack      
     num = top-> value;
     temp = top;
     top = top -> next;
     delete temp;
}
}


void DynIntStack::pop1(int& num)
{
    StackNode* temp;

    if (isEmpty())
    {
        throw DynIntStack::Underflow();
    }
    else
    {
        // Pop value off top of stack      
        num = top1->value;
        temp = top1;
        top1 = top1->next;
        delete temp;
    }
}

bool DynIntStack::isEmpty() const
{
    return top == nullptr;
}


DynIntStack::~DynIntStack()
{
    StackNode* garbage = top;
    while (garbage != nullptr)
    {
        top = top->next;
        garbage->next = nullptr;
        delete garbage;
        garbage = top;
    }
}



int main()
{
    DynIntStack stack, stackCopy;

    //push values into stack
    for (int i = 0; i < 10; i += 2)
    {
        cout << "Push: " << i << endl;
        stack.push(i);
    }

    //copy using contructor
    DynIntStack ptr = stack;
    
    //Copy using assignment
    int num;
    for (int k = 0; k < 5; k++)
    {
        num = stack.copy();
        stackCopy.push1(num);
    }


    cout << "Copied values via assignment" << endl;
    stackCopy.traverse();

    cout << "Copied values via constructor" << endl;
    ptr.traverse1();
    
}

