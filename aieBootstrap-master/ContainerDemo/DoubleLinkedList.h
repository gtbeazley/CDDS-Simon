#pragma once  

#include <iostream> 

using namespace std;

template <typename T>
class Node;

template<typename T>
class DoubleLinkedList
{
	struct Iterator {
	private:
		typename Node<T>* curNode;

	public:
		Iterator() {}
		//Iterator(Node<T>* a_node) { curNode = a_Node; }
		Iterator(int a_iter) { curNode = m_first; this += a_iter; }
		//Accessor Function
		T current() { return curNode->data; }
		//Accessor operator
		T operator * () { current(); }

		//returns true if the iterator can iterate next node
		bool moveNext() { return (curNode->next != nullptr); }
		//returns true if the iterator can iterate prev node 
		bool movePrev() { return (curNode->prev != nullptr); }
		
		//Iterates to the next node a_iter times
		void operator += (int a_iter) { int i = a_iter; while (i != 0) curNode = curNode->next; i--; }
		//Iterates to the next node 
		void operator ++ () { curNode = curNode->next; }
		//Iterates to the prev node a_iter times
		void operator -= (int a_iter ) { int i = a_iter; while (i != 0) curNode = curNode->prev; i--; }
		//Iterates to the prev node 
		void operator -- () { curNode = curNode->prev; }
	};
	
public:  
	//Default Constructor
	DoubleLinkedList();
	//Default Destructor
	~DoubleLinkedList();
	//Adds node to the start of the list with the value of a_data
	void PushFront(T a_data);
	//Adds node at the end of the list with the value of a_data 
	void PushBack(T a_data);
	//Adds node at the position of a_iter with the value of a_data
	void Insert(int a_iter, T a_data);
	//Deletes the node at the end of the list
	void PopBack();
	//Deletes the node at the start of the list
	void PopFront();
	//Deletes the node that is at the position a_iter
	void Erase(int a_iter);
	//Deletes the first node in the list with the value a_data
	void Remove(T a_data);
	//Deletes all node within the list
	void Clear();
	//Sorts the list
	void Sort();
	//Sets the sorted state of the list;
	void SetSorted(bool a_bool);

	//Prints all nodes data
	void Print();

	//Returns a ptr to the first node with the value a_val 
	//by using the linSearch method if the list is not sorted and binSearch if the list is sorted
	Node<T>* Search(T a_val);
	//Returns a ptr to the first node with the value a_val by searching each node one by one
	Node<T>* linSearch(T a_val);
	//Returns a ptr to the first node with the value a_val by using a binary search method
	Node<T>* binSearch(T a_val);

	//Returns the value of the first node in the list
	T First();
	//Returns the value of the last node in the list
	T Last();
	
	//Returns an integer of the first nodes position value
	int Begin();
	//Returns an integer of the last node position value
	int End();

	//Gets the size of the list
	int Size();
	//This was just a request for my double linked list code
	int GiveMeThis = 1;

	//Returns true if no nodes in the list exist
	bool IsEmpty();
	//Returns true if the list has been sorted
	bool IsSorted();

	Iterator begin();
	Iterator end();
	
	//Returns a pointer to the node at the position of a_iter
	Node<T>* operator [](int a_iter);

private:

	bool m_sortedState = false;
	Node<T>* m_first, *m_last;
};

template<typename T>
DoubleLinkedList<T>::DoubleLinkedList() : m_first(nullptr), m_last(nullptr)
{

};

template<typename T>
DoubleLinkedList<T>::~DoubleLinkedList<T>()
{

}

template<typename T>
void DoubleLinkedList<T>::PushFront(T a_data)
{
	Node<T>* n = new Node<T>(a_data);
	if (n)
	{

		if (IsEmpty())
		{
			m_first = n;
			m_last = n;
		}
		else
		{
			m_first->prev = n;
			n->next = m_first;
			m_first = n;
		}
	}
}

