#include "Controller.h"


bool Controller::addToRepository(TrenchCoat x)
{
	return this->repo.add(x);
}

bool Controller::deleteFromRepository(TrenchCoat x)
{
	return this->repo.del(x);
}

bool Controller::updateFromRepository(TrenchCoat x, TrenchCoat y)
{
	return this->repo.update(x, y);
}

void Controller::printRepository()
{
	return this->repo.print();
}

void Controller::addToShopBasket(TrenchCoat x)
{
	this->shopbasket.add(x);
}

void Controller::printShopBasket()
{
	this->shopbasket.print();
}

int Controller::getShopBasketSum()
{
	return this->shopbasket.getSum();
}

TrenchCoat* Controller::getAllRepository()
{
	return this->repo.getAll();
}

int Controller::getSizeRepository()
{
	return this->repo.getSize();
}
