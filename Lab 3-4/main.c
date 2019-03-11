#include "Repository.h"
#include "UI.h"
#include <crtdbg.h>

int main()
{
	testCountryRepo();

	CountryRepo repo = createRepo();
	Controller ctrl = createController(&repo);

	addCountry(&ctrl, "Romania", "Europe", 19.96);
	addCountry(&ctrl, "Spain", "Europe", 47.77);
	addCountry(&ctrl, "USA", "North America", 318.9);
	addCountry(&ctrl, "Australia", "Australia", 23.13);
	addCountry(&ctrl, "Canada", "North America", 35.16);
	addCountry(&ctrl, "England", "Europe", 53.01);
	addCountry(&ctrl, "Germany", "Europe", 80.62);
	addCountry(&ctrl, "France", "Europe", 66.03);
	addCountry(&ctrl, "China", "Asia", 1357);
	addCountry(&ctrl, "Brzil", "South America", 200.4);
	addCountry(&ctrl, "Italy", "Europe", 59.83);
	addCountry(&ctrl, "Portugal", "Europe", 10.34);

	UI ui = createUI(&ctrl);

	startUI(&ui);

	_CrtDumpMemoryLeaks();

	return 0;
}