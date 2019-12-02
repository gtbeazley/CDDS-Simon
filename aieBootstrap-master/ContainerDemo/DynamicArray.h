#pragma once
class DynamicArray
{
public:
	DynamicArray();
	~DynamicArray();

	void PushFront(int a_data);
	void PushBack(int a_data);
	void Insert(int a_iter, int a_data);
	void PopBack();
	void PopFront();
	void Erase(int a_iter);
	void Remove(int a_data);
	void Clear();
	void Sort();
	void Upsize();

	int Size();
	int Capacity();

	bool IsEmpty();
	bool HasRoom();

private:
	int* m_data;
	int m_cap;
	int m_numOfEl;
};

