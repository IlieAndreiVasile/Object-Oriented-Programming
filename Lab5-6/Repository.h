#pragma once
#include "TrenchCoat.h"
#include "DynamicVector.h"

class Repository
{
private:
	DynamicVector <TrenchCoat> trenchcoats;

public:
	Repository() {}
	/*
	Default constructor.
	Initializes an object of type repository.
	*/

	int find(TrenchCoat x);
	/*
	Search for an element into the repository.
	An element is uniquely determinated by size and color.
	Input:  x - an object of the class TrenchCoat.
	Output: an integer that represents the position of the searched element in the repository.
			-1 - if the element was not found.
	*/

	bool add(TrenchCoat x);
	/*
	Adds a trench coat to the repository.
	Input:  x - an object of the class TrenchCoat.
	Output: False - if the trench coat already exists in the repository.
			True - if the trench coat was added to the repository.
	*/

	bool del(TrenchCoat x);
	/*
	Deletes a trench coat from the repository.
	Input:  x - an object of the class TrenchCoat.
	Output: False - if the trench coat already exists in the repository.
			True - if the trench coat was deleted to the repository.
	*/

	bool update(TrenchCoat x, TrenchCoat y);
	/*
	Updates a trench coat from the repository.
	Input:  x - an object of the class TrenchCoat which we want to update.
			y - an object of the class TrenchCoat with whitch we want to update.
	Output: False - if the trench coat was not updated.
			True - if the trench coat was updateed to the repository.
	*/

	void print();
	// Prints the repository.

	TrenchCoat* getAll();
	/*
	Gets all the elements from the repository.
	Returns a pointer to the first element of the dynamic vector of trench coats.
	*/

	int getSize();
	// Returns the size of the repository.
};