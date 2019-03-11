#include "UI.h"
#include <stdio.h>
#include "UndoController.h"

UI *createUI(Controller *p)
{
	UI *ui = (UI*)malloc(sizeof(UI));
	ui->ctrl = p;

	return ui;
}

void destroyUI(UI *ui)
{
	destroyController(ui->ctrl);
	free(ui);
}

void printMenu()
/*
Prints the available menu for the problem
Input: -
Output: the menu is printed at the console
*/
{
	printf("\n \n \t \t \t \t MENU: \n");
	printf("\t \t \t 1 - add a country.\n");
	printf("\t \t \t 2 - delete a country.\n");
	printf("\t \t \t 3 - update a country.\n");
	printf("\t \t \t 4 - migration from one country to another.\n");
	printf("\t \t \t 5 - list all countries.\n");
	printf("\t \t \t 6 - list countries with a given string.\n");
	printf("\t \t \t 7 - list countries on a given continent whose populations are greater than a given value,\t\t\t\t\t sorted ascending by population.\n");
	printf("\t \t \t 8 - list countries on a given continent, sorted ascending by name.\n");
	printf("\t \t \t 9 - list countries on a given continent, sorted descending by population.\n");
	printf("\t \t \t 10 - to undo.\n");
	printf("\t \t \t 11 - to redo.\n");
	printf("\t \t \t 0 - to exit.\n");
}

int validCommand(int command)
/*
Verifies if the given command is valid (is either 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11 or 0)
Input: command - integer
Output: 1 - if the command is valid
		0 - otherwise
*/
{
	if (command >= 0 && command <= 11)
		return 1;
	return 0;
}

int readIntegerNumber(const char* message)
/*
Reads an integer number from the keyboard. Asks for number while read errors encoutered.
Input: the message to be displayed when asking the user for input.
Returns the number.
*/
{
	char s[16];
	int res = 0;
	int flag = 0;
	int r = 0;

	while (flag == 0)
	{
		printf(message);
		scanf("%s", s);

		r = sscanf(s, "%d", &res);	// reads data from s and stores them as integer, if possible; returns 1 if successful
		flag = (r == 1);
		if (flag == 0)
			printf("Error reading number!\n");
	}
	return res;
}

int addCountryUI(UI* ui)
{
	// read the country's data
	char name[30], continent[15];
	double population;

	printf("Please input the name: ");
	scanf("%29s", name);
	printf("Please input the continent: ");
	scanf("%19s", continent);
	printf("Please input the population: ");
	scanf("%lf", &population);

	return addCountry(ui->ctrl, name, continent, population);
}

int deleteCountryUI(UI* ui)
{
	char name[30];
	printf("Please input the name: ");
	scanf("%29s", name);

	return deleteCountry(ui->ctrl, name, "", 0);
}

int updateCountryUI(UI* ui)
{
	char name[30], continent[15];
	double population;

	printf("Please input the name: ");
	scanf("%29s", name);
	printf("Please input the continent: ");
	scanf("%19s", continent);
	printf("Please input the population: ");
	scanf("%lf", &population);

	return updateCountry(ui->ctrl, name, continent, population);
}

int migrationUpdateUI(UI* ui)
{
	char name1[30], name2[30];
	double population;

	printf("Please input the name of the origin country: ");
	scanf("%29s", name1);
	printf("Please input the name of the destination country: ");
	scanf("%29s", name2);
	printf("Please input the population: ");
	scanf("%lf", &population);

	return migrationUpdateC(ui->ctrl, name1, name2, "", "", population);
}

void listAllCountries(UI* ui)
{
	CountryRepo *repo = getRepo(ui->ctrl);
	int length = getLength(repo);

	if (length == 0)
	{
		 printf("There are no stored countries.");
	}

	for (int i = 0; i < getLength(repo); i++)
	{
		char str[200];
		toString(getCountryOnPos(repo, i), str);
		printf("%s\n", str);
	}
}

void listCountriesWithName(UI* ui)
{
	char name[30];
	printf("Please input the string (must contain maximum 29 letters); input 'null' for no name combination: ");
	scanf("%29s", name);

	CountryRepo* res = filterByName(ui->ctrl, name);
	int length = getLength(res);
	if (length == 0)
	{
		printf("There are no countries with the given string.");
	}
	else
	{
		printf("\n");
		for (int i = 0; i < length; i++)
		{
			char str[200];
			toString(getCountryOnPos(res, i), str);
			printf("%s\n", str);
		}
	}
	destroyRepo(res);
}

