#include "Repository.h"
#include <stddef.h>
#include <string.h>
#include <assert.h>

CountryRepo* createRepo()
{
	CountryRepo* v = (CountryRepo*)malloc(sizeof(CountryRepo));
	v->countries = (Country*)malloc(100 * sizeof(Country));
	v->length = 0;

	return v;
}

void destroyRepo(CountryRepo* v)
{
	// first destroy all the countries in the repository
	for (int i = 0; i < v->length; i++)
		destroyCountry(v->countries[i]);
	free(v->countries);
	free(v);

}

Country* find(CountryRepo* v, char* name)
{
	for (int i = 0; i < v->length; i++)
	{
		if (strcmp(v->countries[i]->name, name) == 0)
			return v->countries[i];
	}
	return NULL;
}

int add(CountryRepo* v, Country* c)
{
	if (find(v, c->name) != NULL)
		return 0;

	v->countries[v->length] = c;
	v->length++;
	return 1;
}

int deleteC(CountryRepo* v, Country* c)
{
	int position = -1;
	if (find(v, c->name) != NULL)
	{
		for (int i = 0; i < v->length; i++)
		{
			if (strcmp(v->countries[i]->name, c->name) == 0)
			{
				position = i;
			}
		}
		destroyCountry(v->countries[position]);
		for (int i = position; i < v->length - 1; i++)
		{
			v->countries[i] = v->countries[i + 1];
		}
		v->length = v->length - 1;
		return 1;
	}
	return 0;
}

int migrationUpdate(CountryRepo* v, Country* c1, Country* c2, double mpopulation)
{
	int position1 = -1, position2 = -1;
	if (find(v, c1->name) != NULL && find(v, c2->name) != NULL)
	{
		for (int i = 0; i < v->length; i++)
		{
			if (strcmp(v->countries[i]->name, c1->name) == 0)
			{
				v->countries[i]->population -= mpopulation;
			}
			else if(strcmp(v->countries[i]->name, c2->name) == 0)
			{
				v->countries[i]->population += mpopulation;
			}
		}
		return 1;
	}
	return 0;
}

int getLength(CountryRepo* v)
{
	return v->length;
}

Country* getCountryOnPos(CountryRepo* v, int pos)
{
	if (pos < 0 || pos >= v->length)
		return NULL;
	return v->countries[pos];
}

void sortRepoName(CountryRepo* v)
{
	Country* aux;
	for (int i = 0; i < v->length - 1; i++)
	{
		for (int j = i + 1; j < v->length; j++)
		{
			if (strcmp(v->countries[i]->name, v->countries[j]->name)>0)
			{
				aux = v->countries[i];
				v->countries[i] = v->countries[j];
				v->countries[j] = aux;
			}
		}
	}
}

void sortRepoPopulationDesc(CountryRepo* v)
{
	Country* aux;
	for (int i = 0; i < v->length - 1; i++)
	{
		for (int j = i + 1; j < v->length; j++)
		{
			if (v->countries[i]->population < v->countries[j]->population)
			{
				aux = v->countries[i];
				v->countries[i] = v->countries[j];
				v->countries[j] = aux;
			}
		}
	}
}

void sortRepoPopulationAsc(CountryRepo* v)
{
	Country* aux;
	for (int i = 0; i < v->length - 1; i++)
	{
		for (int j = i + 1; j < v->length; j++)
		{
			if (v->countries[i]->population > v->countries[j]->population)
			{
				aux = v->countries[i];
				v->countries[i] = v->countries[j];
				v->countries[j] = aux;
			}
		}
	}
}


//Tests:
void initCountryRepoForTests(CountryRepo* v)
{
	Country* c = createCountry("Italy", "Europe", 59.83);
	add(v, c);
}

void testAdd()
{
	Country* c = createCountry("Portugal", "Europe", 10.34);

	CountryRepo* v = createRepo();
	initCountryRepoForTests(v);
	assert(getLength(v) == 1);

	// we try to add a new country
	assert(add(v, c) == 1);
	assert(getLength(v) == 2);

	// we try to add a country that already exists
	assert(add(v, c) == 0);
	assert(getLength(v) == 2);

	// destroy the test repository
	destroyRepo(v);
}

void testDeleteC()
{
	Country* c = createCountry("Portugal", "Europe", 10.34);

	CountryRepo* v = createRepo();
	initCountryRepoForTests(v);
	assert(getLength(v) == 1);
	assert(add(v, c) == 1);

	// we try to delete a country that exists
	assert(deleteC(v, c) == 1);
	assert(getLength(v) == 1);

	// destroy the test repository
	destroyRepo(v);

}

void testsCountryRepo()
{
	testAdd();
	testDeleteC();
}