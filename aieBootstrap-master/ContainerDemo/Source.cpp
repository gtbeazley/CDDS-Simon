#include <iostream>
#include <string>
#include <algorithm>
#include "DoubleLinkedList.h"

using namespace std;

void DLLDemo()
{
	cout << "hi" << endl;
}

void DYNDemo()
{

}

int main(int* argv, int** argc)
{

	cout << "Failed!" << endl;
	system("CLS");
	cout << "What Container Would you like to test?" << endl;
	cout << "A) DoubleLinkedList or B) DynamicArray" << endl; 
	string uAnswer = "";
	int i = 0;
	bool answeredProperly = false;
	while (!answeredProperly)
	{
		if (i != 0)
		{
			system("CLS");
			cout << "Come on. You only have two options to answer this" << endl;
			cout << "What Container Would you like to test?" << endl;
			cout << "A) DoubleLinkedList or B) DynamicArray" << endl;
		}
		cin >> uAnswer;
		transform(uAnswer.begin(), uAnswer.end(), uAnswer.begin(), toupper);
		if (uAnswer == "A" || uAnswer == "DOUBLELINKEDLIST")
		{
			DLLDemo();
			answeredProperly = true;
		}
		else if (uAnswer == "B" || uAnswer == "DYNAMICARRAY")
		{
			DYNDemo();
			answeredProperly = true;
		}
		if (i == 3)
		{
			cout << "Thats it, I'm sick of you!" << endl;
			system("pause");
			return 0;
		}
		i++;
	}

	system("pause");
	return 0;
}