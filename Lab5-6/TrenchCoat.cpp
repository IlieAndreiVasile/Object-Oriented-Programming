#include "TrenchCoat.h"
#include <Windows.h>
#include <shellapi.h>


//TrenchCoat::TrenchCoat() : size(0), colour(""), price(0), quantity(0), photograph("") {}

TrenchCoat::TrenchCoat(int size, const std::string& colour, int price, int quantity, const std::string& photograph)
{
	this->size = size;
	this->colour = colour;
	this->price = price;
	this->quantity = quantity;
	this->photograph = photograph;
}

TrenchCoat::TrenchCoat(TrenchCoat& x) {
	this->size = x.size;
	this->colour = x.colour;
	this->price = x.price;
	this->quantity = x.quantity;
	this->photograph = x.photograph;
}

void TrenchCoat::printTrenchCoat()
{
	std::cout << "Size: " << this->size << ", Colour: " << this->colour << ", Price: " << this->price << ", Quantity: " << this->quantity << std::endl;
}

void TrenchCoat::display()
{
	ShellExecuteA(NULL, NULL, "chrome.exe", this->getPhotograph().c_str(), NULL, SW_SHOWMAXIMIZED);
}