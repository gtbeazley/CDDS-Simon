#include "DoubleLinkedList.h"
#include <iostream>

using namespace std;

DoubleLinkedList::DoubleLinkedList() : m_first(nullptr), m_last(nullptr)
{

};


DoubleLinkedList::~DoubleLinkedList()
{

}


void DoubleLinkedList::PushFront(int a_data)
{
	Node* n = new Node(a_data);
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


void DoubleLinkedList::PushBack(int a_data)
{
	Node* n = new Node(a_data);
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



void DoubleLinkedList::Insert(int a_iter, int a_data)
{
	Node* n = new Node(a_data);
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
			Node* cur = m_first;
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


void DoubleLinkedList::PopFront()
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


void DoubleLinkedList::PopBack()
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



void DoubleLinkedList::Erase(int a_iter)
{
	if (!IsEmpty())
	{
		if (a_iter <= 0)
			PopFront();
		else if (a_iter >= Size())
			PopBack();
		else
		{
			Node* cur = m_first;
			for (int i = 0; i < a_iter; i++)
				cur = cur->next;
			cur->next->prev = cur->prev;
			cur->prev->next = cur->next;
			delete cur;
		}
	}
}


void DoubleLinkedList::Remove(int a_data)
{
	if (!IsEmpty())
	{
		while (First() == a_data)
			PopFront();
		while (Last() == a_data)
			PopBack();
		int i = 0;
		Node* cur = m_first;
		while (cur != nullptr)
		{
			if (cur->data == a_data)
				Erase(i);
			i++;
			cur = cur->next;
		}
	}
}



void DoubleLinkedList::Clear()
{
	if (!IsEmpty())
	{
		if (Size() > 1)
		{
			Node* cur = m_first;
			m_first = nullptr;
			if (m_first->next != nullptr)
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

void DoubleLinkedList::Sort()
{

	if (!IsSorted() && !IsEmpty())
	{
		while (!IsSorted())
		{
			Node* cur = m_first;
			if (cur->data > cur->next->data)
			{
				m_first = cur->next;
				m_first->prev = nullptr;
				cur->next = m_first->next;
				m_first->next = cur;
				cur->next->prev = cur;
				cur->prev = m_first;
			}
			else
				cur = cur->next;
			while (cur->next != m_last)
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

void DoubleLinkedList::SetSorted(bool a_bool)
{
	m_sortedState = a_bool;
}

void DoubleLinkedList::Print()
{
	if (!IsEmpty())
	{
		Node* n = m_first;
		int i = 1;
		while (n != nullptr)
		{
			cout << i << ") " << n->data << endl;
			i++;
			n = n->next;
		}
	}
}



int DoubleLinkedList::First()
{
	if (m_first != nullptr)
		return m_first->data;
	else
		throw "invalid target";

}


int DoubleLinkedList::Last()
{
	if (m_last != nullptr)
		return m_last->data;
	else
		throw "invalid target";
}

int DoubleLinkedList::Begin()
{
	return 0;
}

int DoubleLinkedList::End()
{
	return Size() - 1;
}



int DoubleLinkedList::Size()
{

	if (IsEmpty())
		return 0;
	else
	{
		Node* cur = m_first;
		int i = 0;
		while (cur != nullptr)
		{
			i++;
			cur = cur->next;
		}
		return i;
	}
}



bool DoubleLinkedList::IsEmpty()
{
	return m_first == nullptr;
}



bool DoubleLinkedList::IsSorted()
{
	if (!IsEmpty())
	{
		Node* cur = m_first;
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
