#pragma once
#include "TrenchCoat.h"
#include <vector>
#include <fstream>
#include <string>

class ShopBasket
{
protected:
	std::vector <TrenchCoat> v;	
	int sum;

public:
	ShopBasket() : sum(0) {}
	// Constructor

	void add(TrenchCoat x);
	// Adds a trench coat to the shopbasket.

	void print();
	// Prints the trench coats from shopbasket.

	int getSum();
	// Returns the total price of the shopbasket.

	virtual void writeToFile() = 0;
	virtual void executeThings() = 0;
};