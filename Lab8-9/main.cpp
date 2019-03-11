#include "TrenchCoat.h"
#include "Repository.h"
#include "Controller.h"
#include "UI.h"
#include "CSVShopBasket.h"
#include "HTMLShopBasket.h"
//#include "tests.h"
#include <crtdbg.h>


using namespace std;

int main()
{
	system("color f1");

	//tests();

	Repository repo;

	repo.readFromFile();

	cout << "How would you like to work?" << endl;
	cout << "1 - CSV File" << endl;
	cout << "2 - HTML." << endl;

	int command{ 0 };
	cout << "command: ";
	cin >> command;
	cin.ignore();

	if (command == 1)
	{
		CSV p;

		Controller ctrl{ repo , &p };
		UI ui{ ctrl };
		ui.run();

		p.writeToFile();
	}
	else if (command == 2)
	{
		HTML p;

		Controller ctrl{ repo , &p };
		UI ui{ ctrl };
		ui.run();

		p.writeToFile();
	}

	/*if (_CrtDumpMemoryLeaks())
	{
		cout << "\n    There are some memory leaks !\n\n" << endl;
		system("pause");
	}*/

	cout <<"\n Have a nice day!" << endl;
	system("pause");
	return 0;
}