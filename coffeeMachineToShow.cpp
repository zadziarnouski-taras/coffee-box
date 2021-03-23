#include <iostream>

#define ESPRESSO_PRICE 1.5
#define CAPPUCCINO_PRICE 2.5
#define LATTE_PRICE 3.0
#define PIN 1234
#define SERVICE_NUMBER 5
#define PIN_ATTEMPTS 3
#define WARNING_CUPS_QUANTITY 3

using namespace std;

void printBalance(double balance);
void printWarningIfNoCups(int cups);
void printMenu();
int inputNumber(int number);
void pause();

int main()
{
	int choice = 0, cups = 7;
	double balance = 0;


	while (true)
	{
		system("cls");
		printWarningIfNoCups(cups);
		printBalance(balance);
		printMenu();

		choice = inputNumber(choice);		

		if (choice >= 1 and choice <= 3)
		{
			cout << "coffee" << endl;

			pause();
		}
		else if (choice == 4)
		{
			cout << "money" << endl;

			pause();
		}
		else if (choice == SERVICE_NUMBER)
		{
			cout << "servise" << endl;	

			pause();
		}
	}

	return 0;
}

void printBalance(double balance)
{
	cout << "Balance: " << balance << endl;
}

void printWarningIfNoCups(int cups)
{
	if (cups == 0)
	{
		cout << "*** Warning! No cups ***" << endl;
	}
}

void printMenu()
{
	cout << "1. Espresso " << ESPRESSO_PRICE << " BYN" << endl;
	cout << "2. Cappuccino " << CAPPUCCINO_PRICE << " BYN" << endl;
	cout << "3. Latte " << LATTE_PRICE << " BYN" << endl;
	cout << "4. Put money" << endl;
	cout << "5. Service" << endl << endl;
}

int inputNumber(int number)
{
	cout << "Please, press the button: ";
	cin >> number;

	return number;
}

void pause()
{
	cout << endl;
	system("pause");
}