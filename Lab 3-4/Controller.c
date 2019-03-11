#include "Controller.h"
#include <string.h>

Controller createController(CountryRepo * r)
{
	Controller p;
	p.repo = r;

	return p;
}

int addCountry(Controller* p, char name[], char continent[], double population)
{
	Country c = createCountry(name, continent, population);
	int res = add(p->repo, c);
	return res;
}

int deleteCountry(Controller* p, char name[], char continent[], double population)
{
	Country c = createCountry(name, continent, population);
	int res = delete(p->repo, c);
	return res;
}

int updateCountry(Controller* p, char name[], char continent[], double population)
{
	Country c = createCountry(name, continent, population);
	int res = update(p->repo, c);
	return res;
}

CountryRepo* getRepo(Controller* p)
{
	return p->repo;
}

CountryRepo filterByName(Controller* p, char name[])
{
	CountryRepo res = createRepo();
	if (strcmp(name, "null") == 0)
	{
		return *(p->repo);
	}

	for (int i = 0; i < getLength(p->repo); i++)
	{
		Country c = *getCountryOnPos(p->repo, i);
		if (strstr(getName(&c), name) != NULL)
			add(&res, c);
	}

	return res;
}