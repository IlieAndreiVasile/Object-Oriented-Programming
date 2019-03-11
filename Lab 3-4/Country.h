#pragma once

typedef struct
{
	char name[30];
	char continent[20];
	double population;
} Country;

Country createCountry(char name[], char continent[], double population);
char* getName(Country* c);
char* getContinent(Country* c);
double getPopulation(Country* c);

void toString(Country c, char str[]);