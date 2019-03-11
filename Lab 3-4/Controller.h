#pragma once
#include "Repository.h"

typedef struct
{
	CountryRepo* repo;
} Controller;

Controller createController(CountryRepo* r);
/// Creates a controller.

int addCountry(Controller* p, char name[], char continent[], double population);
/// Adds a country to the repository of countries.

int deleteCountry(Controller* p, char name[], char continent[], double population);
/// Deletes a country from the repository of countries.

int updateCountry(Controller* p, char name[], char continent[], double population);
/// Updates a country in the repository of countries.

CountryRepo* getRepo(Controller* p);

CountryRepo filterByName(Controller* p, char name[]);
/// Returns the countries containing the given string.