template<typename T>
void DoubleLinkedList<T>::PushBack(T a_data)
{
	Node<T>* n = new Node<T>(a_data);
	if (IsEmpty())
	{
		m_first = n;
		m_last = n;
	}
	else
	{
		m_last->next = n;
		n->prev = m_last;
		m_last = n;
	}
}

template<typename T>
void DoubleLinkedList<T>::Insert(int a_iter, T a_data)
{
	Node<T>* n = new Node<T>(a_data);
	if (IsEmpty())
	{
		m_first = n;
		m_last = n;
	}
	else
	{
		if (a_iter <= 0)
			PushFront(a_data);
		else if (a_iter >= Size())
			PushBack(a_data);
		else
		{
			Node<T>* cur = m_first;
			for (int i = 0; i < a_iter; i++)
				cur = cur->next;

			if (cur->prev != nullptr)
			{
				cur->prev->next = n;
				n->prev = cur->prev;
			}
			cur->prev = n;
			n->next = cur;
		}
	}
}

template<typename T>
void DoubleLinkedList<T>::PopFront()
{
	if (!IsEmpty())
	{
		if (Size() > 1)
		{
			m_first = m_first->next;
			delete m_first->prev;
			m_first->prev = nullptr;
		}
		else
		{
			delete m_first;
			m_first = nullptr;
			m_last = nullptr;
		}
	}
}

template<typename T>
void DoubleLinkedList<T>::PopBack()
{
	if (!IsEmpty())
	{
		if (Size() > 1)
		{
			m_last = m_last->prev;
			delete m_last->next;
			m_last->next = nullptr;
		}
		else
		{
			delete m_first;
			m_first = nullptr;
			m_last = nullptr;
		}
	}
}

template<typename T>
void DoubleLinkedList<T>::Erase(int a_iter)
{
	if (!IsEmpty())
	{
		if (a_iter <= 0)
			PopFront();
		else if (a_iter >= Size())
			PopBack();
		else
		{
			Node<T>* cur = m_first;
			for (int i = 0; i < a_iter; i++)
				cur = cur->next;
			cur->next->prev = cur->prev;
			cur->prev->next = cur->next;
			delete cur;
		}
	}
}

template<typename T>
void DoubleLinkedList<T>::Remove(T a_data)
{
	if (!IsEmpty())
	{
		while (First() == a_data)
			PopFront();
		while (Last() == a_data)
			PopBack();
		int i = 0;
		Node<T>* cur = m_first;
		while (cur != nullptr)
		{
			if (cur->data == a_data)
				Erase(i);
			i++;
			cur = cur->next;
		}
	}
}

template<typename T>
void DoubleLinkedList<T>::Clear()
{
	if (!IsEmpty())
	{
		if (Size() > 1)
		{
			Node<T>* cur = m_first;
			m_first = nullptr;
			if (cur->next != nullptr)
				cur = cur->next;
			while (cur != nullptr)
			{
				delete cur->prev;
				cur = cur->next;
			}
			delete m_last;
			m_last = nullptr;
		}
		else
			PopBack();
	}

}

template<typename T>
void DoubleLinkedList<T>::Sort()
{

	if (!IsSorted() && !IsEmpty())
	{
		while (!IsSorted())
		{
			Node<T>* cur = m_first;
			if (cur->data > cur->next->data)
			{
				m_first = cur->next;
				m_first->prev = nullptr;
				cur->next = m_first->next;
				m_first->next = cur;
				if (cur->next != nullptr)
					cur->next->prev = cur;
				cur->prev = m_first;
			}
			else
				cur = cur->next;
			while (cur->next != m_last && cur->next != nullptr)
			{
				if (cur->data > cur->next->data)
				{
					cur->prev->next = cur->next;
					cur->next->prev = cur->prev;
					cur->prev = cur->next;
					cur->next = cur->next->next;
					cur->next->prev->next = cur;
					cur->next->prev = cur;
				}
				else
					cur = cur->next;
			}
			if (cur->data > m_last->data)
			{
				cur->prev->next = m_last;
				cur->next = nullptr;
				m_last->next = cur;
				m_last->prev = cur->prev;
				cur->prev = m_last;
				m_last = cur;
			}
			system("CLS");
			Print();
		}
	}
}

