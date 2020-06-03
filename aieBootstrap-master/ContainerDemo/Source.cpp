#include <iostream>
#include <string>
#include <algorithm>
#include "DoubleLinkedList.h"
#include "Node.h"
#include "DynamicArray.h"
#include "HashTable.h"

using namespace std;

void DLLDemo()
{
	DoubleLinkedList<int>* DLL = new DoubleLinkedList<int>(); 
	while (true)
	{
		system("CLS");

		if (DLL->IsEmpty())
			cout << "There is nothing to print in the List" << endl;
		else
		{
			cout << "Lets see what you got" << endl;
			DLL->Print();
			cout << "In total, that is " << DLL->Size() << " elements in the List" << endl << endl;
		}
		cout << "A) PushBack The list For value" << endl;
		cout << "B) PushFront The list For value" << endl;
		cout << "C) Insert value At position" << endl;
		cout << "D) Popback The list" << endl;
		cout << "E) PopFront The list" << endl;
		cout << "F) Erase The Node At position" << endl;
		cout << "G) Remove All Nodes Of value" << endl;
		cout << "H) Clear The list" << endl;
		cout << "I) Sort The list" << endl;
		cout << "J) Return The First Nodes Value Of The list" << endl;
		cout << "K) Return The Last Nodes Value Of The list" << endl;
		cout << "L) Return Begin Position The list" << endl;
		cout << "M) Return Last Nodes Value Of The list" << endl;
		cout << "N) Return the node" << endl;
		cout << "P) Quit" << endl;
		
		string uInput = "";
		cin >> uInput;
		transform(uInput.begin(), uInput.end(), uInput.begin(), toupper);
		if (uInput == "A")
		{
			while (true)
			{
				system("CLS");
				cout << "What Number are we adding to the List?" << endl;
				int uAnswer;
				while (!(cin >> uAnswer))
				{
					system("CLS");
					cout << "What Number are we adding to the List?" << endl;
					cin.clear();
					cin.ignore(1164, '\n');
				}
				DLL->PushBack(uAnswer);
				break;
			}

		}
		else if (uInput == "B")
		{
			while (true)
			{
				system("CLS");
				cout << "What Number are we adding to the List?" << endl;
				int uAnswer;
				while (!(cin >> uAnswer))
				{
					system("CLS");
					cout << "What Number are we adding to the List?" << endl;
					cin.clear();
					cin.ignore(1164, '\n');
				}
				DLL->PushFront(uAnswer);
				break;
			}
		}
		else if (uInput == "C")
		{
			while (true)
			{
				system("CLS");
				cout << "What Number are we adding to the List?" << endl;
				int uVal;
				while (!(cin >> uVal))
				{
					system("CLS");
					cout << "What Number are we adding to the List?" << endl;
					cin.clear();
					cin.ignore(1164, '\n');
				} 
				system("CLS");
				cout << "Where we putting it?" << endl;
				int uPos;
				while (!(cin >> uPos))
				{
					system("CLS");
					cout << "Where we putting it? Integer only." << endl;
					cin.clear();
					cin.ignore(1164, '\n');
				}
				DLL->Insert(uPos, uVal);
				break;
			}
		}
		else if (uInput == "D") {
			DLL->PopBack();
		}
		else if (uInput == "E") {
			DLL->PopFront();
		}
		else if (uInput == "F")
		{
			while (true)
			{
				system("CLS");
				cout << "Where are we E-Racing? Get it? Cause 'Where'... Ugh" << endl;
				int uAnswer;
				while (!(cin >> uAnswer))
				{
					system("CLS");
					cout << "Where are we Erasing?" << endl;
					cin.clear();
					cin.ignore(1164, '\n');
				}
				DLL->Erase(uAnswer);
				break;
			}
		}
		else if (uInput == "G") {
			while (true)
			{
				system("CLS");
				cout << "What values are unfit for this list?" << endl;
				int uAnswer;
				while (!(cin >> uAnswer))
				{
					system("CLS");
					cout << "Where are we Removing?" << endl;
					cin.clear();
					cin.ignore(1164, '\n');
				}
				DLL->Remove(uAnswer);
				break;
			}
		}
		else if (uInput == "H") {
			DLL->Clear();
		}
		else if (uInput == "I") {
			DLL->Sort();
		}
		else if (uInput == "J")
		{ 
			cout  << DLL->First() << endl;
			system("pause");
		}
		else if (uInput == "K")
		{ 
			cout << DLL->Last() << endl;
			system("pause");
		}
		else if (uInput == "L") { 
			cout << DLL->Begin(); 
			system("pause");
		}
		else if (uInput == "M") { 
			cout << DLL->End();
			system("pause");
		}
		else if (uInput == "N")
		{
		system("CLS");
		cout << "What values are we looking for?" << endl;
		int uAnswer;
		while (!(cin >> uAnswer))
		{
			system("CLS");
			cout << "Where values are we looking for?" << endl;
			cin.clear();
			cin.ignore(1164, '\n');
		}
		Node<int> n = DLL->Search(uAnswer);
		cout << &n << ": " << n.data << endl;
			system("pause");
		}
		else if (uInput == "P")
		{
		return;
		}
	}
}

