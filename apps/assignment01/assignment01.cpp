//
// File:   assignment1.cpp
// Author: Stephanie Rupert
// Purpose:
// Illustrate some of the bad things that can happen with
// pointers
// Used this site for help with "new" since I don't know
// what I'm doing:
// http://www.cs.ecu.edu/karl/3300/spr16/Notes/C/Array/heap.html 
//
#include <iostream>
using namespace std;

//Part 1
int ary()
	{
	//allocate large array in the heap storing a pointer
	int *arr = new int[100];
	for (int i = 0; i < 100; i++)
		{
		arr[i] = 0;
		}

	//second pointer to the first pointer's location in memory
	int **arr2 = &arr;

	//array delete of first pointer
	//second pointer is a dangling pointer
	delete [] arr;
	
	//print the first ten integers pointed to by the second pointer
	for (int i = 0; i < 10; i++)
		cout << **arr2;
		
	cout << "\n";

	return 0;
	}

//Part 2
int ary2()
	{
	//allocate large array in the heap storing a pointer
	int *arr = new int[100];
	for (int i = 0; i < 100; i++)
		{
		arr[i] = 0;
		//cout << *arr;
		}

	//second pointer to the first pointer's location in memory
	int **arr2 = &arr;

	//regular delete of first pointer which gives a warning
	delete arr;
	
	//print the first ten integers pointed to by the second pointer
	for (int i = 0; i < 10; i++)
		cout << **arr2;

	cout << "\n";

	return 0;
	}

//Part 3
string str()
	{
	//pointer to a string object and use
	//'new' to create a new string on the stack
	string *str = new string[100];

	*str = "This is the string. Joy.";

	return *str;
	}

//calling function
void call(string str())
	{
	//string object set to be whatever is returned
	//from the helper function
	string strOb = str();

	cout << strOb;
	}	

int main()
	{
	ary();
	ary2();
	call(*str);
	
	return 0;
	}
