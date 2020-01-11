#pragma once 
#include <iostream>
#include <istream>
#include <fstream>
#include <math.h>
#include "DoubleLinkedList.h"

using namespace std;

template<typename T>
class DynamicArray
{
public:
	//Default Constructor
	DynamicArray();
	//Initialize array with size of a_size
	DynamicArray(int a_size);
	//Default Destructor
	~DynamicArray();

	//Subscript operator
	T& operator [](int a_iter);
	
	//Casting returns the data array
	operator T* () { return m_data; }

	//Copy operator
	void operator = (DynamicArray a_dynArr);

	//Adds a_data to the start of the array and resizes if necessary
	void PushFront(T a_data);
	//Adds a_data to the end of the array and resizes if necessary
	void PushBack(T a_data);
	//Adds a_data at location a_iter and resizes if neccessary
	void Insert(int a_iter, T a_data);
	//No longer takes in account of the value at the end of the array
	void PopBack();
	//Mo longer takes in account of the valie at the start of the array
	void PopFront();
	//Erases the data from the position a_iter and reorganises the array
	void Erase(int a_iter);
	//Removes the first data with the value a_data and reorganises the array
	void Remove(T a_data);
	//Clears out the entire array
	void Clear();
	//Sorts the entire array
	void Sort();
	//Increases the size of the array by a_cap
	//unless a_cap is zero in which case will double the size of the array
	void Upsize(int a_cap = 0);
	//Decreases the sze of the array to thje number of elements that exists
	void Downsize();
	//Prints out the array to the console
	void Print();

	//Returns the number of elements
	int Size();
	//Returns the maximum number of elements allowed in the array
	int Capacity();

	//Returns the first value in the array
	T First();
	//Returns the last value in the array
	T Last();
	//Returns the first elemeents position
	int Begin();
	//Returns the lasts elements position
	int End();
	//Returns the first elemeents position
	int begin();
	//Returns the lasts elements position
	int end();

	//Gets a reference to the data array
	T* GetData();

	//Returns true if the array is sorted
	bool IsSorted();
	//Returns true when there are 0 elements in the array
	bool IsEmpty();
	//Returns true if the array has room for more element
	//without resizing
	bool HasRoom();

private:
	//Array of data
	T* m_data = new T[1];
	
	//Capacity of the array
	int m_cap;
	//Number of elememts
	int m_numOfEl;
};

template <typename T>
DynamicArray<T>::DynamicArray()
{
}

template<typename T>
inline DynamicArray<T>::DynamicArray(int a_size)
{
	Upsize(a_size);
}

template <typename T>
DynamicArray<T>::~DynamicArray()
{
	delete[] m_data;
}

template <typename T>
T& DynamicArray<T>::operator[](int a_iter)
{
	return m_data[a_iter];
}

template <typename T>
void DynamicArray<T>::operator=(DynamicArray a_dynArr)
{
	m_data = a_dynArr.GetData();
}

template <typename T>
void DynamicArray<T>::PushFront(T a_data)
{
	if (!HasRoom())
		Upsize();

	if (!IsEmpty())
	{
		T* newData = new T[m_cap];
		for (int i = 0; i < m_numOfEl; i++)
			newData[i + 1] = m_data[i];
		m_data = newData;
	}
	m_data[0] = a_data;
	m_numOfEl++;
}

template <typename T>
void DynamicArray<T>::PushBack(T a_data)
{
	if (!HasRoom())
		Upsize();

	m_numOfEl++;
	m_data[m_numOfEl - 1] = a_data;
}

template <typename T>
void DynamicArray<T>::Insert(int a_iter, T a_data)
{
	if (!HasRoom())
		Upsize();
	if (IsEmpty())
		m_data[0] = a_data;
	else
	{
		T * newData = new T[m_cap];
		for (int i = 0; i < m_numOfEl; i++)
		{
			if (i == a_iter)
				newData[i + 1] = m_data[i];
			else
				newData[i] = m_data[i];
		}
		m_data = newData;
		m_data[a_iter] = a_data;
	}
	m_numOfEl++;
}

