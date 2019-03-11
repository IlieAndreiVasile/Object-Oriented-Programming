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
	cout << "\t 0 - Back." << endl;
}

int UI::readInteger(const char* message)
{
	char s[16];
	int res, r, flag = 0;

	while (flag == 0)
	{
		cout << message;
		cin >> s;
		r = sscanf(s, "%d", &res);		// reads data from s and stores them as integer, if possible; returns 1 if successful
		if (r == 1)
			flag = 1;
		else
			cout << "Error reading number!" << endl;
	}
	return res;
}

void UI::readTrenchCoat(int &size, string &colour, int &price, int &quantity, string &photograph)
{
	size = readInteger("size: ");
	cout << "colour: ";
	cin >> colour;
	price = readInteger("price: ");
	quantity = readInteger("quantity: ");
	cout << "photo: ";
	cin >> photograph;
}

bool UI::addToRepository()
{
	int size, price, quantity;
	string colour, photograph;

	readTrenchCoat(size, colour, price, quantity, photograph);

	TrenchCoat x(size, colour, price, quantity, photograph);
	if (ctrl.addToRepository(x) == true)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool UI::deleteFromRepository()
{
	int size;
	string colour;

	size = readInteger("size: ");
	cout << "colour: ";
	cin >> colour;
	
	TrenchCoat x(size, colour, 0, 0, " ");
	if (ctrl.deleteFromRepository(x) == true)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool UI::updateFromRepository()
{
	int size, sizex, price, quantity;
	string colour, colourx, photograph;

	sizex = readInteger("size: ");
	cout << "colour: ";
	cin >> colourx;

	readTrenchCoat(size, colour, price, quantity, photograph);

	TrenchCoat x(sizex, colourx, 0, 0, " ");
	TrenchCoat y(size, colour, price, quantity, photograph);

	if (ctrl.updateFromRepository(x, y) == true)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void UI::buy(int size)
{
	TrenchCoat* v = this->ctrl.getAllRepository();
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
					v[i].display();
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
	int cmd = -1;
	while (true)
	{
		this->printMenu();
		cout << "command: ";
		cin >> cmd;
		if (cmd == 1)
		{
			while (true) {
				cout << endl;
				this->printAdministratorMenu();
				cout << "command: ";
				cin >> cmd;

				if (cmd == 1)
				{
					if (addToRepository() == true)
						cout << "Trench coat added!" << endl;
					else 
						cout << "This element is already in the repository!" << endl;
					
				}
				else if (cmd == 2)
				{
					if (deleteFromRepository() == true)
						cout << "Trench coat deleted!" << endl;
					else
						cout << "This element does not exists in the repository!" << endl;
				}
				else if (cmd == 3)
				{
					if (updateFromRepository() == true)
						cout << "Trench coat updated!" << endl;
					else
						cout << "This element does not exists in the repository!" << endl;
				}
				else if (cmd == 4)
				{
					cout << "'\t\t The shopping basket value is: " << ctrl.getShopBasketSum() << endl;
					this->ctrl.printRepository();
				}
				else if (cmd == 0)
					break;
				else
					cout << "Invalid command!" << endl;
			}
		}
		else if (cmd == 2)
		{
			while (true)
			{
				cout << endl;
				printUserMenu();
				cout << "command: ";
				cin >> cmd;
				if (cmd == 1)
				{
					int size;
					cout << "What size do you looking for?" << endl;
					cin >> size;
					this->buy(size);
				}
				else if (cmd == 2)
				{
					cout << "The shopping basket value is: " << ctrl.getShopBasketSum() << endl;
					this->ctrl.printShopBasket();
					cout << endl;
				}
				else if (cmd == 0)
					break;
				else
					cout << "Invalid command!" << endl;
			}
		}
		else if (cmd == 0)
			break;
		else
			cout << "Invalid command!" << endl;
	}
}