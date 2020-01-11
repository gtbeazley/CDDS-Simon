#pragma once
#include <functional>

namespace Hash {
	typedef std::function< unsigned int(const char*, unsigned int, const int)> HashFunc; 

	// implementation of a basic addition hash
	unsigned int badHash(const char* data, unsigned int length, const int unused = 0);
	
	// ADD YOUR FUNCTIONS HERE
	unsigned int myHash(const char* data, unsigned int length, const int tableSize); 

	// a helper to access a default hash function
	static HashFunc defaultHash = myHash; 
}