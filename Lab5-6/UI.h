#pragma once
#include "Controller.h"
#include "DynamicVector.h"
#include <iostream>

using namespace std;

class UI
{
private:
	Controller ctrl;
	int readInteger(const char* message);
public:
	UI(const Controller& c) : ctrl(c) {}
	static void printMenu();
	static void printAdministratorMenu();
	static void printUserMenu();

	void readTrenchCoat(int &size, string &colour, int &price, int &quantity, string &photograph);
	bool addToRepository();
	bool deleteFromRepository();
	bool updateFromRepository();
	void buy(int size);
	void run();
};
