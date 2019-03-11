#include "Repository.h"
#include <string>


using namespace std;

int Repository::find(TrenchCoat x)
{
	TrenchCoat* v = this->trenchcoats.getAllElems();

	for (int i = 0; i < this->trenchcoats.getSize(); i++)
	{
		TrenchCoat y = v[i];
		if (x.getSize() == y.getSize() && x.getColour() == y.getColour())
			return i;
	}
	return -1;
}

bool Repository::add(TrenchCoat x)
{
	if (this->find(x) != -1)
		return false;

	/*this->trenchcoats.add(x);*/

	this->trenchcoats = this->trenchcoats + x;
	return true;
}

bool Repository::del(TrenchCoat x)
{
	int pos = this->find(x);
	if (pos == -1)
		return false;

	//this->trenchcoats.del(pos);

	this->trenchcoats - x;
	return true;
}

bool Repository::update(TrenchCoat x, TrenchCoat y)
{
	if (this->find(x) == -1)
		return false;
	this->del(x);
	this->add(y);
	return true;
}

void Repository::print()
{
	TrenchCoat* v = this->trenchcoats.getAllElems();

	for (int i = 0; i < this->trenchcoats.getSize(); i++) {
		TrenchCoat x = v[i];
		x.printTrenchCoat();
	}
}

TrenchCoat* Repository::getAll()
{
	return this->trenchcoats.getAllElems();
}

int Repository::getSize()
{
	return this->trenchcoats.getSize();
}