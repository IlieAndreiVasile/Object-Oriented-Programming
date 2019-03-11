#include "Country.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

Country* createCountry(char* name, char* continent, double population)
{
	Country* c = (Country*)malloc(sizeof(Country));
	c->name = (char*)malloc(strlen(name) + 1);
	strcpy(c->name, name);
	c->continent = (char*)malloc(strlen(continent) + 1);
	strcpy(c->continent, continent);
	c->population = population;

	return c;
}

void destroyCountry(Country* c)
{
	// free the memory which was allocated for the component fields
	free(c->name);
	free(c->continent);

	// free the memory which was allocated for the country structure
	free(c);
}

char* getName(Country* c)
{
	return c->name;
}

char* getContinent(Country* c)
{
	return c->continent;
}

double getPopulation(Country* c)
{
	return c->population;
}

void toString(Country* c, char str[])
{
	sprintf(str, "%s belongs to %s and has a population of %.2lf millions of people.", c->name, c->continent, c->population);
}