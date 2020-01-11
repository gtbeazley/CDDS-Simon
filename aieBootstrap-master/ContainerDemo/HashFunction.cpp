#include "HashFunction.h"

namespace Hash {
	// implementation of a basic addition hash
	unsigned int badHash(const char* data, unsigned int length, const int unused) {
		unsigned int hash = 0;

		for (unsigned int i = 0; i < length; ++i)
			hash += data[i];
		return hash;
	}
	unsigned int myHash(const char * data, unsigned int length, const int tableSize)
	{
		unsigned int hash = 0;
		for (int i = 0; i < length; i++)
			hash += ((int)data[i] * length - i);

		return hash % tableSize;
	}
}