#include <iostream>
//#include <Windows.h>

#define ESPRESSO_PRICE 1.5
#define CAPPUCCINO_PRICE 2.5
#define LATTE_PRICE 3.0
#define PIN 1234
#define PIN_ATTEMPTS 3

using namespace std;

void printBalance(double material, string nameOfMaterial);

void printWarningIfNoCups(int cups);

void printMenu();

void pause();

int inputNumber(int number);

double inputMaterials(double material, string nameOfMaterial);

double installPrice(int choice);

void transaction(double sum, double &from, double &to);

void giveCoffee();

void printPinMenu();

bool isPinRightEntered();

void printServiceMenu();

int main() {
    int choice = 0, cups = 3;
    double balance = 5, price = 0, balanceInMachine = 0, moneyTakenOut = 0;
    bool flagService;


    while (true) {
        system("cls");
        printWarningIfNoCups(cups);
        printBalance(balance, "money");
        printMenu();

        choice = inputNumber(choice);

        if (0 < choice and choice < 4) {
            price = installPrice(choice);
            if (price > balance) {
                cout << "Not enough money" << endl;

                pause(); //Sleep(3000);
            } else {
                transaction(price, balance, balanceInMachine);
                if (cups > 0) {
                    giveCoffee();

                    cups--;
                } else {}
            }
        } else if (choice == 4) {
            balance = inputMaterials(balance, "money");
        } else if (choice == 5) {
            system("cls");
            printPinMenu();

            choice = inputNumber(choice);
            if (choice == 1) {
                if (isPinRightEntered()) {
                    flagService = true;
                    while (flagService) {
                        printServiceMenu();

                        choice = inputNumber(choice);

                        if (choice == 1) {  //Money
                            printBalance(balance + balanceInMachine, "money");

                            pause();
                        } else if (choice == 2) {   //Cups
                            cups = inputMaterials(cups, "cups");  //max 700 pcs
                        } else if (choice == 3) {   //Withdraw money
                            transaction(balanceInMachine, balanceInMachine, moneyTakenOut);
                            transaction(balance, balance, moneyTakenOut);

                            cout << "Operation completed successfully !!! Money withdrawn: " << moneyTakenOut << " BYN" << endl;

                            moneyTakenOut = 0;
                            pause();
                        } else if (choice == 4) {   //Exit
                            flagService = false;
                        } else {
                            cout << "Incorrect input!!!" << endl;
                        }
                    }
                } else {
                    while (true) {  //maybe one function like lockMachine();
                        int tmp;
                        system("clr");
                        cout << "The machine is locked after 3 attempts to enter the wrong pin...";
                        cin >> tmp;
                    }
                }
            } else {}

        }
    }
}

void printBalance(double material, string nameOfMaterial) {
    cout << "Balance of " << nameOfMaterial << ": " << material << endl;
}

void printWarningIfNoCups(int cups) {
    if (cups == 0) {
        cout << "**********************************************************************" << endl;
        cout << "*********************** Warning! NO cups. ****************************" << endl;
        cout << "*** Do not order coffee, otherwise you will be wasting your money. ***" << endl;
        cout << "**********************************************************************" << endl;
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

int inputNumber(int number) {
    cout << "Please, press the button(s): ";
    cin >> number;

    return number;
}

double inputMaterials(double material, string nameOfMaterial) {
    double input = 0;

    while (true) {
        printBalance(material, nameOfMaterial);

        cout << "Please insert " << nameOfMaterial << "(0 - Exit): ";
        cin >> input;
        if (input == 0) {
            break;
        }

        material += input;
    }

    return material;
}

double installPrice(int choice) {
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

void transaction(double sum, double &from, double &to) {
    from -= sum;
    to += sum;
}

void giveCoffee() {
    cout << "*** Take your coffee! ***" << endl;
    pause();
}

void printPinMenu() {
    cout << "1. Enter PIN." << endl;
    cout << "0. Exit." << endl;
}

bool isPinRightEntered() {
    int pin = 0, counter = 0;
    bool flag = false;

    while (counter < 3) {
        system("cls");

        cout << "Number of password attempts: " << PIN_ATTEMPTS - counter << endl;

        pin = inputNumber(pin);

        if (pin == PIN) {
            flag = true;
            break;
        }
        counter++;
    }
    return flag;
}

void printServiceMenu() {
    system("cls");
    cout << "Service menu: " << endl;
    cout << "1. Balance of money in machine" << endl;
    cout << "2. Check/Change the number of cups" << endl;
    cout << "3. Withdraw money from the machine" << endl;
    cout << "4. Exit the Service menu" << endl;
}