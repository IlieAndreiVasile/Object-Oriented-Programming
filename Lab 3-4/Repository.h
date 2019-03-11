#pragma once
#include "Country.h"

typedef struct
{
	Country countries[100];
	int length;
} CountryRepo;

CountryRepo createRepo();
/// Creates a CountryRepo.

int find(CountryRepo* v, char name[]);
/// Finds the country with the given string.

int add(CountryRepo* v, Country c);
/*
	Adds a country to the repository of countries.
	Input:	- v - pointer to the CountryRepo
			- c - country
	Output: 1 - if the country was sucessfully added
			0 - if the country could not be added, as another country with the same name already exists in the CountryRepo.
*/

int delete(CountryRepo* v, Country c);
/*
	Deletes a country to the repository of countries.
	Input:	- v - pointer to the CountryRepo
			- c - country
	Output: 1 - if the country was sucessfully deleted
			0 - if the country could not be deleted because it does not exists.
*/

int update(CountryRepo* v, Country c);
/*
	Updates a country to the repository of countries.
	Input:	- v - pointer to the CountryRepo
			- c - country
	Output: 1 - if the country was sucessfully updated
			0 - if the country could not be updated because it does not exists.
*/

int getLength(CountryRepo* v);

/*
	Returns the country on the given position in the country vector.
	Input:	v - the country repository;
	pos - integer, the position;
	Output: the country on the given potision, or an "empty" country.
*/
Country *getCountryOnPos(CountryRepo* v, int pos);

void testsCountryRepo();