void DYNDemo()
{ 
	DynamicArray<int>* DA = new DynamicArray<int>();
	while (true)
	{
		system("CLS");

		if (DA && DA->Capacity() == 0)
			cout << "There is nothing to print in the Array" << endl;
		else
		{
			cout << "Lets see what you got" << endl;
			DA->Print();
			cout << "In total, that is " << DA->Size() << " elements in the Array" << endl << endl;
		}
		cout << "A) PushBack The list For value" << endl;
		cout << "B) PushFront The list For value" << endl;
		cout << "C) Insert value At position" << endl;
		cout << "D) Popback The list" << endl;
		cout << "E) PopFront The list" << endl;
		cout << "F) Erase The Node At position" << endl;
		cout << "G) Remove All Nodes Of value" << endl;
		cout << "H) Clear The list" << endl;
		cout << "I) Sort The list" << endl;
		cout << "J) Return The First Nodes Value Of The list" << endl;
		cout << "K) Return The Last Nodes Value Of The list" << endl;
		cout << "L) Return Begin Position The list" << endl;
		cout << "M) Return Last Nodes Value Of The list" << endl;
		cout << "N) Insert Multiple Values" << endl;
		cout << "O) Unorderedly Remove A Value In The List" << endl;
		cout << "P) DownSize The Array" << endl;
		cout << "Q) UpSize The Array" << endl;
		cout << "R) Find The Place That A Value Exists In The Array" << endl;
		cout << "S) Go Back To Menu Select" << endl;
		string uInput = "";
		cin >> uInput;
		transform(uInput.begin(), uInput.end(), uInput.begin(), toupper);
		if (uInput == "A")
		{
				system("CLS");
				cout << "What Number are we adding to the List?" << endl;
				int uAnswer;
				while (!(cin >> uAnswer))
				{
					system("CLS");
					cout << "What Number are we adding to the List?" << endl;
					cin.clear();
					cin.ignore(1164, '\n');
				}
				DA->PushBack(uAnswer);

		}
		else if (uInput == "B")
		{
			while (true)
			{
				system("CLS");
				cout << "What Number are we adding to the List?" << endl;
				int uAnswer;
				while (!(cin >> uAnswer))
				{
					system("CLS");
					cout << "What Number are we adding to the List?" << endl;
					cin.clear();
					cin.ignore(1164, '\n');
				}
				DA->PushFront(uAnswer);
				break;
			}
		}
		else if (uInput == "C")
		{
			while (true)
			{
				system("CLS");
				cout << "What Number are we adding to the List?" << endl;
				int uVal;
				while (!(cin >> uVal))
				{
					system("CLS");
					cout << "What Number are we adding to the List?" << endl;
					cin.clear();
					cin.ignore(1164, '\n');
				}
				system("CLS");
				cout << "Where we putting it?" << endl;
				int uPos;
				while (!(cin >> uPos))
				{
					system("CLS");
					cout << "Where we putting it? Integer only." << endl;
					cin.clear();
					cin.ignore(1164, '\n');
				}
				DA->Insert(uPos, uVal);
				break;
			}
		}
		else if (uInput == "D") {
			DA->PopBack();
		}
		else if (uInput == "E") {
			DA->PopFront();
		}
		else if (uInput == "F")
		{
			while (true)
			{
				system("CLS");
				cout << "Where are we E-Racing? Get it? Cause 'Where'... Ugh" << endl;
				int uAnswer;
				while (!(cin >> uAnswer))
				{
					system("CLS");
					cout << "Where are we Erasing?" << endl;
					cin.clear();
					cin.ignore(1164, '\n');
				}
				DA->Erase(uAnswer);
				break;
			}
		}
		else if (uInput == "G") {
			while (true)
			{
				system("CLS");
				cout << "What values are unfit for this list?" << endl;
				int uAnswer;
				while (!(cin >> uAnswer))
				{
					system("CLS");
					cout << "Where are we Removing?" << endl;
					cin.clear();
					cin.ignore(1164, '\n');
				}
				DA->Remove(uAnswer);
				break;
			}
		}
		else if (uInput == "H") {
			DA->Clear();
		}
		else if (uInput == "I") {
			DA->Sort();
		}
		else if (uInput == "J")
		{
			cout << DA->First();
			system("pause");
		}
		else if (uInput == "K")
		{
			cout << DA->Last();
			system("pause");
		}
		else if (uInput == "L") {
			cout << DA->Begin();
			system("pause");
		}
		else if (uInput == "M") {
			cout << DA->End();
			system("pause");
		}
		else if (uInput == "N") {
			system("CLS"); 
			cout << "How Many Values Would You Like To Add To The Array?" << endl;
			int uAnswer;
			while (!(cin >> uAnswer))
			{
				system("CLS");
				cout << "How Many Values Would You Like To Add To The Array?" << endl;
				cin.clear();
				cin.ignore(1164, '\n');
			} 
			int l_traversePoint = DA->Size() / 2;

			for (int i = 0; i < uAnswer; i++)
			{
				system("CLS");
				cout << i << ") "; 
				cout << "What is the value you would like to add?" << endl;
				int uData;
				while (!(cin >> uData))
				{
					system("CLS");
					cout << i << ") ";
					cout << "What is the value you would like to add?" << endl;
					cin.clear();
					cin.ignore(1164, '\n');
				}
				DA->Insert(l_traversePoint, uData);

			}

		}
		else if (uInput == "O") 
		{
			system("CLS");
			cout << "What value would you like to remove?" << endl;
			int uAnswer;
			while (!(cin >> uAnswer))
			{
				system("CLS");
				cout << "What value would you like to remove?" << endl; 
				cin.clear();
				cin.ignore(1164, '\n');
			}
			DA->UnorderedRemoval(uAnswer);
		} 
		else if (uInput == "P") {
			cout << "" << endl;
			system("CLS");
			cout << "How Many Spaces Smaller?" << endl;
			int uAnswer;
			while (!(cin >> uAnswer))
			{
				system("CLS");
				cout << "How Many Spaces Smaller?" << endl;
				cin.clear();
				cin.ignore(1164, '\n');
			}
			DA->Downsize(uAnswer);
		} 
		else if (uInput == "Q") {
			cout << "" << endl;
			system("CLS");
			cout << "How Many Spaces Bigger?" << endl;
			int uAnswer;
			while (!(cin >> uAnswer))
			{
				system("CLS");
				cout << "How Many Spaces Bigger?" << endl;
				cin.clear();
				cin.ignore(1164, '\n');
			}
			DA->Upsize(uAnswer);

		}
		else if (uInput == "R") {
			cout << "" << endl;
			system("CLS");
			cout << "What Value Are We Looking For?" << endl;
			int uAnswer;
			while (!(cin >> uAnswer))
			{
				system("CLS");
				cout << "What Value Are We Looking For?" << endl;
				cin.clear();
				cin.ignore(1164, '\n');
			}
			cout << DA->Search(uAnswer); 
			system("pause");
		}
		else if (uInput == "S")
		{
			cin.clear();
			break;
		}
	}
}

