#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <string.h>

#define ESPRESSO_PRICE 1.5
#define CAPPUCCINO_PRICE 2.5
#define LATTE_PRICE 3.0
#define PIN 8014

/**
 * Warning codes
 * */

#define NO_CUPS 1
#define NOT_ENOUGH_MONEY 2
#define NO_MONEY_IN_MACHINE 3
#define INCORRECT_INPUT 4
#define MAX_CAPACITY_OF_CUPS_700 5
#define LOCK_MACHINE 6
#define NOT_ENOUGH_CUPS 7

/**
 * Color codes
 * */

const char *BRIGHT_WHITE = "F";
const char *BLACK = "0";
const char *BLUE = "1";
const char *RED = "4";

using namespace std;

/**
 * Print functions
 * */

void printBalance(double material, string nameOfMaterial);
void printMenu();
void printServiceMenu();
void printLoading();
void printConfirmationOfWithdrawnMoney(double withdrawnMoney);
void printWarning(int warningCode);

/**
 * Input functions
 * */

int inputNumber(int number);
double inputMaterials(double material, string nameOfMaterial);
int inputPin();
double inputMoney(double balance, int cups);

/**
 * System functions
 * */

void pause();
void clearConsole();
void changeBackgroundAndFontColor(const char *backgroundColor, const char *fontColor);

/**
 * Special functions
 * */

double installPrice(int choice);
void transaction(double sum, double &from, double &to);
void giveCoffee();
void lockMachine();
bool checkPin(int pin);
void composeWarning(string warning);
bool isEnoughCups(double totalBalance, int cups);

