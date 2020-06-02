#include "Controller.h"
#include <string.h>

Controller createController(PlanetRepo* r)
{
	Controller c;
	c.repo = r;

	return c;
}

int addPlanet(Controller* c, char name[], char type[], double distanceFromEarth)
{
	Planet p = createPlanet(name, type, distanceFromEarth);
	
	int res = add(c->repo, p);
	return res;
}

PlanetRepo* getRepo(Controller* c)
{
	return c->repo;
}

PlanetRepo filterByType(Controller* c, char type[])
{
	PlanetRepo res = createRepo();

	// add the planets having the given type to "res" created above and return res
	// TODO

	return res;
}