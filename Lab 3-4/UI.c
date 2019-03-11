#include "UI.h"
#include <stdio.h>

UI createUI(Controller* p)
{
	UI ui;
	ui.ctrl = p;

	return ui;
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
	printf("\t \t \t 4 - list all countries.\n");
	printf("\t \t \t 5 - list countries with a given string.\n");
	printf("\t \t \t 0 - to exit.\n");
}

int validCommand(int command)
/*
	Verifies if the given command is valid (is either 1, 2, 3, 4, 5 or 0)
	Input: command - integer
	Output: 1 - if the command is valid
			0 - otherwise
*/
{
	if (command >= 0 && command <= 5)
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
	char name[30], continent[20];
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
	char name[30], continent[20];
	double population;

	printf("Please input the name: ");
	scanf("%29s", name);

	return deleteCountry(ui->ctrl, name, "", 0);
}

int updateCountryUI(UI* ui)
{
	char name[30], continent[20];
	double population;

	printf("Please input the name: ");
	scanf("%29s", name);
	printf("Please input the continent: ");
	scanf("%19s", continent);
	printf("Please input the population: ");
	scanf("%lf", &population);

	return updateCountry(ui->ctrl, name, continent, population);
}

void listAllCountries(UI* ui)
{
	CountryRepo* repo = getRepo(ui->ctrl);
	int length = getLength(repo);

	if (length == 0)
	{
		char* str = "There are no stored countries.";
		printf("%s \n", str);
	}

	for (int i = 0; i < getLength(repo); i++)
	{
		char str[200];
		toString(*getCountryOnPos(repo, i), str);
		printf("%s\n", str);
	}
}

void listCountriesWithName(UI* ui)
{
	char name[30];
	printf("Please input the string (must contain maximum 29 letters); input 'null' for no name combination: ");
	scanf("%29s", name);

	CountryRepo res = filterByName(ui->ctrl, name);
	int length = getLength(&res);
	if (length == 0)
	{
		printf("There are no countries with the given string.");
	}
	else
	{
		for (int i = 0; i < getLength(&res) - 1; i++)
		{
			Country *c1 = getCountryOnPos(&res, i);
			for (int j = i + 1; j < getLength(&res); j++)
			{
				Country *c2 = getCountryOnPos(&res, j);
				if (c1->population < c2->population)
				{
					Country aux = createCountry("", "", 0);
					aux = *c1;
					*c1 = *c2;
					*c2 = aux;
				}
			}
		}
		printf("\n");
		for (int i = 0; i < length; i++)
		{
			char str[200];
			toString(*getCountryOnPos(&res, i), str);
			printf("%s\n", str);
		}
	}
}

void startUI(UI* ui)
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
				printf("Country successfully added.\n");
			else
				printf("Error! Country could not be added, as there is another country with the same name!\n");
			break;
		}
		case 2:
		{
			int res = deleteCountryUI(ui);
			if (res == 1)
				printf("Country successfully deleted.\n");
			else
				printf("Error! Country could not be deleted because it does not exists!\n");
			break;
		}
		case 3:
		{
			int res = updateCountryUI(ui);
			if (res == 1)
				printf("Country successfully updated.\n");
			else
				printf("Error! Country could not be updateed because it does not exists!\n");
			break;
		}
		case 4:
		{
			listAllCountries(ui);
			break;
		}
		case 5:
		{
			listCountriesWithName(ui);
			break;
		}
		}
	}
}