#include "TrenchCoat.h"
#include <Windows.h>
#include <shellapi.h>

using namespace std;

TrenchCoat::TrenchCoat() : size(0), colour(""), price(0), quantity(0), photograph("")
{
}

TrenchCoat::TrenchCoat(int size, const std::string& colour, int price, int quantity, const std::string& photograph)
{
	this->size = size;
	this->colour = colour;
	this->price = price;
	this->quantity = quantity;
	this->photograph = photograph;
}

void TrenchCoat::printTrenchCoat()
{
	std::cout << "Size: " << this->size << ", Colour: " << this->colour << ", Price: " << this->price << ", Quantity: " << this->quantity << std::endl;
}

void TrenchCoat::displayPhotograph()
{
	ShellExecuteA(NULL, NULL, "chrome.exe", this->getPhotograph().c_str(), NULL, SW_SHOWMAXIMIZED);
}

bool TrenchCoat::operator==(TrenchCoat x)
{
	if (this->colour == x.getColour() && this->size == x.getSize())
		return true;
	return false;
}

TrenchCoat::TrenchCoat(const TrenchCoat& x)
{
	this->size = x.size;
	this->colour = x.colour;
	this->price = x.price;
	this->quantity = x.quantity;
	this->photograph = x.photograph;
}

vector<string> tokenize(string s, char del)
{
	stringstream ss(s);
	string aux;
	vector<string> res;
	while (getline(ss, aux, del))
		res.push_back(aux);
	return res;
}

istream& operator>>(istream & is, TrenchCoat & x)
{
	std::string s;
	getline(is, s);

	vector<string> rez = tokenize(s, ',');
	if (rez.size() != 5)
		return is;
	x.size = atoi(rez[0].c_str());
	x.colour = rez[1];
	x.price = atoi(rez[2].c_str());
	x.quantity = atoi(rez[3].c_str());
	x.photograph = rez[4];

	return is;
}

ostream& operator<<(ostream & os, TrenchCoat & x)
{
	os << x.size << "," << x.colour << "," << x.price << "," << x.quantity << "," << x.photograph << '\n';
	return os;
}