template <typename T>
void DynamicArray<T>::PopBack()
{
	if (IsEmpty())
		cout << "Nothing to remove" << endl;
	else
		m_numOfEl--;
}

template <typename T>
void DynamicArray<T>::PopFront()
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

template <typename T>
void DynamicArray<T>::Erase(int a_iter)
{
	for (int i = 0; i < m_numOfEl; i++)
		if (i < a_iter)
			m_data[i] = m_data[i];
		else if (i + 1 != a_iter)
			m_data[i] = m_data[i + 1];
	m_numOfEl--;
}

template <typename T>
void DynamicArray<T>::Remove(T a_data)
{
	DynamicArray posList = DynamicArray();
	for (int i = 0; i < m_numOfEl; i++)
		if (m_data[i] == a_data)
			posList.PushBack(i);
	for (int i = 0; i < posList.Size(); i++)
		Erase(posList[i] - i);
}

template <typename T>
void DynamicArray<T>::Clear()
{
	m_numOfEl = 0;
}

template <typename T>
void DynamicArray<T>::Sort()
{
	if (!IsEmpty())
		while (!IsSorted())
		{
			for (int i = 0; i < m_numOfEl - 1; i++)
				if (m_data[i] > m_data[i + 1])
				{
					int temp = m_data[i];
					m_data[i] = m_data[i + 1];
					m_data[i + 1] = temp;
				}
		}
}

template <typename T>
void DynamicArray<T>::Upsize(int a_cap)
{
	int newCap;
	if (a_cap == 0)
		newCap = m_cap + 10;
	else
		newCap = m_cap + a_cap;

	T* newData = new T[newCap];
	int original = m_cap;
	m_cap = newCap;

	for (int i = 0; i < original; i++)
	{ 
		newData[i] = m_data[i];
	}
	m_data = newData;
}

template <typename T>
void DynamicArray<T>::Downsize()
{
	if (HasRoom())
	{
		m_cap = m_numOfEl;
		m_data = new T[m_cap];
	}
}

template <typename T>
void DynamicArray<T>::Print()
{
	if(typeid(T) != typeid(DoubleLinkedList<int>))
	for (int i = 0; i < m_numOfEl; i++)
	{ 
		cout << i << ") " << m_data[i] << endl;
	}
}

template <typename T>
int DynamicArray<T>::Size()
{
	return m_numOfEl;
}

template <typename T>
int DynamicArray<T>::Capacity()
{
	return m_cap;
}

template <typename T>
T DynamicArray<T>::First()
{
	if (!(IsEmpty()))
		return m_data[0];
	else {
		cout << "Array is Empty" << endl;
		return T();
	}
}

template <typename T>
T DynamicArray<T>::Last()
{
	if (!(IsEmpty()))
		return m_data[m_numOfEl - 1];
	else {
		cout << "Array is Empty" << endl;
		return T();
	}
}

template <typename T>
int DynamicArray<T>::Begin()
{
	return 0;
}

template <typename T>
int DynamicArray<T>::End()
{
	if (!IsEmpty())
		return m_numOfEl - 1;
	else return m_numOfEl;
}

template<typename T>
inline int DynamicArray<T>::begin()
{
	return 0;
}

template<typename T>
inline int DynamicArray<T>::end()
{
	return End();
}

template <typename T>
T * DynamicArray<T>::GetData()
{
	return m_data;
}

template <typename T>
bool DynamicArray<T>::IsSorted()
{
	if (!IsEmpty())
		for (int i = 0; i < m_numOfEl - 1; i++)
			if (m_data[i] > m_data[i + 1])
				return false;
	return true;
}

template <typename T>
bool DynamicArray<T>::IsEmpty()
{
	return !(m_numOfEl);
}

template <typename T>
bool DynamicArray<T>::HasRoom()
{
	return ((m_cap - m_numOfEl) > 0);
}
