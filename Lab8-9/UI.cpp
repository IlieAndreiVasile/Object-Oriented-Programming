#include "UI.h"
#include <string>


using namespace std;

void UI::printMenu()
{
	cout << endl;
	cout << "\t MENU:" << endl;
	cout << "1 - Administrator mode." << endl;
	cout << "2 - User mode." << endl;
	cout << "0 - Exit." << endl;
}

void UI::printAdministratorMenu()
{
	cout << "\t\t Administrator Menu: " << endl;
	cout << "\t 1 - Add trench coat." << endl;
	cout << "\t 2 - Delete trench coat." << endl;
	cout << "\t 3 - Update trench coat." << endl;
	cout << "\t 4 - Display all." << endl;
	cout << "\t 0 - Back." << endl;
}

void UI::printUserMenu()
{
	cout << "\t\t User Menu: " << endl;
	cout << "\t 1 - Buy trench coats." << endl;
	cout << "\t 2 - See the shopping basket and the total price of the purchased trench coats." << endl;
	cout << "\t 3 - Display ShopBasket" << endl;
	cout << "\t 0 - Back." << endl;
}

void UI::addToRepository()
{
	int size;
	cout << "size: ";
	cin >> size;
	cin.ignore();
	cout << "colour: ";
	string colour;
	getline(cin, colour);
	int price;
	cout << "price: ";
	cin >> price;
	cin.ignore();
	int quantity;
	cout << "quantity: ";
	cin >> quantity;
	cin.ignore();
	cout << "photo: ";
	string photograph;
	getline(cin, photograph);

	try
	{
		this->ctrl.addToRepository(size, colour, price, quantity, photograph);
	}
	catch (TrenchCoatException& e)
	{
		for (auto s : e.getErrors())
			cout << s;
	}

	catch (RepositoryException& e)
	{
		cout << e.what() << endl;
	}
}

void UI::deleteFromRepository()
{
	int size;
	cout << "size: ";
	cin >> size;
	cin.ignore();
	cout << "colour: ";
	string colour;
	getline(cin, colour);

	try
	{
		this->ctrl.deleteFromRepository(size, colour, 0, 0, "");
	}
	catch (RepositoryException& e)
	{
		cout << e.what() << endl;
	}
}

void UI::updateFromRepository()
{
	int size;
	cout << "size: ";
	cin >> size;
	cin.ignore();
	cout << "colour: ";
	string colour;
	getline(cin, colour);
	int price;
	cout << "price: ";
	cin >> price;
	cin.ignore();
	int quantity;
	cout << "quantity: ";
	cin >> quantity;
	cin.ignore();
	cout << "photo: ";
	string photograph;
	getline(cin, photograph);

	try
	{
		this->ctrl.updateFromRepository(size, colour, price, quantity, photograph);
	}
	catch (RepositoryException& e)
	{
		cout << e.what() << endl;
	}
}

void UI::buy(int size)
{
	vector<TrenchCoat>& v = this->ctrl.getAllRepository();
	int n = this->ctrl.getSizeRepository();
	int i, m = 0, pos = -1, flag = 0, cmd;

	if (size == 0)					// if the user introduce the size "0" then all trench coats will be considered.
	{
		m = n;
		pos = 0;
	}
	else
	{
		for (int i = 0; i < n; i++)
			if (v[i].getSize() == size)
				m++;
		i = 0;
		while (pos == -1 && i <= n)
			if (v[i].getSize() == size)
				pos = i;
			else
				i++;
	}

	if (m != 0)
	{
		i = pos;
		while (flag != 1)
		{
			if (v[i].getQuantity() > 0)
			{
				v[i].printTrenchCoat();
				cout << "\t\t 1 Buy" << endl;
				cout << "\t\t 2 See photo" << endl;
				cout << "\t\t 3 Next" << endl;
				cout << "\t\t 0 Back" << endl;
				cin >> cmd;

				if (cmd == 1)
				{
					this->ctrl.addToShopBasket(v[i]);
					v[i].setQuantity(v[i].getQuantity() - 1);
					cout << "'\t\t The shopping basket value is: " << ctrl.getShopBasketSum() << endl;
				}
				else if (cmd == 2)
				{
					v[i].displayPhotograph();
					cout << "\t\t 1 Buy" << endl;
					cout << "\t\t 2 Next" << endl;
					cout << "\t\t 0 Back" << endl;
					cin >> cmd;
					if (cmd == 1)
					{
						this->ctrl.addToShopBasket(v[i]);
						v[i].setQuantity(v[i].getQuantity() - 1);
						cout << "'\t\t The shopping basket value is: " << ctrl.getShopBasketSum() << endl;
					}
					else if (cmd == 2)
					{
						if (i < m + pos - 1)
							i++;
						else
							i = pos;		// if it is the last item we return to the first one
					}
					else if (cmd == 0)
						break;
					else
						cout << "Invalid command!" << endl;
				}
				else if (cmd == 3)
				{
					if (i < m + pos - 1)
						i++;
					else
						i = pos;		// if it is the last item we return to the first one
				}
				else if (cmd == 0)
					flag = 1;
				else
					cout << "Invalid command!" << endl;
			}
			else
			{
				cout << "Trench coat size: " << v[i].getSize() << " and colour: " << v[i].getColour() << " out of stock!" << endl;
				if (i < m + pos - 1)
					i++;
				else
					i = pos;		// if it is the last item we return to the first one
				cout << endl;
			}
		}
	}
	else
		cout << "Sorry, we do not have tench coats with this size!" << endl;
}

void UI::run()
{
	while (true)
	{
		UI::printMenu();
		int cmd{ 0 };
		cout << "command: ";
		cin >> cmd;
		cin.ignore();
		if (cmd == 0)
			break;

		if (cmd == 1)
		{
			while (true)
			{
				cout << endl;
				UI::printAdministratorMenu();
				int cmdAdmin{ 0 };
				cout << "command: ";
				cin >> cmdAdmin;
				cin.ignore();
				if (cmdAdmin == 0)
					break;

				switch (cmdAdmin)
				{

				case 1:
				{
					this->addToRepository();
					break;
				}

				case 2:
				{
					this->deleteFromRepository();
					break;
				}

				case 3:
				{
					this->updateFromRepository();
					break;
				}

				case 4:
				{
					this->ctrl.printRepository();
				}
				}
			}
		}
		else
		{
			while (true)
			{
				cout << endl;
				UI::printUserMenu();
				int cmdUser{ 0 };
				cout << "command: ";
				cin >> cmdUser;
				cin.ignore();
				if (cmdUser == 0)
					break;

				switch (cmdUser)
				{

				case 1:
				{
					int size;
					cout << "What size do you looking for?" << endl;
					cin >> size;
					this->buy(size);
				}

				case 2:
				{
					cout << "The shopping basket value is: " << ctrl.getShopBasketSum() << endl;
					this->ctrl.printShopBasket();
					cout << endl;
				}

				case 3:
				{
					this->ctrl.displayPlayList();
					break;
				}
				}
			}
		}
	}
	this->ctrl.writeToFile();
}