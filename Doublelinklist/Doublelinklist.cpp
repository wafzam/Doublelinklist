// Doublelinklist.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include "Node.h"
#include "Dlist.h"
using namespace std; int main()
{
	//create a few nodes------------------------------
	DList* lst1 = new DList();
	DList* lst2 = new DList();
	lst1->addFromDisk("c:/temp/Myfile1.txt");
	lst1->showList();
	lst2->addFromDisk("c:/temp/Myfile2.txt");
	lst2->showList();
	
	lst1->addWithoutDuplicates(lst2);
	lst1->showList();
}
//Node* n1 = new Node("AAA");
//Node* n2 = new Node("BBB");
//Node* n3 = new Node("CCC");
//DList* lst1 = new DList();
//lst1->addAfter(lst1->last, n1);
//lst1->addAfter(lst1->last, n2);
//lst1->addAfter(lst1->last, n3);
//cout << "\n List (Forward traversal)";
//lst1->showList();
//cout << "\n List (Backward traversal)";
//lst1->showListBackward();
//Node* n4 = new Node("AAB");
//lst1->addAfter(lst1->first, n4);
//cout << "\n List (Forward traversal)";
//lst1->showList();
//cout << "\n List (Forward traversal) - XXX is first node";
//lst1->addFirst(new Node("XXX"));
//lst1->showList();
//string keyData = "BBB";
//Node* p = lst1->findNode(keyData);
//cout << "\n Find Node: " << keyData << " " << p;
//if (p != nullptr) {
//	cout << "\n FOUND " << p->showNode() << endl;
//}
//cout << "\n List (Forward traversal) - add YYY after BBB";
//lst1->addAfter(p, new Node("YYY"));
//lst1->showList();
//cout << "\n List (Forward traversal) - find and delete BBB ";
//p = lst1->findNode("BBB");
//lst1->deleteNode(p);
//lst1->showList();
//cout << "\n All done...\n";