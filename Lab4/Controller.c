#include "Controller.h"
#include <string.h>

Controller* createController(CountryRepo* r)
{
	Controller* p = (Controller*)malloc(sizeof(Controller));
	p->repo = r;
	return p;
}

void destroyController(Controller* p)
{
	// first destroy the repository inside
	destroyRepo(p->repo);
	// then free the memory
	free(p);
}

int addCountry(Controller* p, char* name, char* continent, double population)
{
	Country* c = createCountry(name, continent, population);
	int res = add(p->repo, c);
	if (res == 0)
		destroyCountry(c);
	return res;
}

int deleteCountry(Controller* p, char* name, char* continent, double population)
{
	Country* c = createCountry(name, continent, population);
	int res = deleteC(p->repo, c);
	destroyCountry(c);
	return res;
}

int updateCountry(Controller* p, char* name, char* continent, double population)
{
	Country* c = createCountry(name, continent, population);
	int res1 = deleteC(p->repo, c);
	int res2 = 0;
	if (res1 == 1)
		res2 = add(p->repo, c);
	if (res1 == 0)
		destroyCountry(c);
	return res2;
}

int migrationUpdateC(Controller* p, char* name1, char* name2, char* continent1, char* continent2, double population)
{
	Country* c1 = createCountry(name1, continent1, population);
	Country* c2 = createCountry(name2, continent2, population);
	int res = migrationUpdate(p->repo, c1, c2, population);
	destroyCountry(c1);
	destroyCountry(c2);
	return res;
}

CountryRepo* getRepo(Controller *p)
{
	return p->repo;
}

CountryRepo* filterByName(Controller* p, char name[])
{
	CountryRepo* res = createRepo();
	if (strcmp(name, "null") == 0)
	{
		for (int i = 0; i < getLength(p->repo); i++)
		{
			Country *c = getCountryOnPos(p->repo, i);
			Country *newCountry = createCountry(c->name, c->continent, c->population);
			add(res, newCountry);
		}
		return res;
	}
	for (int i = 0; i < getLength(p->repo); i++)
	{
		Country *c = getCountryOnPos(p->repo, i);
		if (strstr(getName(c), name) != NULL)
		{
			Country *newCountry = createCountry(c->name, c->continent, c->population);
			add(res, newCountry);
		}
	}

	return res;
}

CountryRepo* filterByContinentAndPopulation(Controller* p, char continent[], double population)
{
	CountryRepo* res = createRepo();
	for (int i = 0; i < getLength(p->repo); i++)
	{
		Country* c = getCountryOnPos(p->repo, i);
		if (strstr(getContinent(c), continent) != NULL && getPopulation(c) > population)
		{
			Country* newCountry = createCountry(c->name, c->continent, c->population);
			add(res, newCountry);
		}
	}
	return res;
}

CountryRepo* filterByContinent(Controller* p, char continent[])
{
	CountryRepo* res = createRepo();
	if (strcmp(continent, "null") == 0)
	{
		for (int i = 0; i < getLength(p->repo); i++)
		{
			Country* c = getCountryOnPos(p->repo, i);
			Country* newCountry = createCountry(c->name, c->continent, c->population);
			add(res, newCountry);
		}
		return res;
	}

	for (int i = 0; i < getLength(p->repo); i++)
	{
		Country* c = getCountryOnPos(p->repo, i);
		if (strstr(getContinent(c), continent) != NULL)
		{
			Country* newCountry = createCountry(c->name, c->continent, c->population);
			add(res, newCountry);
		}
	}
	return res;
}

//CountryRepo* filterByPopulation(Controller* p, double x)
//{
//	CountryRepo* res = createRepo();
//
//	for (int i = 0; i < getLength(p->repo); i++)
//	{
//		Country* c = getCountryOnPos(p->repo, i);
//		if (c->population > x)
//		{
//			Country* newCountry = createCountry(c->name, c->continent, c->population);
//			add(res, newCountry);
//		}
//	}
//	return res;
//}

void sortByName(Controller* c)
{
	sortRepoName(c->repo);
}

void sortByPopulationAsc(Controller* c)
{
	sortRepoPopulationAsc(c->repo);
}

void sortByPopulationDesc(Controller* c)
{
	sortRepoPopulationDesc(c->repo);
}