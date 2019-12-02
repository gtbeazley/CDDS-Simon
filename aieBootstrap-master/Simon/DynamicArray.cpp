#include "DynamicArray.h"
#include <iostream>

using namespace std;
DynamicArray::DynamicArray(const int a_cap)
{
}

DynamicArray::~DynamicArray()
{
}

void DynamicArray::Print()
{
	for (int i = 0; i < curSize; i++)
		cout << m_elements[i] << endl;
}

void DynamicArray::Insert(int a_val, int a_pos)
{
	if (!HasRoomLeft())
	{

	}
}

bool DynamicArray::IsEmpty()
{
	return !curSize;
}

bool DynamicArray::HasRoomLeft()
{
	return (MaxCap - curSize) > 0;
}
