#pragma once
#include "Repository.h"
#include "ShopBasket.h"

class Controller
{
private:
	Repository repo;
	ShopBasket shopbasket;

public:
	Controller(const Repository& r) : repo(r) {}

	bool addToRepository(TrenchCoat x);
	// Adds a trench coat with the given data to the trenchcoat repository.

	bool deleteFromRepository(TrenchCoat x);
	// Deletes a trench coat with the given data from the trenchcoat repository.

	bool updateFromRepository(TrenchCoat x, TrenchCoat y);
	// Updates a trench coat with the given data from the repository

	void printRepository();
	// Prints the trenchcoat repository.


	void addToShopBasket(TrenchCoat x);
	/*
	Adds a given trench coat to the current shopbasket.
	Input: x - TrenchCoat, the trenchcoat must belong to the repository.
	Output: the trenchcoat is added to the shopbasket.
	*/

	void printShopBasket();
	// Prints the shopbag.

	int getShopBasketSum();
	// Returns the total price of trench coats from shopbasket.

	TrenchCoat* getAllRepository();
	// Returns all the elements from the repository. 

	int getSizeRepository();
	// Returns the size of the repository.

};