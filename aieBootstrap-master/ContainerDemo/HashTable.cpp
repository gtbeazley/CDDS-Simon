#include "HashTable.h"

namespace Hash
{
	HashTable::HashTable()
	{
		while (list.HasRoom())
			list.PushBack(DoubleLinkedList<int>());

		while (keys.HasRoom())
			keys.PushBack(DoubleLinkedList<string>());
	}

	HashTable::~HashTable()
	{
	}

	void HashTable::AddVal(string a_key, int a_data)
	{
		int HashVal = defaultHash(a_key.c_str(), (unsigned int)a_key.size(), list.Size());
		keys[HashVal].PushBack(a_key);
		list[HashVal].PushBack(a_data);
		m_numOfEl++;
	}

	void HashTable::RemoveValAtKey(string a_key)
	{
		int HashVal = defaultHash(a_key.c_str(), (int)a_key.size(), list.Size());
		int i;
		for (i = 0; keys[HashVal][i] != nullptr; i++)
			if (keys[HashVal][i]->data == a_key)
			{
				keys[HashVal].Erase(i);
				list[HashVal].Erase(i);
				m_numOfEl--;
				cout << "'" << a_key << "' was successfully deleted.";
				return;
			}
		cout << "'" << a_key << "' was not found.";
	}

	void HashTable::ClearTable()
	{
		if (IsEmpty())
			cout << "Nothing to delete" << endl;
		else {
			for (int i = 0; i < list.Size(); i++)
			{
				list[i].Clear();
				keys[i].Clear();
			}
			m_numOfEl = 0;
			cout << "Table Successfully cleared" << endl;
		}
		
	}

	void HashTable::Upsize(int a_cap)
	{
		DoubleLinkedList<int> tempData = DoubleLinkedList<int>();
		DoubleLinkedList<string> tempKeys = DoubleLinkedList<string>();
		for (int i = 0; i < list.Size(); i++)
		{
			for (int j = 0; j < list[i].Size(); j++)
			{
				tempData.PushBack(list[i][j]->data);
				tempKeys.PushBack(keys[i][j]->data);
			}
		}

		list.Upsize(a_cap);
		while (list.HasRoom())
			list.PushBack(DoubleLinkedList<int>());

		keys.Upsize(a_cap);
		while (keys.HasRoom())
			keys.PushBack(DoubleLinkedList<string>());
		ClearTable();
		for (int i = 0; i < tempData.Size(); i++)
			AddVal(tempKeys[i]->data, tempData[i]->data);

	}

	void HashTable::DownSize(int a_cap)
	{
		DoubleLinkedList<int> tempData = DoubleLinkedList<int>();
		DoubleLinkedList<string> tempKeys = DoubleLinkedList<string>();
		for (int i = 0; i < list.Size(); i++)
		{
			for (int j = 0; j < list[i].Size(); j++)
			{
				tempData.PushBack(list[i][j]->data);
				tempKeys.PushBack(keys[i][j]->data);
			}
		}
		keys.Downsize();
		list.Downsize();
		ClearTable();
		for (int i = 0; i < tempData.Size(); i++)
			AddVal(tempKeys[i]->data, tempData[i]->data);
	}

	void HashTable::Print()
	{
		for (int i = 0; i < list.Size(); i++)
		{
			cout << i << ")";
			for (int j = 0; j < list[i].Size(); j++)
				cout << keys[i][j]->data << ": " << list[i][j]->data << ", ";
			cout << endl;
		}
	}

	bool HashTable::IsEmpty()
	{
		for (int i = 0; i < keys.Size(); i++)
			if (!keys[i].IsEmpty())
				return false;
		return true;
	}

	int HashTable::NumOfEl()
	{
		return m_numOfEl;
	}

	int HashTable::operator[](string a_key)
	{
		int HashVal = defaultHash(a_key.c_str(), (int)a_key.size(), m_size);
		int i;
		for (i = 0; keys[HashVal][i] != nullptr; i++)
			if (keys[HashVal][i]->data == a_key)
				return list[HashVal][i]->data;
		cout << "'" << a_key << "' does not exist";
		return NULL;
	}

	DynamicArray<DoubleLinkedList<string>>* HashTable::GetAllKeys()
	{
		return &keys;
	}

}
