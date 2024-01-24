#pragma once
#include <iostream>
#include <stdexcept>
#define MAX_SIZE 1000

template <typename T> class ArrayBag
{
private:
	static const int DEFAULT_SIZE{ 25 };
	int currentBagSize = DEFAULT_SIZE;
	int numberOfEntries{ 0 };
	bool integrityCheck = false;

	T checkValueOne = NULL;
	T checkValueTwo = NULL;

	inline static T* bagArray;
	bool operator== (const ArrayBag<T>& check) {
		return check.checkValueOne == check.checkValueTwo;
	}


	T printValue = NULL;
	friend std::ostream& operator<<(std::ostream& os, const ArrayBag<T>& check) {
		os << check.printValue;
		return os;
	}

	T& operator[](const int index) {
		return bagArray[index];
	}

public:
	ArrayBag(int bagSize);

	ArrayBag();

	~ArrayBag();


	virtual int getCurrentSize(); // return size of bag
	virtual bool isEmpty(); // return true if bag empty
	virtual void clearBag(); // removes all itesm from bag
	 
	virtual bool add(T newEntry); // return true if item was added
	virtual bool remove(T anEntry); // remove certain item
	virtual T remove(); // remove all items 
	virtual int getFrequencyOf(T anEntry); // return number of times anEntry is in array
	virtual bool contains(T anEntry); // return true if array contains anEntry
	virtual bool isArrayFull(); // return true if array full
	virtual bool doubleBagSize(); // return true if bag size was doubled
	virtual bool isArrayCreated(); // return true if bag was successfully created.
	virtual void printBag();

};
