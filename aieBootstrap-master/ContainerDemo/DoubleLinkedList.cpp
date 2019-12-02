#include "DoubleLinkedList.h"
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

		if (Empty())
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
	if (Empty())
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
	if (Empty())
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

			cur->next->prev = n;
			n->next = cur->next;
			cur->next = n;
			n->prev = cur;
		}
	}
}


void DoubleLinkedList::PopFront()
{
	if (!Empty())
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
	if (!Empty())
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
	if (!Empty())
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
	if (!Empty())
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
	if (!Empty())
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

	if (!IsSorted() && !Empty())
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
				cur = m_last;
			}
		}
		SetSorted(true);
	}
}

void DoubleLinkedList::SetSorted(bool a_bool)
{
	m_sortedState = a_bool;
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



int DoubleLinkedList::Size()
{

	if (Empty())
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



bool DoubleLinkedList::Empty()
{
	return m_first != nullptr;
}



bool DoubleLinkedList::IsSorted()
{
	if (!Empty())
	{
		Node* cur = m_first;
		while (cur != m_last)
		{
			if (cur->data > cur->next->data)
				return false;
			cur = cur->next;
		}
	}
	return true;
}
