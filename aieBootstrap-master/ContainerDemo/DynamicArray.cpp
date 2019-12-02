#include "DynamicArray.h" 

DynamicArray::DynamicArray()
{
} 

DynamicArray::~DynamicArray()
{
}

void DynamicArray::PushFront(int a_data)
{
	if (!HasRoom())
		Upsize();

	if(!IsEmpty())
	{
		int* newData = nullptr;
		for (int i = 0; i < m_numOfEl; i++)
			newData[i + 1] = m_data[i];
		m_data = newData;
	}
	m_data[0] = a_data; 
}

void DynamicArray::PushBack(int a_data)
{
	if (!HasRoom())
		Upsize();
	m_data[m_numOfEl] = a_data;
}

void DynamicArray::Insert(int a_iter, int a_data)
{

}

void DynamicArray::PopBack()
{
}

void DynamicArray::PopFront()
{
}

void DynamicArray::Erase(int a_iter)
{
}

void DynamicArray::Remove(int a_data)
{
}

void DynamicArray::Clear()
{
}

void DynamicArray::Sort()
{
}

void DynamicArray::Upsize()
{
	m_cap += 5;
	int* newData = new int[m_cap];
	for (int i = 0; i < m_cap - 5; i++)
		newData[i] = m_data[i];

	m_data = newData;
}

int DynamicArray::Size()
{
	return m_numOfEl;
}

int DynamicArray::Capacity()
{
	return m_cap;
}

bool DynamicArray::IsEmpty()
{
	return !(m_numOfEl);
}

bool DynamicArray::HasRoom()
{
	return ((m_cap - m_numOfEl) > 0);
}
