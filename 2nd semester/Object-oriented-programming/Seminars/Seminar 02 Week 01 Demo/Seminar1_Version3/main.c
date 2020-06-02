#include "UI.h"
#include <crtdbg.h>

int main()
{
	// Tests will pass only after everythins has been implemented according to specifications.
	/*testsDynamicArray();
	testsPlanetRepo();
	testsStack();*/

	PlanetRepo* repo = createRepo();
	OperationsStack* operationsStack = createStack();
	Controller* ctrl = createController(repo, operationsStack);
	
	addPlanetCtrl(ctrl, "Wolf 1061 c", "terrestrial", 13.8);
	addPlanetCtrl(ctrl, "HAT-P-26b", "Neptune-like", 450);
	addPlanetCtrl(ctrl, "Proxima Centauri b", "terrestrial", 4.2);
	addPlanetCtrl(ctrl, "K2-18b", "super-Earth", 111);
	
	UI* ui = createUI(ctrl);

	startUI(ui);

	destroyUI(ui);

	_CrtDumpMemoryLeaks();

	return 0;
}