#pragma once
#include "TrenchCoat.h"
#include "DynamicVector.h"

class ShopBasket
{
private:
	DynamicVector <TrenchCoat> trenchcoats;		// Dynamic array for repository of shopbasket
	int sum;

public:
	ShopBasket();
	// Constructor

	void add(TrenchCoat x);
	// Adds a trench coat to the shopbasket.

	void print();
	// Prints the trench coats from shopbasket.

	int getSum();
	// Returns the total price of the shopbasket.
};