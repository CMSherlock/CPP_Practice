#include "pch.h"
#include <iostream>
#include <string>
#include "LinkedList.cpp"

int main()
{
	LinkedList<int> list;

	list.insert(1);
	list.insert(2);
	list.insert(3);
	list.insert(4);
	list.insert(5);
	list.insert(6);
	list.insert(7);
	list.insert(8);
	
	list.PrintAllData();
	cout << endl << endl;

	cout << list.search(2) << endl;
	cout << list.search(10) << endl;
	cout << endl << endl;

	list.remove(2);
	list.remove(4);
	list.PrintAllData();
	
	cout << endl <<"/***************************************************************************/"<< endl << endl;

	LinkedList<string> strList;

	strList.insert("a");
	strList.insert("b");
	strList.insert("c");
	strList.insert("d");
	strList.insert("e");
	strList.insert("f");
	strList.insert("g");
	strList.insert("h");

	strList.PrintAllData();
	cout << endl << endl;

	cout << strList.search("a") << endl;
	cout << strList.search("z") << endl;
	cout << endl << endl;

	strList.remove("a");
	strList.remove("h");
	strList.PrintAllData();
}

