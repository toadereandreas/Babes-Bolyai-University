#pragma once
#include "PlanetRepository.h"

typedef struct
{
	PlanetRepo* repo;
} Controller;

Controller* createController(PlanetRepo* r);
void destroyController(Controller* c);

/// <summary>
/// Adds a planet to the repository of planets.
/// </summary>
/// <param name="c">Pointer to theController.</param>
/// <param name = "name">A string, the name of the planet.</param>
/// <param name = "type">A string, the planet's type.</param>
/// <param name = "distanceFromEarth">Double, the distance from the planet to Earth, in light years.</param>
/// <returns>1 - if the planet was sucessfully added; 0 - if the planet could not be added, as another planet with the same name already exists.</returns>
int addPlanet(Controller* c, char* name, char* type, double distanceFromEarth);

PlanetRepo* getRepo(Controller* c);

/// <summary>
/// Searches for the planets containing a given type.
/// </summary>
/// <param name="c">Pointer to theController.</param>
/// <param name = "symbols">A string, the searched type; "null" - for all the planets.</param>
/// <returns>A pointer to a repository of planets, that have the given type.</returns>
PlanetRepo* filterByType(Controller* c, char type[]);
