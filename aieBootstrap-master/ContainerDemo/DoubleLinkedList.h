#pragma once
class DoubleLinkedList
{
public:
	DoubleLinkedList();
	~DoubleLinkedList();

	void PushFront(int a_data);
	void PushBack(int a_data);
	void Insert(int a_iter, int a_data);
	void PopBack();
	void PopFront();
	void Erase(int a_iter);
	void Remove(int a_data);
	void Clear();
	void Sort();
	void SetSorted(bool a_bool);

	int First();
	int Last();

	int Size();

	bool Empty();
	bool IsSorted();

	int GiveMeThis = 1;

private:
	bool m_sortedState = false;

	class Node
	{
	public:
		Node(int a_v) : data(a_v), next(nullptr), prev(nullptr) { };
		~Node() { };

		Node	*next,
			*prev;
		int		 data;
	};

	Node	*m_first,
		*m_last;
};

