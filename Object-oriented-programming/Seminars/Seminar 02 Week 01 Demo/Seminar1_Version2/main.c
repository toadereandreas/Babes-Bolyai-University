#include "PlanetRepository.h"
#include "UI.h"
#include <crtdbg.h>

int main()
{
	// tests will not pass unless all functions are correctly implemented
	// testsPlanetRepo();

	PlanetRepo* repo = createRepo();
	Controller* ctrl = createController(repo);
	
	addPlanet(ctrl, "Wolf 1061 c", "terrestrial", 13.8);
	addPlanet(ctrl, "HAT-P-26b", "Neptune-like", 450);
	addPlanet(ctrl, "Proxima Centauri b", "terrestrial", 4.2);
	addPlanet(ctrl, "K2-18b", "super-Earth", 111);
	
	UI* ui = createUI(ctrl);

	startUI(ui);

	destroyUI(ui);

	_CrtDumpMemoryLeaks();

	return 0;
}