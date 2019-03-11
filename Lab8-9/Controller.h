#pragma once
#include "Repository.h"
#include "ShopBasket.h"
#include "TrenchCoatValidator.h"
#include "Exceptions.h"

class Controller
{
private:
	Repository repo;
	ShopBasket *basket;
	TrenchCoatValidator validator;

public:
	Controller(const Repository& r, ShopBasket *b) : repo(r), basket(b) {}

	void addToRepository(int size, const std::string& colour, int price, int quantity, const std::string& photograph);
	// Adds a trench coat with the given data to the trenchcoat repository.

	void deleteFromRepository(int size, const std::string& colour, int price, int quantity, const std::string& photograph);
	// Deletes a trench coat with the given data from the trenchcoat repository.

	void updateFromRepository(int size, const std::string& colour, int price, int quantity, const std::string& photograph);
	// Updates a trench coat with the given data from the repository

	void printRepository() { return this->repo.print(); }
	// Prints the trenchcoat repository.


	void addToShopBasket(const TrenchCoat& x) { this->basket->add(x); }
	/*
	Adds a given trench coat to the current shopbasket.
	Input: x - TrenchCoat, the trenchcoat must belong to the repository.
	*/

	void printShopBasket() { return this->basket->print(); }
	// Prints the shopbag.

	int getShopBasketSum() { return this->basket->getSum(); }
	// Returns the total price of trench coats from shopbasket.

	std::vector<TrenchCoat>& getAllRepository() { return this->repo.getAll(); }

	int getSizeRepository() { return this->repo.getSize(); }
	// Returns the size of the repository.

	void writeToFile() { this->repo.writeToFile(); }
	void readFromFile() { this->repo.readFromFile(); }

	void displayPlayList() { return this->basket->executeThings(); }
};