void listCountriesByPopulationAndContinent(UI* ui)
{
	double population;
	printf("        Population: ");
	scanf("%lf", &population);
	char continent[15];
	printf("        Continent: ");
	scanf("%49s", continent);
	printf("\n");

	CountryRepo* res = filterByContinentAndPopulation(ui->ctrl, continent, population);
	int length = getLength(res);
	if (length == 0)
	{
		printf("\n    There are no countries on this continent.\n");
	}
	else
	{
		for (int i = 0; i < length; i++)
		{
			char str[200];
			toString(getCountryOnPos(res, i), str);
			printf("%s\n", str);
		}
	}
	destroyRepo(res);
}

void listCountriesByContinent(UI* ui)
{
	char continent[15];
	printf("        Continent: ");
	scanf("%49s", continent);
	printf("\n");

	CountryRepo* res = filterByContinent(ui->ctrl, continent);
	int length = getLength(res);
	if (length == 0)
	{
		printf("\n    There are no countries on this continent.\n");
	}
	else
	{
		for (int i = 0; i < length; i++)
		{
			char str[200];
			toString(getCountryOnPos(res, i), str);
			printf("%s\n", str);
		}
	}
	destroyRepo(res);
}

//void listCountriesByPopulation(UI* ui)
//{
//	double population;
//	printf("        Population: ");
//	scanf("%lf", &population);
//	printf("\n");
//
//	CountryRepo* res = filterByPopulation(ui->ctrl, population);
//	int length = getLength(res);
//	if (length == 0)
//	{
//		printf("\n    There are no countries with greater population than the given value on this continent.\n");
//	}
//	else
//	{
//		for (int i = 0; i < length; i++)
//		{
//			char str[200];
//			toString(getCountryOnPos(res, i), str);
//			printf("%s\n", str);
//		}
//	}
//	destroyRepo(res);
//}

void startUI(UI* ui, undoController* undoCtrl)
{
	while (1)
	{
		printMenu();
		int command = readIntegerNumber("Input command: ");
		while (validCommand(command) == 0)
		{
			printf("Please input a valid command!\n");
			command = readIntegerNumber("Input command: ");
		}
		if (command == 0)
			break;
		switch (command)
		{
		case 1:
		{
			int res = addCountryUI(ui);
			if (res == 1)
			{
				printf("Country successfully added.\n");
				newOperation(undoCtrl);
				addList(undoCtrl, ui->ctrl->repo);
			}
			else
				printf("Error! Country could not be added, as there is another country with the same name!\n");
			break;
		}
		case 2:
		{
			int res = deleteCountryUI(ui);
			if (res == 1)
			{
				printf("Country successfully deleted.\n");
				newOperation(undoCtrl);
				addList(undoCtrl, ui->ctrl->repo);
			}
			else
				printf("Error! Country could not be deleted because it does not exists!\n");
			break;
		}
		case 3:
		{
			int res = updateCountryUI(ui);
			if (res == 1)
			{
				printf("Country successfully updated.\n");
				newOperation(undoCtrl);
				addList(undoCtrl, ui->ctrl->repo);
			}
			else
				printf("Error! Country could not be updateed because it does not exists!\n");
			break;
		}
		case 4:
		{
			int res = migrationUpdateUI(ui);
			if (res == 1)
			{
				printf("Countries successfully updated.\n");
				newOperation(undoCtrl);
				addList(undoCtrl, ui->ctrl->repo);
			}
			else
				printf("Error! Countries could not be updateed because they does not exist!\n");
			break;
		}
		case 5:
		{
			listAllCountries(ui);
			break;
		}
		case 6:
		{
			listCountriesWithName(ui);
			break;
		}
		case 7:
		{
			sortByPopulationAsc(ui->ctrl);
			listCountriesByPopulationAndContinent(ui);
			break;
		}
		case 8:
		{
			sortByName(ui->ctrl);
			listCountriesByContinent(ui);
			break;
		}
		case 9:
		{
			sortByPopulationDesc(ui->ctrl);
			listCountriesByContinent(ui);
			break;
		}
		case 10:
		{
			if (checkUndo(undoCtrl) == 1)
			{
				ui->ctrl->repo = undo(undoCtrl, ui->ctrl->repo);
				printf("\n    Undo done!\n");
			}
			else
				printf("\n    Can't undo!\n");
			break;
		}
		case 11:
		{
			if (checkRedo(undoCtrl) == 1)
			{
				ui->ctrl->repo = redo(undoCtrl, ui->ctrl->repo);
				printf("\n    Redo done!\n");
			}
			else
				printf("\n    Can't redo!\n");
			break;
		}
		}
	}
}