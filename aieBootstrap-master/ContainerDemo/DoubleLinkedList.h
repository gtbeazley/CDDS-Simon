#pragma once
class DoubleLinkedList
{
private:
	class Node
	{
	public:
		Node(int a_v) : data(a_v), next(nullptr), prev(nullptr) { };
		~Node() { };

		Node	*next,
			*prev;
		int		 data;
	};
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

	void Print();

	Node* Search(int a_val);
	Node* linSearch(int a_val);
	Node* binSearch(int a_val);

	int First();
	int Last();
	int Begin();
	int End();

	int Size();
	int GiveMeThis = 1;

	bool IsEmpty();
	bool IsSorted();

	Node* operator [](int a_iter);

private:

	bool m_sortedState = false;
	Node *m_first, *m_last;
};

