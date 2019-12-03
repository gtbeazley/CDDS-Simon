#include "DynamicArray.h" 
#include <iostream>

using namespace std;

DynamicArray::DynamicArray()
{
} 

DynamicArray::~DynamicArray()
{
	delete[] m_data;
}

int DynamicArray::operator[](int a_iter)
{
	return m_data[a_iter];
}

void DynamicArray::operator=(DynamicArray a_dynArr)
{
	m_data = a_dynArr.GetData();
}

void DynamicArray::PushFront(int a_data)
{
	if (!HasRoom())
		Upsize();

	if(!IsEmpty())
	{
		int* newData = new int[m_cap];
		for (int i = 0; i < m_numOfEl; i++)
			newData[i + 1] = m_data[i];
		m_data = newData;
	}
	m_data[0] = a_data; 
	m_numOfEl++;
}

void DynamicArray::PushBack(int a_data)
{
	if (!HasRoom())
		Upsize();

	m_numOfEl++;
	m_data[m_numOfEl - 1] = a_data;
}

void DynamicArray::Insert(int a_iter, int a_data)
{
	if (!HasRoom())
		Upsize(); 
	if (IsEmpty())
		m_data[0] = a_data;
	else
	{
		int * newData = nullptr;
		for (int i = 0; i < m_numOfEl; i++)
		{
			if (i == a_iter)
				newData[i+1] = m_data[i];
			else
				newData[i] = m_data[i];
		}
		m_data = newData;
		m_data[a_iter] = a_data;
	}
	m_numOfEl++;
}

void DynamicArray::PopBack()
{
	if (IsEmpty())
		cout << "Nothing to remove" << endl;
	else 
		m_numOfEl--; 
}

void DynamicArray::PopFront()
{
	if (IsEmpty())
		cout << "Nothing to remove" << endl;
	else
	{
		for (int i = 0; i < m_numOfEl; i++)
			m_data[i] = m_data[i + 1];
		m_numOfEl--;
	}
}

void DynamicArray::Erase(int a_iter)
{
	for (int i = 0; i < m_numOfEl; i++)
		if(i != a_iter)
			m_data[i] = m_data[i + 1];
	m_numOfEl--;
}

void DynamicArray::Remove(int a_data)
{
	DynamicArray posList = DynamicArray();
	for (int i = 0; i < m_numOfEl; i++)
		if (m_data[i] == a_data)
			posList.PushBack(a_data);
	for (int i = 0; i < posList.Size(); i++)
		Erase(posList[i]);
}

void DynamicArray::Clear()
{
	m_numOfEl = 0;
}

void DynamicArray::Sort()
{

}

void DynamicArray::Upsize(int a_cap)
{
	int newCap;
	if (a_cap == 0)
		newCap = m_cap + 10;
	else
		newCap = m_cap + a_cap;

	int* newData = new int[newCap];
	int original = m_cap;
	m_cap = newCap;

	for (int i = 0; i < original; i++)
	{
		std::cout << m_data[i] << std::endl;
		newData[i] = m_data[i];
	}
	m_data = newData;
}

void DynamicArray::Downsize()
{
	if (HasRoom())
	{ 
		m_cap = m_numOfEl;
		m_data = new int[m_cap];
	}
}

void DynamicArray::Print()
{
	for (int i = 0; i < m_numOfEl; i++)
		cout << i << ") " << m_data[i] << endl;
}

int DynamicArray::Size()
{
	return m_numOfEl;
}

int DynamicArray::Capacity()
{
	return m_cap;
}

int DynamicArray::First()
{
	return m_data[0];
}

int DynamicArray::Last()
{
	return m_data[m_numOfEl-1];
}

int DynamicArray::Begin()
{
	return 0;
}

int DynamicArray::End()
{
	return m_numOfEl - 1;
}

int * DynamicArray::GetData()
{
	return m_data;
}

bool DynamicArray::IsEmpty()
{
	return !(m_numOfEl);
}

bool DynamicArray::HasRoom()
{
	return ((m_cap - m_numOfEl) > 0);
}
