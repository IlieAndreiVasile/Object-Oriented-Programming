#pragma once

typedef struct
{
	char* name;
	char* continent;
	double population;
} Country;

Country* createCountry(char* name, char* continent, double population);
void destroyCountry(Country* c); //the memory is freed

char *getName(Country* c);
char *getContinent(Country* c);
double getPopulation(Country* c);

void toString(Country* c, char str[]);