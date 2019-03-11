#include "Country.h"
#include <string.h>
#include <stdio.h>

Country createCountry(char name[], char continent[], double population)
{
	Country c;
	strcpy(c.name, name);
	strcpy(c.continent, continent);
	c.population = population;

	return c;
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

void toString(Country c, char str[])
{
	sprintf(str, "%s belongs to %s and has a population of %.2lf millions of people.", c.name, c.continent, c.population);
}