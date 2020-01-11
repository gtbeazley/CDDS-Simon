#pragma once
#include "vector"
#include "DoubleLinkedList.h" 
#include "DynamicArray.h"
#include "HashFunction.h"
#include <iostream>
#include <istream>
#include <fstream>
#include <string>
#include "Node.h"
using namespace std;

namespace Hash {
	class HashTable
	{
	public:
		//Default Constructor
		HashTable();
		//Default Destructor
		~HashTable();

		//Adds the value a_data at position calaculated by a_key
		void AddVal(string a_key, int a_data);
		//Removes the first value that is at the same position as a_key 
		void RemoveValAtKey(string a_key);
		//Clears the entire table
		void ClearTable();
		//Grows the size of the table
		void Upsize(int a_cap);
		//Decreases the size of the table
		void DownSize(int a_cap);
		//Prints the list of data
		void Print();

		//Returns true if the table is empty
		bool IsEmpty();

		/* Returns the amount of elements in the table */
		int NumOfEl();

		//Subscript operator controlled by a_key
		int operator [] (const string a_key);

		//Gets all keys that exist
		DynamicArray<DoubleLinkedList<string>>* GetAllKeys();

		//The initial size of the arrays
		static const int m_size = 10;

		//The consistantly updated number of elements
		int m_numOfEl = 0;

		//The array of data
		DynamicArray<DoubleLinkedList<int>> list = DynamicArray<DoubleLinkedList<int>>(m_size);
		//The array of keys
		DynamicArray<DoubleLinkedList<string>> keys = DynamicArray<DoubleLinkedList<string>>(m_size);
	};
}