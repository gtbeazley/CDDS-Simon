#pragma once
class DynamicArray
{
public:
	DynamicArray();
	~DynamicArray();

	int operator [](int a_iter);

	void operator = (DynamicArray a_dynArr);

	void PushFront(int a_data);
	void PushBack(int a_data);
	void Insert(int a_iter, int a_data);
	void PopBack();
	void PopFront();
	void Erase(int a_iter);
	void Remove(int a_data);
	void Clear();
	void Sort();
	void Upsize(int a_cap = 0);
	void Downsize();

	void Print();

	int Size();
	int Capacity();
	int First();
	int Last();
	int Begin();
	int End();

	int* GetData();

	bool IsEmpty();
	bool HasRoom();

private:
	int* m_data = new int[1];
	int m_cap;
	int m_numOfEl;
};

