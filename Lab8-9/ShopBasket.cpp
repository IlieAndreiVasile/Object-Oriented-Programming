#include "ShopBasket.h"


using namespace std;

void ShopBasket::add(TrenchCoat x)
{
	this->v.push_back(x);
	this->sum += x.getPrice();
}

void ShopBasket::print()
{
	for (auto it : this->v)
		cout << "Size: " << it.getSize() << " Colour: " << it.getColour() << " Price: " << it.getPrice() << endl;
}

int ShopBasket::getSum()
{
	return this->sum;
}