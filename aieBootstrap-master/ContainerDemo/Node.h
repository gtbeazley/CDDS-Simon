#pragma once
template <typename T>
class DoubleLinkedList;

template<typename T>
class Node
{
	friend class DoubleLinkedList<T>;
public:
	Node(T a_data = T()); 
	~Node();

	Node<T> *next, *prev;
	T data;
};

template<typename T>
Node<T>::Node(T a_data) : data(a_data), prev(nullptr), next(nullptr)
{
	data = a_data;
}

template<typename T>
Node<T>::~Node()
{
}
