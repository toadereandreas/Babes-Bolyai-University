#include "PlanetRepository.h"
#include <stdlib.h>
#include <string.h>
#include <assert.h>

PlanetRepo createRepo()
{
	PlanetRepo v;
	v.length = 0;

	return v;
}

int find(PlanetRepo* v, char name[])
{
	// TODO
	return 0;
}

int add(PlanetRepo* v, Planet p)
{
	// first search for a planet with the same symbol as the one that is to be added and do not add it if it already exists
	// function "find" can be used
	// TODO
	
	v->planets[v->length] = p;
	v->length++;

	return 1;
}

int getLength(PlanetRepo* v)
{
	return v->length;
}

Planet getPlanetOnPos(PlanetRepo* v, int pos)
{
	// TODO
}


// Tests
void initPlanetRepoForTests(PlanetRepo* v)
{
	Planet p = createPlanet("Wolf 1061 c", "terrestrial", 13.8);
	add(v, p);
}

void testAdd()
{
	Planet p = createPlanet("Proxima Centauri b", "terrestrial", 4.2);

	PlanetRepo v = createRepo();
	initPlanetRepoForTests(&v);
	assert(getLength(&v) == 1);

	assert(add(&v, p) == 1);
	assert(getLength(&v) == 2);

	// now try to add the same planet again -> add must return 0
	assert(add(&v, p) == 0);
}

void testsPlanetRepo()
{
	testAdd();
}