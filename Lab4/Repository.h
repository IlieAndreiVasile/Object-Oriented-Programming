#pragma once
#include "Country.h"

typedef struct
{
	Country **countries;
	int length;
} CountryRepo;

CountryRepo* createRepo();
/// Creates a CountryRepo.

void destroyRepo(CountryRepo* v);
/// Destroys a given country repository. The memory is freed.

Country* find(CountryRepo* v, char* name);
/// Finds the country with the given string.

int add(CountryRepo* v, Country* c);
/*
Adds a country to the repository of countries.
Input:	- v - pointer to the CountryRepo
		- c - country
Output: 1 - if the country was sucessfully added.
		0 - if the country could not be added, as another country with the same name already exists in the CountryRepo.
*/

int deleteC(CountryRepo* v, Country* c);
/*
Deletes a country to the repository of countries.
Input:	- v - pointer to the CountryRepo
		- c - country
Output: 1 - if the country was sucessfully deleted.
		0 - if the country could not be deleted because it does not exists.
*/

int migrationUpdate(CountryRepo* v, Country* c1, Country* c2, double mpopulation);
/*
Input: - v - pointer to the CountryRepo
	   - c1 - origin country
	   - c2 - destination  country
	   - mpopulation - migration population
Output: 1 - if the migration was made.
		0 - if the migration could not be done.
*/

int getLength(CountryRepo* v);

Country* getCountryOnPos(CountryRepo* v, int pos);
/*
Returns the country on the given position in the country vector.
Input:	v - the country repository;
		pos - integer, the position;
Output: the country on the given potision, or an "empty" country.
*/

void sortRepoName(CountryRepo* v);
/*
Sorts the repository v, alphabetically.
Input:  v - the CountryRepository;
Output: The repository v, sorted alphabetically.
*/

void sortRepoPopulationDesc(CountryRepo* v);
/*
Sorts the repository v, descending, by population.
Input:  v - the CountryRepository;
Output: The repository v, sorted descending by population.
*/

void sortRepoPopulationAsc(CountryRepo* v);
/*
Sorts the repository v, ascending, by population.
Input:  v - the CountryRepository;
Output: The repository v, sorted ascending by population.
*/

void testsCountryRepo();
/*
Tests the country repo.
*/