#pragma once
#include <iostream>
#include <string>

class TrenchCoat
{
private:
	int size;
	std::string colour;
	int price;
	int quantity;
	std::string photograph;

public:
	//TrenchCoat();	// default constructor for a trench coat

	TrenchCoat() : size(0), colour(""), price(0), quantity(0), photograph("") {};		// default constructor for a trench coat

	TrenchCoat(TrenchCoat& x);

	// constructor with parameters
	TrenchCoat(int size, const std::string&, int price, int quantity, const std::string&);

	int getSize() { return size; }
	std::string getColour() { return colour; }
	int getPrice() { return price; }
	int getQuantity() { return quantity; }
	std::string getPhotograph() { return photograph; }

	void set_size(int s) { size = s; }
	void set_color(std::string c) { colour = c; }
	void set_price(int p) { price = p; }
	void setQuantity(int q) { quantity = q; }
	void setPhotograph(std::string ph) { photograph = ph; }

	void printTrenchCoat();
	void display();
};