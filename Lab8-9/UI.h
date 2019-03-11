#pragma once
#include "Controller.h"
#include "TrenchCoatValidator.h"
#include "Exceptions.h"
#include <iostream>

using namespace std;

class UI
{
private:
	Controller ctrl;
	static void printMenu();
	static void printAdministratorMenu();
	static void printUserMenu();

	void addToRepository();
	void deleteFromRepository();
	void updateFromRepository();
	void buy(int size);

	void displayPlayListUI() { return this->ctrl.displayPlayList(); }

public:
	UI(const Controller& c) : ctrl(c) {}
	void run();
};