void HTBDemo()
{
	Hash::HashTable* HT = new Hash::HashTable();
	while (true)
	{
		system("CLS");
		string uInput = "";

		if (HT && HT->IsEmpty())
			cout << "There is nothing to print in the Table" << endl;
		else
		{
			cout << "Lets see what you got" << endl;
			HT->Print();
			cout << "In total, that is " << HT->NumOfEl() << " elements in the Array" << endl << endl;
		}
		cout << "A) Add a Value with a Key" << endl;
		cout << "B) Remove a Value via Key" << endl;
		cout << "C) Mass Deletion" << endl;
		cout << "D) Gain weight" << endl;
		cout << "E) To say Bye" << endl;
		cin >> uInput;
		transform(uInput.begin(), uInput.end(), uInput.begin(), toupper);
		if (uInput == "A")
		{
			system("CLS");
			while (true)
			{
				system("CLS"); 
				cout << "What Number are we adding to the List?" << endl;
				int uVal;
				while (!(cin >> uVal))
				{
					system("CLS");
					cout << "What Number are we adding to the Table?" << endl;
					cin.clear();
					cin.ignore(1164, '\n');
				}
				system("CLS"); 
				string uKey;
				cout << "Create the key for the value." << endl;
				while (!(cin >> uKey))
				{
					system("CLS"); 
					cin.clear();
					cin.ignore(1164, '\n');
				}
				HT->AddVal(uKey, uVal);
				break;
			} 
		}
		if (uInput == "B")
		{
			system("CLS");
			string uKey;
			cout << "What Key would you like to delete" << endl;
			while (!(cin >> uKey))
			{
				system("CLS");
				cin.clear();
				cin.ignore(1164, '\n');
			}
			HT->RemoveValAtKey(uKey);
			cout << endl;
			system("pause");
		}
		if (uInput == "C")
		{
			system("CLS");
			HT->ClearTable();
			system("pause");
		}
		if (uInput == "D")
		{
			system("CLS");
			int uSize;
			cout << "How much weight did we gain. Integers Only." << endl;
			while (!(cin >> uSize))
			{
				system("CLS");
				cout << "How much weight did we gain. Integers Only." << endl;
				cin.clear();
				cin.ignore(1164, '\n'); 
			}
			HT->Upsize(uSize);
		}
		if (uInput == "E")
		{
			break;
		}
	}
}

