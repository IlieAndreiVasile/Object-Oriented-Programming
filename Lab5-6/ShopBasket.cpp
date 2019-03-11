#include "ShopBasket.h"


ShopBasket::ShopBasket() : sum(0) {}

void ShopBasket::add(TrenchCoat x)
{
	this->trenchcoats.add(x);
	this->sum += x.getPrice();
}

void ShopBasket::print()
{
	if (this->trenchcoats.getSize() == 0)
		return;

	TrenchCoat* v = this->trenchcoats.getAllElems();

	for (int i = 0; i < this->trenchcoats.getSize(); i++)
	{
		std::cout << "Size: " << v[i].getSize() << " Colour: " << v[i].getColour() << " Price: " << v[i].getPrice() << std::endl;
	}
}

int ShopBasket::getSum()
{
	return this->sum;
}
