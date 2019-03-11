#include "Repository.h"


using namespace std;

int Repository::find(const TrenchCoat& x)
{
	for (int i = 0; i < this->v.size(); i++)
	{
		if (v[i] == x)
			return i;
	}
	return -1;
}

void Repository::add(const TrenchCoat& x)
{
	if (this->find(x) == -1)
		this->v.push_back(x);
	else
		try
	{
		throw DuplicateTrenchCoatException();
	}
	catch (InexistentTrenchCoatException& e) {}
}

void Repository::del(const TrenchCoat& x)
{
	int pos = this->find(x);
	if (pos == -1)
		this->v.erase(v.begin() + pos);
	else
		throw InexistentTrenchCoatException{};
}

void Repository::update(const TrenchCoat& x)
{
	if (this->find(x) != -1)
	{
		this->del(x);
		this->add(x);
	}
	else
		throw InexistentTrenchCoatException{};
}

void Repository::print()
{
	for (auto it : v)
		it.printTrenchCoat();
}

std::vector<TrenchCoat>& Repository::getAll()
{
	return this->v;
}

int Repository::getSize()
{
	return this->v.size();
}

void Repository::writeToFile()
{
	std::ofstream fout("TrenchCoats.txt");

	if (!fout.is_open())
		throw FileException("The file could not be opened!");

	for (auto it : this->v)
		fout << it;
	fout.close();
}

void Repository::readFromFile()
{
	std::ifstream fin("TrenchCoats.txt");

	if (!fin.is_open())
		throw FileException("The file could not be opened!");

	TrenchCoat x;
	while (fin >> x)
		this->v.push_back(x);
	fin.close();
}