int main(int* argv, int** argc)
{

	cout << "Failed!" << endl;
	string uAnswer = "";
	int i = 0;
	while (true)
	{
			system("CLS");
		if (i != 0) 
			cout << "Come on. You only have four options to answer this" << endl;  
		cout << "What Container Would you like to test?" << endl;
		cout << "A) DoubleLinkedList or B) DynamicArray or C) HashTable or D) The most unpopular option" << endl;
		cin >> uAnswer;
		transform(uAnswer.begin(), uAnswer.end(), uAnswer.begin(), toupper); 
			i++;
		if (uAnswer == "A" || uAnswer == "DOUBLELINKEDLIST" || uAnswer == "DLL")
		{
			DLLDemo();
			cin.clear();
			i = 0;
		}
		else if (uAnswer == "B" || uAnswer == "DYNAMICARRAY" || uAnswer == "DA")
		{
			DYNDemo();
			i = 0;
		}
		else if (uAnswer == "C" || uAnswer == "HASHTABLE" || uAnswer == "HT")
		{
			HTBDemo();
			i = 0;
		}
		else if (uAnswer == "D" || uAnswer == "QUIT" || uAnswer == "Q")
			break;

		if (i == 3)
		{
			cout << "Thats it, I'm sick of you!" << endl;
			system("pause");
			return 0;
		}
	}
	return 0;
}