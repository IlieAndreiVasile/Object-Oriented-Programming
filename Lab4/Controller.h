#pragma once
#include "Repository.h"

typedef struct
{
	CountryRepo* repo;
} Controller;

Controller *createController(CountryRepo* r);
/// Creates a controller.
void destroyController(Controller* p);

int addCountry(Controller* p, char* name, char* continent, double population);
/// Adds a country to the repository of countries.

int deleteCountry(Controller* p, char* name, char* continent, double population);
/// Deletes a country from the repository of countries.

int updateCountry(Controller* p, char* name, char* continent, double population);
/// Updates a country in the repository of countries.

int migrationUpdateC(Controller* p, char* name1, char* name2, char* continent1, char* continent2, double population);
/// Perform a migration of population from one country to another in the repository of countries.

CountryRepo* getRepo(Controller* p);

CountryRepo* filterByName(Controller* p, char name[]);
/// Returns the countries containing the given string.

CountryRepo* filterByContinentAndPopulation(Controller* p, char continent[], double population);
/// Returns the countries from a continent which contain a given string whose population is larger than the given number.

CountryRepo* filterByContinent(Controller* p, char continent[]);
/// Returns the countries containing the given string.

//CountryRepo* filterByPopulation(Controller* p, double x);
///// Returns the countries whose population is larger than the given number.

void sortByName(Controller* c);
/// Sorts the repository alphabetically.

void sortByPopulationAsc(Controller* c);
/// Sorts the repository ascending by population.

void sortByPopulationDesc(Controller* c);
/// Sorts the repository descending by population.