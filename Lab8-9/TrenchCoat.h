#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <sstream>

class TrenchCoat
{
private:
	int size;
	std::string colour;
	int price;
	int quantity;
	std::string photograph;

public:
	TrenchCoat();		//default constructor
	//TrenchCoat() : size(0), colour(""), price(0), quantity(0), photograph("") {};		// default constructor for a trench coat
	TrenchCoat(int size, const std::string& colour, int price, int quantity, const std::string& photograph);		// constructor with parameters

	int getSize() const { return size; }
	std::string getColour() const { return colour; }
	int getPrice() const { return price; }
	int getQuantity() const { return quantity; }
	std::string getPhotograph() const { return photograph; }

	void set_size(int s) { size = s; }
	void set_color(std::string c) { colour = c; }
	void set_price(int p) { price = p; }
	void setQuantity(int q) { quantity = q; }
	void setPhotograph(std::string ph) { photograph = ph; }

	void printTrenchCoat();
	void displayPhotograph();

	bool operator==(TrenchCoat x);

	TrenchCoat(const TrenchCoat& x);

	friend std::istream& operator>>(std::istream & is, TrenchCoat & x);
	friend std::ostream& operator<<(std::ostream & os, TrenchCoat & x);
};