#include "Controller.h"


using namespace std;

void Controller::addToRepository(int size, const std::string& colour, int price, int quantity, const std::string& photograph)
{
	TrenchCoat x{ size, colour, price, quantity, photograph };
	this->validator.validate(x);
	this->repo.add(x);
}

void Controller::deleteFromRepository(int size, const std::string& colour, int price, int quantity, const std::string& photograph)
{
	TrenchCoat x{ size, colour, price, quantity, photograph };
	this->repo.del(x);
}

void Controller::updateFromRepository(int size, const std::string& colour, int price, int quantity, const std::string& photograph)
{
	TrenchCoat x{ size, colour, price, quantity, photograph };
	this->repo.update(x);
}

