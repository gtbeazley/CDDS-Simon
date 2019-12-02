#pragma once
class DynamicArray
{
public:
	/* Default constructor */
	DynamicArray(const int a_cap = 0);

	/* Destructor */
	~DynamicArray();

	/* Prints out the contents in thje array */
	void Print();

	/* Inserts a new element into the array */
	void Insert(int a_val, int a_pos);
	
	/* Checks if the array is empty */
	bool IsEmpty();

	/* Checks if there is any room left in the array */
	bool HasRoomLeft();

private: 
	int MaxCap;
	int curSize;
	int* m_elements;

};
