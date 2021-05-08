#pragma once
#include "Node.h";
#include <iostream>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <stack>
#include <set>

using namespace std;
//---------------------------------------------------------------
class DList
{
public:
	Node* first;
	Node* last;
	int counter;

	DList() {
		first = nullptr;
		last = nullptr;
		counter = 0;
	};

	~DList()
	{
		this->clear();
		cout << "DList at " << this << " has been destroyed\n";
	}

	void addFromDisk(string fileName) {

		ifstream infile(fileName);
		string newData;

		while (getline(infile, newData)) {
			Node* n1 = new Node(newData);
			addAfter(last, n1);
		}

		infile.close();
	}
	
	int addWithoutDuplicates(DList* lst2) {
		
		Node* x = lst2->first;
		//int num = 1;
		bool l=false;
		
		while (x != NULL) {
			bool l = false;
			Node* k = this->first;
			while(k !=NULL)
			{
				if (x->getData() == k->getData())
				{
					
					l = true;
					break;
				}
				k = k->getNext();
			}
			if (l == false)
			{
				this->addFirst(new Node(x->getData()));
			}
			x = x->getNext();
		}

		return 0;
	}

	void reverse()
	{
		stack<string> stk;
		Node* ptr = first;
		while (ptr != nullptr)
		{
			stk.push(ptr->getData());
			ptr = ptr->getNext();
		}

		ptr = first;
		while (ptr != nullptr)
		{
			ptr->setData(stk.top());
			stk.pop();
			ptr = ptr->getNext();
		}
	}

	void keepCommonElements(DList* lst2)
	{
		Node* n1 = this->first;
		Node* tempNext;

		while (n1 != nullptr)
		{
			string keyData = n1->getData();
			if (lst2->findNode(keyData) != nullptr)
			{
				tempNext = n1->getNext();
				this->deleteNode(n1);
				n1 = tempNext;
			}
			else
			{
				n1 = n1->getNext();
			}
		}
	}

	// -------------------------------------------------
	void deleteNode(Node* n) {
		if (n == nullptr) return;
		if (counter == 0) return;

		//CASE1. Only one element in the list?
		if (counter == 1) {
			if (first != n) return;
			delete n;
			first = nullptr;
			last = nullptr;
			counter = 0;
			return;
		}

		//Reduce counter
		counter--;

		//CASE2. Deleting the head of the list?
		if (n == first) {
			first = first->getNext();
			first->setPrevious(nullptr);
			delete n;
			return;
		}
		// Get references to sourrounding Nodes
		Node* leftNode = n->getPrevious();
		Node* rightNode = n->getNext();
		//CASE3. Deleting last of the list?
		if (n == last) {
			leftNode->setNext(nullptr);
			last = leftNode;
			delete n;
			return;
		}
		//CASE4. interconnect surrounding nodes
		leftNode->setNext(rightNode);
		rightNode->setPrevious(leftNode);
		delete n;
		return;
	}
	// --------------------------------------------
	Node* findNode(string keyData) {
		Node* p = first;
		while (p != nullptr) {
			if (p->getData() == keyData)
				return p;
			else
			{
				p = p->getNext();
			}
		}
		return p;
	}
	void addFirst(Node* n1) {
		if (first == nullptr)
		{
			first = n1;
			last = n1;
			counter = 1;
			return;
		}

		n1->setNext(first);
		first->setPrevious(n1);
		first = n1;
		counter++;
	}

	/////////////////////////////////////////////////////////////////////

	void addAfter(Node* n1, Node* n2) {

		if (first == nullptr && counter > 0)
		{
			n2->setNext(first);
			first = n2;
			counter++;
			return;

		}

		if (counter == 0)
		{
			first = n2;
			last = n2;
			counter = 1;
			return;
		}

		counter++;

		Node* n1Successor = n1->getNext();
		if (n1Successor != nullptr)
			n1Successor->setPrevious(n2);
		n1->setNext(n2);

		n2->setNext(n1Successor);
		n2->setPrevious(n1);

		if (n2->getNext() == nullptr) {
			last = n2;
		}
	}

	void showList(string msg = "") {
		int n = 1;
		cout << endl
			<< msg
			<< " Loc: " << this
			<< " First: " << first
			<< " Last: " << last
			<< " Counter: " << counter << endl;
		Node* p = this->first;
		while (p != nullptr)
		{
			cout << setw(3) << n++ << " " << p->showNode() << endl;
			p = p->getNext();
		}
	}


	//////////////////////////////////////////////////////////////////

	void showListBackward() {
		cout << endl;
		Node* p = this->last;
		while (p != nullptr) {
			cout << p->showNode() << endl;
			p = p->getPrevious();
		}
	}

	void clear()
	{
		Node* ptr = this->first;
		while (ptr != nullptr)
		{
			Node* nextNode = ptr->getNext();
			this->deleteNode(ptr);
			ptr = nextNode;
		}
	}

};
