#include "Repository.h"
#include <stddef.h>
#include <string.h>
#include <assert.h>

CountryRepo createRepo()
{
	CountryRepo v;
	v.length = 0;

	return v;
}

int find(CountryRepo* v, char name[])
{
	Country* c = NULL;

	for (int i = 0; i < v->length; i++)
	{
		if (strcmp(v->countries[i].name, name) == 0)
			return i;
	}
	return -1;
}

int add(CountryRepo* v, Country c)
{
	if (find(v, c.name) != -1)
		return 0;
	v->countries[v->length] = c;
	v->length++;

	return 1;
}

int delete(CountryRepo* v, Country c)
{
	if (find(v, c.name) != -1)
	{
		int pos = find(v, c.name);
		for (int i = pos; i < getLength(v); i++)
			v->countries[i] = v->countries[i + 1];
		v->length = v->length - 1;
		return 1;
	}
	return 0;
}

int update(CountryRepo* v, Country c)
{
	if (find(v, c.name) != -1)
	{
		v->countries[find(v, c.name)] = c;
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
	if (pos < 0 || pos > v->length)
		return NULL;
	return &(*v).countries[pos];
}


//Tests:
void initCountryRepoForTests(CountryRepo* v)
{
	Country  c = createCountry("Italy", "Europe", 59.83);
	add(v, c);
}

void testAdd()
{
	Country c = createCountry("Portugal", "Europe", 10.34);

	CountryRepo v = createRepo();
	initCountryRepoForTests(&v);
	assert(getLength(&v) == 1);

	// we try to add a new country
	assert(add(&v, c) == 1);
	assert(getLength(&v) == 2);

	// we try to add a country that already exists
	assert(add(&v, c) == 0);
	assert(getLength(&v) == 2);
}

void testDelete()
{
	Country c = createCountry("Portugal", "Europe", 10.34);

	CountryRepo v = createRepo();
	initCountryRepoForTests(&v);
	assert(getLength(&v) == 1);
	assert(add(&v, c) == 1);

	// we try to delete a country that exists
	assert(delete(&v, c) == 1);
	assert(getLength(&v) == 1);

	// we try to delete a country that does not exists

}

void testUpdate()
{
	Country c = createCountry("Portugal", "Europe", 10.34);

	CountryRepo v = createRepo();
	initCountryRepoForTests(&v);
	assert(getLength(&v) == 1);
	assert(add(&v, c) == 1);

	// we try to update a country that exists
	assert(update(&v, c) == 1);
	assert(getLength(&v) == 2);

	// we try to update a country that does not exists

}

void testCountryRepo()
{
	testAdd();
	testDelete();
	testUpdate();
}