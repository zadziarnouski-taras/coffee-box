#include <iostream>
//#include <Windows.h>

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

void pause();


double inputNumber(double number, string action);

double inputMaterials(double material, string action, string materialBalance);

void printMaterialBalance(double material, string materialBalance);

double installCurrentPrice(int choice);

void transactPayment(double price, double &balance, double &balanceInMachine);

void cupsReduction(int &cups);

void giveCoffee(int cups);


int main() {
    int choice = 0, cups = 3;
    double balance = 5, currentPrice = 0, balanceInMachine = 0;


    while (true) {
        system("cls");
        printWarningIfNoCups(cups);
        printBalance(balance);
        printMenu();

        choice = inputNumber(choice, "Please, press the button: ");

        if (choice >= 1 and choice <= 3) {
            currentPrice = installCurrentPrice(choice);

            if (currentPrice > balance) {
                cout << "Not enough money" << endl;
//				Sleep(3000);
            } else {
                transactPayment(currentPrice, balance, balanceInMachine);
                giveCoffee(cups);
                cupsReduction(cups);
            }
        } else if (choice == 4) {
            balance = inputMaterials(balance, "Input money (0 for exit): ", "Balance: ");
        } else if (choice == SERVICE_NUMBER) {
            cout << "service" << endl;

            pause();
        }
    }
}

void printBalance(double balance) {
    cout << "Balance: " << balance << endl;
}

void printWarningIfNoCups(int cups) {
    if (cups == 0) {
        cout << "*** Warning! No cups ***" << endl;
    }
}

void printMenu() {
    cout << "1. Espresso " << ESPRESSO_PRICE << " BYN" << endl;
    cout << "2. Cappuccino " << CAPPUCCINO_PRICE << " BYN" << endl;
    cout << "3. Latte " << LATTE_PRICE << " BYN" << endl;
    cout << "4. Put money" << endl;
    cout << "5. Service" << endl << endl;
}

void pause() {
    cout << endl;
    system("pause");
}


double inputNumber(double number, string action) {
    cout << action;

    cin >> number;

    return number;
}

double inputMaterials(double material, string action, string materialBalance) {
    double input = 0;

    while (true) {
        printMaterialBalance(material, materialBalance);
        input = inputNumber(input, action);

        if (input == 0) {
            break;
        }

        material += input;
        input = 0;
    }

    return material;
}

void printMaterialBalance(double material, string materialBalance) {
    system("cls");

    cout << materialBalance << material << endl;
}

double installCurrentPrice(int choice) {
    switch (choice) {
        case 1:
            return ESPRESSO_PRICE;
        case 2:
            return CAPPUCCINO_PRICE;
        case 3:
            return LATTE_PRICE;
        default:
            break;
    }
}

void transactPayment(double price, double &balance, double &balanceInMachine) {
    balance -= price;
    balanceInMachine += price;
}

void cupsReduction(int &cups) {
    if (cups > 0) cups -= 1;
}

void giveCoffee(int cups) //?
{
    if (cups > 0) {
        cout << "*** Take your coffee! ***" << endl;
        pause();
    } else {
        cout << "Ha-ha! Just spent money :(" << endl;
//		Sleep(3000);
    }
}

