#pragma once
#include "TrenchCoat.h"
#include "Exceptions.h"
#include <vector>
#include <string>
#include <fstream>

class Repository
{
private:
	std::vector <TrenchCoat> v;

public:
	Repository() {}
	/*
	Default constructor.
	Initializes an object of type repository.
	*/

	int find(const TrenchCoat& x);
	/*
	Search for an element into the repository.
	An element is uniquely determinated by size and color.
	Input:  x - an object of the class TrenchCoat.
	Output: an integer that represents the position of the searched element in the repository.
	-1 - if the element was not found.
	*/

	void add(const TrenchCoat& x);
	/*
	Adds a trench coat to the repository.
	Input:  x - an object of the class TrenchCoat.
	Output: False - if the trench coat already exists in the repository.
	True - if the trench coat was added to the repository.
	*/

	void del(const TrenchCoat& x);
	/*
	Deletes a trench coat from the repository.
	Input:  x - an object of the class TrenchCoat.
	Output: False - if the trench coat already exists in the repository.
	True - if the trench coat was deleted to the repository.
	*/

	void update(const TrenchCoat& x);
	/*
	Updates a trench coat from the repository.
	Input:  x - an object of the class TrenchCoat which we want to update.
	y - an object of the class TrenchCoat with whitch we want to update.
	Output: False - if the trench coat was not updated.
	True - if the trench coat was updateed to the repository.
	*/

	void print();
	// Prints the repository.

	std::vector <TrenchCoat>& getAll();
	/*
	Gets all the elements from the repository.
	Returns a pointer to the first element of the vector of trench coats.
	*/

	int getSize();
	// Returns the size of the repository.

	void writeToFile();
	void readFromFile();
};