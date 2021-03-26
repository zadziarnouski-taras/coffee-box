#include <iostream>
//#include <Windows.h>

#define ESPRESSO_PRICE 1.5
#define CAPPUCCINO_PRICE 2.5
#define LATTE_PRICE 3.0
#define PIN 1234

/**
 * Warning codes
 * */
#define NO_CUPS 1
#define NOT_ENOUGH_MONEY 2
#define NO_MONEY_IN_MACHINE 3
#define INCORRECT_INPUT 4
#define MAX_CAPACITY_OF_CUPS_700 5
#define LOCK_MACHINE 6

using namespace std;

void printBalance(double material, string nameOfMaterial);

void printTipLessThan3Cups(int cups);

void printMenu();

void pause();

int inputNumber(int number, string word);

double inputMaterials(double material, string nameOfMaterial);

double installPrice(int choice);

void transaction(double sum, double &from, double &to);

void giveCoffee();

void printServiceMenu();

void clearConsole();

void lockMachine();

bool checkPin(int pin);

void printWarning(int warningCode);

int main() {
    int choice = 0, cups = 3, pin = 0, counter = 3;
    double balance = 0, price = 0, balanceInMachine = 0, moneyTakenOut = 0;
    bool isFromServiceMenu = false;

    while (true) {
        clearConsole();

        if (cups == 0) {
            printWarning(NO_CUPS);
        } else if (cups < 4) {
            printTipLessThan3Cups(cups);
        }
        printBalance(balance, "money");
        printMenu();

        choice = inputNumber(choice, "number");

        if (0 < choice and choice < 4) {    //ESPRESSO or CAPPUCCINO or LATTE
            price = installPrice(choice);
            if (price > balance) {
                clearConsole();
                printWarning(NOT_ENOUGH_MONEY);

                pause(); //Sleep(3000);
            } else {
                transaction(price, balance, balanceInMachine);
                if (cups > 0) {
                    clearConsole();
                    giveCoffee();
                    pause();

                    cups--;
                } else {}
            }
        } else if (choice == 4) {   //Put Money
            balance = inputMaterials(balance, "money");
        } else if (choice == 5) {   //Service
            clearConsole();
            while (counter > 0) {
                clearConsole();
                pin = inputNumber(pin, "PIN");

                if (pin) {
                    counter--;
                    if (checkPin(pin)) {
                        isFromServiceMenu = true;
                        while (true) {
                            counter = 3, pin = 0;
                            clearConsole();
                            printServiceMenu();

                            choice = inputNumber(choice, "number");

                            if (choice == 1) {  //Money
                                clearConsole();
                                printBalance(balance + balanceInMachine, "money");

                                pause();
                            } else if (choice == 2) {   //Cups
                                clearConsole();
                                cups = inputMaterials(cups, "cups");
                            } else if (choice == 3) {   //Withdraw money
                                clearConsole();
                                if (balanceInMachine > 0) {
                                    transaction(balanceInMachine, balanceInMachine, moneyTakenOut);
                                }
                                if (balance > 0) {
                                    transaction(balance, balance, moneyTakenOut);
                                }
                                if (moneyTakenOut > 0) {
                                    cout << "Operation completed successfully !!! Money withdrawn: " << moneyTakenOut   //maybe one more function
                                         << " BYN"
                                         << endl;
                                    moneyTakenOut = 0;
                                } else {
                                    printWarning(NO_MONEY_IN_MACHINE);
                                }
                                pause();
                            } else if (choice == 4) {   //Exit
                                break;
                            } else {
                                printWarning(INCORRECT_INPUT);
                            }
                        }
                    } else {}
                } else {
                    break;
                }
                if (isFromServiceMenu) {
                    isFromServiceMenu = false;
                    break;
                }
            }
            if (counter == 0) {
                lockMachine();
            }
        }
    }
}

void printBalance(double material, string nameOfMaterial) {
    cout << "Balance of " << nameOfMaterial << ": " << material << endl;
}

void printTipLessThan3Cups(int cups) {
    cout << "**********************************************************************" << endl;
    cout << "***************** Warning! Only " << cups << " cups left in machine ***************" << endl;
    cout << "**********************************************************************" << endl;
}

void printMenu() {
    cout << "1. Espresso " << ESPRESSO_PRICE << " BYN" << endl;
    cout << "2. Cappuccino " << CAPPUCCINO_PRICE << " BYN" << endl;
    cout << "3. Latte " << LATTE_PRICE << " BYN" << endl;
    cout << "4. Put money" << endl;
    cout << "5. Service" << endl << endl;
}

void pause() {
    system("pause");
}

int inputNumber(int number, string word) {
    string hint = "";
    if (word == "PIN") {
        hint = " (0 - Exit)";
    }
    cout << "Enter " << word << hint << ": ";
    cin >> number;

    return number;
}

double inputMaterials(double material, string nameOfMaterial) {
    double input = 0;

    while (true) {
        clearConsole();
        printBalance(material, nameOfMaterial);

        cout << "Please insert " << nameOfMaterial << "(0 - Exit): ";
        cin >> input;

        if (nameOfMaterial == "cups" and material + input > 700) {
            clearConsole();

            printWarning(MAX_CAPACITY_OF_CUPS_700);
            pause();
        } else if (input > 0) {
            material += input;
        } else if (input == 0) {
            break;
        } else {}
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
}

void printServiceMenu() {
    cout << "Service menu: " << endl;
    cout << "1. Balance of money in machine" << endl;
    cout << "2. Check/Change the number of cups" << endl;
    cout << "3. Withdraw money from the machine" << endl;
    cout << "4. Exit the Service menu" << endl;
}

void clearConsole() {
    system("cls");
}

void lockMachine() {
    while (true) {
        int tmp;
        clearConsole();

        printWarning(LOCK_MACHINE);
        cin >> tmp;
    }
}

bool checkPin(int pin) {
    return pin == PIN;
}

void printWarning(int warningCode) {
    switch (warningCode) {
        case NO_CUPS:
            cout << "*****************************************************************************" << endl;
            cout << "*** NO cups.Do NOT order coffee, otherwise you will be wasting your money.***" << endl;
            cout << "*****************************************************************************" << endl;
            break;
        case NOT_ENOUGH_MONEY:
            cout << "*****************************************************************************" << endl;
            cout << "************************** NOT enough money! ********************************" << endl;
            cout << "*****************************************************************************" << endl;
            break;
        case NO_MONEY_IN_MACHINE:
            cout << "*****************************************************************************" << endl;
            cout << "******************** There is NO money in the machine! **********************" << endl;
            cout << "*****************************************************************************" << endl;
            break;
        case INCORRECT_INPUT:
            cout << "*****************************************************************************" << endl;
            cout << "*************************** Incorrect input! ********************************" << endl;
            cout << "*****************************************************************************" << endl;
            break;
        case MAX_CAPACITY_OF_CUPS_700:
            cout << "*****************************************************************************" << endl;
            cout << "******************* MAXIMUM capacity of cups 700 pieces! ********************" << endl;
            cout << "*****************************************************************************" << endl;
            break;
        case LOCK_MACHINE:
            cout << "*****************************************************************************" << endl;
            cout << "***** The machine is locked after 3 attempts to enter the wrong pin... ******" << endl;
            cout << "*****************************************************************************" << endl;
            break;
        default:
            break;
    }
}