#include "PlanetRepository.h"
#include <stdlib.h>
#include <string.h>
#include <assert.h>

PlanetRepo* createRepo()
{
	PlanetRepo* v = (PlanetRepo*)malloc(sizeof(PlanetRepo));
	v->planets = createDynamicArray(CAPACITY);

	return v;
}

void destroyRepo(PlanetRepo* v)
{
	if (v == NULL)
		return;

	// !!! If the dynamic vector takes responsibility of these planets, then the memory can be deallocated in the function "destroy" in DynamicArray.c.
	// Otherwise, the repository should deallocate the memory for the planets.
	/*for (int i = 0; i < getLength(v->planets); i++)
	{
		Planet* p = get(v->planets, i);
		destroyPlanet(p);
	}*/

	// then destroy the dynamic array
	destroy(v->planets);
	free(v);
}

int findPosOfPlanet(PlanetRepo * v, char * name)
{
	// TODO
	return -1;
}

Planet* find(PlanetRepo* v, char* name)
{
	// TODO
	return NULL;
}

int addPlanet(PlanetRepo* v, Planet* p)
{
	if (v == NULL)
		return 0;

	// first search for a planet with the same name as the one that is to be added and do not add it if it already exists
	// function "find"

	// a copy of the planet which was passed will be stored, such that the memory for the planet can be deallocated where it was allocated (in Controller) 
	// and the Repository will handle its own memory
	Planet* copy = copyPlanet(p);
	add(v->planets, copy);

	return 1;
}

void deletePlanet(PlanetRepo* v, char* symbol)
{
	// TODO
}

int getRepoLength(PlanetRepo* v)
{
	if (v == NULL)
		return -1;

	return getLength(v->planets);
}

Planet* getPlanetOnPos(PlanetRepo* v, int pos)
{
	// TODO

	return NULL;
}


// Tests
void testAdd()
{
	PlanetRepo* v = createRepo();

	Planet* p1 = createPlanet("Wolf 1061 c", "terrestrial", 13.8);
	addPlanet(v, p1);
	assert(getRepoLength(v) == 1);
	assert(strcmp(getName(getPlanetOnPos(v, 0)), "Wolf 1061 c") == 0);

	Planet* p2 = createPlanet("HAT-P-26b", "Neptune-like", 450);
	assert(addPlanet(v, p2) == 1);
	assert(getRepoLength(v) == 2);

	// now try to add the same planet again -> add must return 0
	assert(addPlanet(v, p2) == 0);

	// destroy the test repository
	destroyRepo(v);

	// now the memory allocated for the planets must be freed
	destroyPlanet(p1);
	destroyPlanet(p2);
}

void testsPlanetRepo()
{
	testAdd();
}