template<typename T>
void DoubleLinkedList<T>::SetSorted(bool a_bool)
{
	m_sortedState = a_bool;
}

template<typename T>
void DoubleLinkedList<T>::Print()
{
	if (!IsEmpty())
	{
		Node<T>* n = m_first;
		int i = 1;
		while (n != nullptr)
		{
			cout << i << ") " << n->data << endl;
			i++;
			n = n->next;
		}
	}
}

template<typename T>
Node<T>* DoubleLinkedList<T>::Search(T a_val)
{
	if (!IsEmpty())
		if (IsSorted())
			return binSearch(a_val);
		else
			return linSearch(a_val);
	else
	{
		cout << "Empty list";
		return nullptr;
	}
}

template<typename T>
Node<T>* DoubleLinkedList<T>::linSearch(T a_val)
{
	Node<T> * cur = m_first;
	while (cur != nullptr)
	{
		if (cur->data == a_val)
			return cur;
		cur = cur->next;
	}
	cout << "does not exist in this list" << endl;
	return nullptr;
}

template<typename T>
Node<T>* DoubleLinkedList<T>::binSearch(T a_val)
{
	int searchSize = Size() - 1;
	int searchPos = searchSize / 2;
	Node<T>* head = m_first;
	Node<T>* tail = m_last;
	Node<T>* cur = (*this)[searchPos];
	while (head != tail && cur != nullptr && tail != nullptr)
	{
		searchSize /= 2;
		if (head->data == a_val)
			return head;
		if (tail->data == a_val)
			return tail;
		if (a_val < cur->data)
		{
			tail = cur;
			searchPos -= searchSize;
		}
		else if (a_val > cur->data)
		{
			head = cur;
			searchPos += searchSize;
		}
		else if (cur->data == a_val)
			return cur;

		cur = (*this)[searchPos];
	}
	cout << "That value does not exist" << endl;
	return nullptr;
}

template<typename T>
T DoubleLinkedList<T>::First()
{
	if (m_first != nullptr)
		return m_first->data;
	else
		throw "invalid target";

}

template<typename T>
T DoubleLinkedList<T>::Last()
{
	if (m_last != nullptr)
		return m_last->data;
	else
		throw "invalid target";
}

template<typename T>
int DoubleLinkedList<T>::Begin()
{
	return 0;
}

template<typename T>
int DoubleLinkedList<T>::End()
{
	return Size() - 1;
}

template<typename T>
int DoubleLinkedList<T>::Size()
{

	if (IsEmpty())
		return 0;
	else
	{
		Node<T>* cur = m_first;
		int i = 0;
		while (cur != nullptr)
		{
			i++;
			cur = cur->next;
		}
		return i;
	}
}

template<typename T>
bool DoubleLinkedList<T>::IsEmpty()
{
	return m_first == nullptr;
}

template<typename T>
bool DoubleLinkedList<T>::IsSorted()
{
	if (!IsEmpty())
	{
		Node<T>* cur = m_first;
		while (cur != m_last)
		{
			if (cur->data > cur->next->data)
				return false;
			cur = cur->next;
		}
		return true;
	}
	return true;
}

template<typename T>
typename DoubleLinkedList<T>::Iterator DoubleLinkedList<T>::begin()
{
	return Iterator(m_first);
}

template<typename T>
typename DoubleLinkedList<T>::Iterator DoubleLinkedList<T>::end()
{
	return Iterator(m_last);
}

template<typename T>
Node<T>* DoubleLinkedList<T>::operator[](int a_iter)
{
	if (IsEmpty())
		return nullptr;
	if (a_iter > Size() - 1)
		return m_last;
	Node<T>* cur = m_first;
	for (int i = 0; i < a_iter; i++)
		cur = cur->next;
	return cur;
}

