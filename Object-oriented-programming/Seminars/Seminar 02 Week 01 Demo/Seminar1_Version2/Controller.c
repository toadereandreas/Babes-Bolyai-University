#include "Controller.h"
#include <stdlib.h>
#include <string.h>

Controller* createController(PlanetRepo* r)
{
	Controller* c = (Controller*)malloc(sizeof(Controller));
	c->repo = r;

	return c;
}

void destroyController(Controller * c)
{
	// first destroy the repository inside
	destroyRepo(c->repo);
	// then free the memory
	free(c);
}

int addPlanet(Controller* c, char* name, char* type, double distanceFromEarth)
{
	Planet* p = createPlanet(name, type, distanceFromEarth);
	
	int res = add(c->repo, p);
	// if the planet was not added - destroy it (as it will not be destroyed by the repository)
	if (res == 0)
		destroyPlanet(p);

	return res;
}

PlanetRepo* getRepo(Controller* c)
{
	return c->repo;
}

PlanetRepo* filterByType(Controller* c, char type[])
{
	PlanetRepo* res = createRepo();

	if (strcmp(type, "null") == 0)
	{
		// what should we do here?
	}

	// for each planet that fulfills the condition, create a copy and add it to "res"
	// why should we create a copy?

	// TODO

	return res;
}