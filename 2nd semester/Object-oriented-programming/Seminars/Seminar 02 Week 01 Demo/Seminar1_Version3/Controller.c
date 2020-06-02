#include "Controller.h"
#include <stdlib.h>
#include <string.h>

Controller* createController(PlanetRepo* r, OperationsStack* undoS)
{
	Controller* c = (Controller*)malloc(sizeof(Controller));
	c->repo = r;
	c->undoStack = undoS;

	return c;
}

void destroyController(Controller * c)
{
	// first destroy the repository inside
	destroyRepo(c->repo);

	// then the operation stack
	destroyStack(c->undoStack);

	// then free the memory
	free(c);
}

int addPlanetCtrl(Controller* c, char* name, char* type, double distanceFromEarth)
{
	Planet* p = createPlanet(name, type, distanceFromEarth);
	
	int res = addPlanet(c->repo, p);

	if (res == 1) // if the planet was successfully added - register the operation
	{
		Operation* o = createOperation(p, "add");
		push(c->undoStack, o);
		// once added, the operation can be destroyed (a copy of the operation was added)
		destroyOperation(o);
	}

	// destroy the planet that was just created, as the repository stored a copy
	destroyPlanet(p);

	return res;
}

PlanetRepo* getRepo(Controller* c)
{
	return c->repo;
}

int undo(Controller* c)
{
	if (isEmpty(c->undoStack))
	{
		return 0;
	}

	Operation* operation = pop(c->undoStack);

	if (strcmp(getOperationType(operation), "add") == 0)
	{
		Planet* planet = getPlanet(operation);
		char name[50];
		strcpy(name, getName(planet));
		deletePlanet(c->repo, name);
	}
	else if (strcmp(getOperationType(operation), "remove") == 0)
	{
		// TO DO!!!
	}

	// the operation must be destroyed
	destroyOperation(operation);

	return 1;

}
