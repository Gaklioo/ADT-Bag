#include "arrayBag.h"

template <typename T>
bool ArrayBag<T>::isArrayCreated() {
	return integrityCheck;
}

template <typename T>
int ArrayBag<T>::getCurrentSize() {
	if(isArrayCreated())
	{
		return currentBagSize;
	}
	return 0;
}

template <typename T>
bool ArrayBag<T>::isEmpty() {
	return numberOfEntries > 0;
}

template <typename T>
T ArrayBag<T>::remove() {
	if (isArrayCreated())
	{
		bagArray = new T[currentBagSize];
		numberOfEntries = 0;
		return true;
	}
	return false;
}

template <typename T>
bool ArrayBag<T>::remove(T anEntry) {
	if (isArrayCreated())
	{
		for (int i = 0; i < numberOfEntries; i++) 
		{
			checkValueOne = bagArray[i];
			checkValueTwo = anEntry;
			if (checkValueOne == checkValueTwo)
			{
				bagArray[i] = bagArray[numberOfEntries - 1];
				bagArray[numberOfEntries - 1] = NULL;
				numberOfEntries--;
				return true;
			}
		}
	}
	return false;
}

template <typename T>
bool ArrayBag<T>::doubleBagSize() {
	if ((currentBagSize * 2) <= MAX_SIZE)
	{
		static T* newBag = new T[currentBagSize * 2];
		for (int i = 0; i < currentBagSize; i++)
		{
			newBag[i] = bagArray[i];
			bagArray[i] = newBag[i];
		}


		currentBagSize *= 2;
		delete[] newBag;
		return true;
	}
	return false;
}

template <typename T>
bool ArrayBag<T>::isArrayFull() {
	if (numberOfEntries > currentBagSize) {
		return doubleBagSize();
	}
	return false;
}

template <typename T>
bool ArrayBag<T>::add(T newEntry) {
	if (isArrayCreated())
	{
		isArrayFull();
		bagArray[numberOfEntries] = newEntry;
		numberOfEntries++;
		return true;
	}
	return false;
}

template <typename T>
ArrayBag<T>::~ArrayBag() {
	delete[] bagArray;
}

template <typename T>
ArrayBag<T>::ArrayBag() {
	bagArray = new T[DEFAULT_SIZE];
	integrityCheck = true;
	checkValueOne = NULL;
	checkValueTwo = NULL;
}

template <typename T>
ArrayBag<T>::ArrayBag(int bagSize) {
	if (MAX_SIZE > bagSize) {
		bagArray = new T[bagSize];

		currentBagSize = bagSize;
		integrityCheck = true;
	}
	else {
		integrityCheck = false;
		throw std::invalid_argument("Attempted to create bag with more than maximum ammount");
	}
}



template <typename T>
void ArrayBag<T>::clearBag() {
	if (isArrayCreated())
	{
		remove();
	}
}

template <typename T>
int ArrayBag<T>::getFrequencyOf(T anEntry) {
	int sum = 0;
	if (isArrayCreated())
	{
		for (int i = 0; i < numberOfEntries - 1; i++)
		{
			checkValueOne = bagArray[i];
			checkValueTwo = anEntry;
			if (checkValueOne == checkValueTwo) 
			{
				++sum;
			}
		}

		return sum;
	}
	return 0;
}

template <typename T>
bool ArrayBag<T>::contains(T anEntry) {
	if (isArrayCreated())
	{
		for (int i = 0; i < numberOfEntries - 1; i++) {
			checkValueOne = bagArray[i];
			checkValueTwo = anEntry;
			if (checkValueOne == checkValueTwo) {
				return true;
			}
		}
	}
	return false;
}

template <typename T>
void ArrayBag<T>::printBag() {
	if (isArrayCreated())
	{
		for (int i = 0; i < numberOfEntries; i++)
		{
			printValue = bagArray[i];
			std::cout << printValue << std::endl;
		}
	}
}

template <typename T>
void ArrayBag<T>::deleteBag() {
	ArrayBag<T>::~ArrayBag();
}

int main() {
	ArrayBag<int> *bag = new ArrayBag<int>(3);
	bag->add(10);
	bag->add(20);
	bag->add(30);
	std::cout << bag->getCurrentSize() << std::endl;
	bag->doubleBagSize();
	std::cout << bag->getCurrentSize() << std::endl;
	bag->add(40);
	bag->add(50);
	bag->add(60);
	bag->printBag();


}
