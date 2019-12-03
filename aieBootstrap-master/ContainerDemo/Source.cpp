#include <iostream>
#include <string>
#include <algorithm>
#include "DoubleLinkedList.h"
#include "DynamicArray.h"

using namespace std;

void DLLDemo()
{
	DoubleLinkedList* DLL = new DoubleLinkedList();
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
		cout << "N) Go Back To Menu Select" << endl;
		
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
			cout << DLL->First();
			system("pause");
		}
		else if (uInput == "K")
		{
		cout << DLL->Last();
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
			cin.clear();
			break;
		}
	}
}

void DYNDemo()
{ 
	DynamicArray* DA = new DynamicArray();
	while (true)
	{
		system("CLS");

		if (DA && DA->IsEmpty())
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
		cout << "N) Go Back To Menu Select" << endl;
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
		else if (uInput == "N")
		{
			cin.clear();
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
			cout << "Come on. You only have two options to answer this" << endl;  
		cout << "What Container Would you like to test?" << endl;
		cout << "A) DoubleLinkedList or B) DynamicArray or C) the most unpopular option" << endl;
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
		else if (uAnswer == "C" || uAnswer == "QUIT" || uAnswer == "Q")
			break;

		if (i == 3)
		{
			cout << "Thats it, I'm sick of you!" << endl;
			system("pause");
			return 0;
		}
	}

	system("pause");
	return 0;
}