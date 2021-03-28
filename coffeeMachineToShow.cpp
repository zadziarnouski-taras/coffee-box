#include <iostream>
#include <Windows.h>
#include <conio.h>

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

using namespace std;

void printBalance(double material, string nameOfMaterial);

void printTipLessThan3Cups(int cups);

void printMenu();

void pause();

int inputNumber(int number);

double inputMaterials(double material, string nameOfMaterial);

double installPrice(int choice);

void transaction(double sum, double &from, double &to);

void giveCoffee();

void printServiceMenu();

void clearConsole();

void lockMachine();

bool checkPin(int pin);

void printWarning(int warningCode);

void composeWarning(string warning);

int inputPin();

<<<<<<< Updated upstream
=======
double inputMoney(double balance, int cups);

bool isEnoughCups(double totalBalance, int cups);

void printLoading();

>>>>>>> Stashed changes
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

        choice = inputNumber(choice);

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
                    printLoading();
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
                pin = inputPin();

                if (pin) {
                    counter--;
                    if (checkPin(pin)) {
                        isFromServiceMenu = true;
                        while (true) {
                            counter = 3, pin = 0;
                            clearConsole();
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
                                    cout << "Operation completed successfully !!! Money withdrawn: "
                                         << moneyTakenOut   //maybe one more function
                                         << " BYN"
                                         << endl;
                                    moneyTakenOut = 0;
                                } else {
                                    printWarning(NO_MONEY_IN_MACHINE);
                                }
                                pause();
                            }  else {
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
        cout << "____________*** Take your coffee! ***___________" << endl;
        cout << "_______________Have a nice day!!!_______________" << endl;
        cout << "______________1¶¶¶¶¶¶¶¶¶1_______________________" << endl;
        cout << "_________1¶¶¶¶¶¶¶11_______1¶¶¶¶¶¶¶¶1____________" << endl;
        cout << "________¶¶¶¶1____________¶¶¶¶¶¶¶¶¶¶¶¶___________" << endl;
        cout << "_______1¶¶¶¶____________________¶¶¶¶1__11¶11____" << endl;
        cout << "________¶¶¶¶¶11_______________1¶¶¶1__¶¶¶¶¶¶¶¶1__" << endl;
        cout << "_________¶¶¶¶¶¶¶¶¶¶¶11111¶¶¶¶¶¶¶___¶¶¶1___¶¶¶¶__" << endl;
        cout << "__________1¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶1____¶¶¶¶_____1¶¶¶__" << endl;
        cout << "___________1¶¶¶1________________¶¶¶¶_____1¶¶¶¶__" << endl;
        cout << "____________1¶¶¶¶______________¶¶¶¶__1¶¶¶¶¶¶¶___" << endl;
        cout << "_____________1¶¶¶¶____________1¶¶¶___¶¶¶¶¶¶¶____" << endl;
        cout << "______________1¶¶¶____________¶¶¶_____1111______" << endl;
        cout << "__________1¶¶¶¶¶¶¶¶__________¶¶¶________________" << endl;
        cout << "______1¶¶¶¶¶¶¶¶11¶¶¶________¶¶¶__¶¶¶¶¶¶¶1_______" << endl;
        cout << "___1¶¶¶¶¶¶1_______¶¶¶¶1__11¶¶¶___¶¶¶¶¶¶¶¶¶______" << endl;
        cout << "__1¶¶¶¶¶¶__________1¶¶¶¶¶¶¶¶1_________1¶¶¶¶_____" << endl;
        cout << "__1¶¶¶¶¶¶¶____________________________¶¶¶¶______" << endl;
        cout << "____1¶¶¶¶¶¶¶¶1_____________________1¶¶¶¶1_______" << endl;
        cout << "_______1¶¶¶¶¶¶¶¶¶¶¶¶¶111111111¶¶¶¶¶¶¶¶__________" << endl;
        cout << "____________11¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶11_____________" << endl;
        cout << "________________________________________________" << endl;
}

void printLoading()
{
    for (int i = 0; i < 11; i++) {
        clearConsole();
        for (int j = 0; j < i; j++) {
            cout << "///";
        }
        cout << i * 10 << "%" << endl;
        Sleep(300);
    }
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
            warning = "***** The machine is locked after 3 attempts to enter the wrong pin... ******";
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
    
    cout << "Enter PIN: ";

    while (temp != 13){
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
        } else if (temp != 13){
            cout << "*";
            pin = pin * 10 + (int)temp - 48;
            counter++;
        }
    }

    return pin;
}