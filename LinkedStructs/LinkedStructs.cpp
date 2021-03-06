#include "stdafx.h"
#include <iostream>

using namespace std;

class LinkedStack {
	
	//The node of the stack
	struct Node {
		int data;
		Node *next;
	};

	// public members
public:

	// constructor
	LinkedStack() {
		head = NULL;
	}

	// destructor
	~LinkedStack() {
		Node *next = head;

		while (next) {              
			Node *deleteMe = next;
			next = next->next;     
			delete deleteMe; //please
		}
	}

	// This prepends a new value at the beginning of the stack
	bool push(int value) {
		Node *newNode = new Node();   
		newNode->data = value;            
		newNode->next = head;         
								
		head = newNode;

		return true;
	}

	// returns the first element in the list and deletes the Node.
	int pop() {
		if (head == NULL) // There might be an exeption I gues
			return 0;

		Node *newNode = head;
		int ret = newNode->data;

		head = head->next;
		delete newNode;
		return ret;
	}

	// private members
private:
	Node * head;
};

int main() {
	LinkedStack *stack = new LinkedStack();

	stack->push(1);
	stack->push(3);
	stack->push(5);

	cout << stack->pop() << endl;
	cout << stack->pop() << endl;
	cout << stack->pop() << endl;
	cout << stack->pop() << endl;
	cout << stack->pop() << endl << endl;

	stack->push(2);
	stack->push(4);
	stack->push(6);

	cout << stack->pop() << endl;
	cout << stack->pop() << endl;
	cout << stack->pop() << endl;
	cout << stack->pop() << endl;
	cout << stack->pop() << endl;

	delete stack;

	system("pause");
	return 0;
}