int main() {
    int choice = 0, cups = 3, pin, counter = 3;
    double balance = 0, price, balanceInMachine = 0, moneyTakenOut = 0;
    bool isFromServiceMenu = false;

    while (true) {
        clearConsole();
        changeBackgroundAndFontColor(BLACK, BRIGHT_WHITE);

        if (cups == 0) {
            printWarning(NO_CUPS);
        }
        printBalance(balance, "money");
        printMenu();

        choice = inputNumber(choice);

        if (0 < choice and choice < 4) {    //ESPRESSO or CAPPUCCINO or LATTE
            price = installPrice(choice);
            if (price > balance) {
                clearConsole();
                printWarning(NOT_ENOUGH_MONEY);

                pause();
            } else {
                transaction(price, balance, balanceInMachine);
                if (cups > 0) {
                    clearConsole();
                    printLoading();
                    giveCoffee();
                    pause();

                    cups--;
                } else {}
            }
        } else if (choice == 4) {   //Put Money
            //balance = inputMaterials(balance, "money");
            balance = inputMoney(balance, cups);
        } else if (choice == 5) {   //Service
            clearConsole();
            while (counter > 0) {
                clearConsole();
                changeBackgroundAndFontColor(BLACK, RED);
                pin = inputPin();

                if (pin) {
                    counter--;
                    if (checkPin(pin)) {
                        isFromServiceMenu = true;
                        while (true) {
                            counter = 3, pin = 0;
                            clearConsole();
                            changeBackgroundAndFontColor(BRIGHT_WHITE, BLUE);
                            printServiceMenu();

                            choice = inputNumber(choice);

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
                                    printConfirmationOfWithdrawnMoney(moneyTakenOut);
                                    moneyTakenOut = 0;
                                } else {
                                    printWarning(NO_MONEY_IN_MACHINE);
                                }
                                pause();
                            } else {
                                break;
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
                changeBackgroundAndFontColor(RED, BLACK);
                lockMachine();
            }
        }
    }
}

void printBalance(double material, string nameOfMaterial) {
    cout << "Balance of " << nameOfMaterial << ": " << material << endl;
}

void printMenu() {
    cout << "1. Espresso \t  " << ESPRESSO_PRICE << " BYN" << endl;
    cout << "2. Cappuccino \t  " << CAPPUCCINO_PRICE << " BYN" << endl;
    cout << "3. Latte \t  " << LATTE_PRICE << "   BYN" << endl;
    cout << "4. Put money" << endl;
    cout << "5. Service" << endl << endl;
}

void pause() {
    cout << "Press any key to continue...";
    _getch();
}

int inputNumber(int number) {
    cout << "Press the button: ";
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
    cout << "_________Take your coffee! Have a nice day!_____" << endl;
    cout << "______________1XXXXXXXXX1_______________________" << endl;
    cout << "_________1XXXXXXX11_______1XXXXXXXX1____________" << endl;
    cout << "________XXXX1____________XXXXXXXXXXXX___________" << endl;
    cout << "_______1XXXX____________________XXXX1__11X11____" << endl;
    cout << "________XXXXX11_______________1XXX1__XXXXXXXX1__" << endl;
    cout << "_________XXXXXXXXXXX11111XXXXXXX___XXX1___XXXX__" << endl;
    cout << "__________1XXXXXXXXXXXXXXXXX1____XXXX_____1XXX__" << endl;
    cout << "___________1XXX1________________XXXX_____1XXXX__" << endl;
    cout << "____________1XXXX______________XXXX__1XXXXXXX___" << endl;
    cout << "_____________1XXXX____________1XXX___XXXXXXX____" << endl;
    cout << "______________1XXX____________XXX_____1111______" << endl;
    cout << "__________1XXXXXXXX__________XXX________________" << endl;
    cout << "______1XXXXXXXX11XXX________XXX__XXXXXXX1_______" << endl;
    cout << "___1XXXXXX1_______XXXX1__11XXX___XXXXXXXXX______" << endl;
    cout << "__1XXXXXX__________1XXXXXXXX1_________1XXXX_____" << endl;
    cout << "__1XXXXXXX____________________________XXXX______" << endl;
    cout << "____1XXXXXXXX1_____________________1XXXX1_______" << endl;
    cout << "_______1XXXXXXXXXXXXX111111111XXXXXXXX__________" << endl;
    cout << "____________11XXXXXXXXXXXXXXXXXXX11_____________" << endl;
    cout << "________________________________________________" << endl;
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
    string warning;

    switch (warningCode) {
        case NO_CUPS:
            warning = "NO cups!Do NOT order coffee, otherwise you will be wasting your money";
            composeWarning(warning);
            break;
        case NOT_ENOUGH_MONEY:
            warning = "NOT enough money!";
            composeWarning(warning);
            break;
        case NO_MONEY_IN_MACHINE:
            warning = "There is NO money in the machine!";
            composeWarning(warning);
            break;
        case INCORRECT_INPUT:
            warning = "Incorrect input!";
            composeWarning(warning);
            break;
        case MAX_CAPACITY_OF_CUPS_700:
            warning = "MAXIMUM capacity of cups 700 pieces!";
            composeWarning(warning);
            break;
        case LOCK_MACHINE:
            warning = "The machine is locked after 3 attempts to enter the wrong pin...";
            composeWarning(warning);
            break;
        case NOT_ENOUGH_CUPS:
            warning = "Warning! Could be not enough cups in machine!";
            composeWarning(warning);
            break;
        default:
            break;
    }
}

void composeWarning(string warning) {
    string midLine = "***   ***", topBottomLine;

    midLine.replace(4, 1, warning);

    for (int i = 0; i < midLine.size(); i++) {
        topBottomLine.append("*");
    }

    cout << topBottomLine << endl;
    cout << midLine << endl;
    cout << topBottomLine << endl;
}

int inputPin() {
    int pin = 0, temp = 0, counter = 0;

    cout << "Enter PIN (0 for exit): ";

    while (temp != 13) {
        temp = _getch();

        if (temp == 8) {
            if (counter > 0) {
                clearConsole();
                counter--;
                pin /= 10;

                cout << "Enter PIN: ";
                for (int i = 0; i < counter; i++) {
                    cout << "*";
                }
            }
        } else if (temp != 13) {
            cout << "*";
            pin = pin * 10 + (int) temp - 48;
            counter++;
        }
    }

    return pin;
}

double inputMoney(double balance, int cups) {
    double moneyToInput = 0;
    int choice = 0;

    while (true) {
        clearConsole();
        printBalance(balance, "money");
        cout << "Input money (0 to exit): ";
        cin >> moneyToInput;

        if (moneyToInput < 0) {
            moneyToInput = 0;
        }

        if (moneyToInput == 0) {
            break;
        } else if (isEnoughCups(balance + moneyToInput, cups)) {
            balance += moneyToInput;
        } else {
            do {
                clearConsole();
                printWarning(NOT_ENOUGH_CUPS);
                cout << "Press 1 to confirm input, 0 to take your money. " << endl;
                choice = inputNumber(choice);
            } while (choice != 0 and choice != 1);

            if (choice) {
                balance += moneyToInput;
            } else {
                clearConsole();
                cout << "Take your " << moneyToInput << " BYN" << endl;
                pause();
                break;
            }
        }
    }

    return balance;
}

bool isEnoughCups(double totalBalance, int cups) {
    return ESPRESSO_PRICE * cups >= totalBalance;
}

void printLoading() {
    for (int i = 0; i < 11; i++) {
        clearConsole();
        for (int j = 0; j < i; j++) {
            cout << "///";
        }
        cout << i * 10 << "%" << endl;
        Sleep(300);
    }
}

void changeBackgroundAndFontColor(const char *backgroundColor, const char *fontColor) {
    char command[9] = "color ";

    strcat_s(command, backgroundColor);
    strcat_s(command, fontColor);

    system(command);
}

void printConfirmationOfWithdrawnMoney(double withdrawnMoney) {
    cout << "Operation completed successfully !!! Money withdrawn: " << withdrawnMoney << " BYN" << endl;
}
