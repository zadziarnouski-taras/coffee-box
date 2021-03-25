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

int inputNumber(int number, string word);

double inputMaterials(double material, string nameOfMaterial);

double installPrice(int choice);

void transaction(double sum, double &from, double &to);

void giveCoffee();

void printPinMenu();

bool isPinRightEntered();

void printServiceMenu();

void clearConsole();

int inputPin(int pin);

void lockMachine();

int main() {
    int choice = 0, cups = 3, pin = 0, counter = 3;
    double balance = 0, price = 0, balanceInMachine = 0, moneyTakenOut = 0;
    bool flagService;


    while (true) {
        clearConsole();
        printWarningIfNoCups(cups);
        printBalance(balance, "money");
        printMenu();

        choice = inputNumber(choice, "number");

        if (0 < choice and choice < 4) {
            price = installPrice(choice);
            if (price > balance) {
                cout << "Not enough money" << endl;

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
        } else if (choice == 4) {
            balance = inputMaterials(balance, "money");
        } else if (choice == 5) {
            clearConsole();

            while (true){
            pin = inputNumber(pin, "PIN");
            counter--;

            if (pin == PIN) {
                counter = 3;
                flagService = true;
                break;
            }
            else if (pin == 0) {
                counter++;
                flagService = false;
                break;
            }
            else if (counter == 0) {
                lockMachine();
            }            
            }


            while (flagService) {
                clearConsole();
                printServiceMenu();

                choice = inputNumber(choice, "number");

                if (choice == 1) {  //Money
                    clearConsole();
                    printBalance(balance + balanceInMachine, "money");

                    pause();
                }
                else if (choice == 2) {   //Cups
                    clearConsole();
                    cups = inputMaterials(cups, "cups");  //max 700 pcs
                }
                else if (choice == 3) {   //Withdraw money
                    clearConsole();
                    transaction(balanceInMachine, balanceInMachine, moneyTakenOut);
                    transaction(balance, balance, moneyTakenOut);

                    cout << "Operation completed successfully !!! Money withdrawn: " << moneyTakenOut << " BYN" << endl;

                    moneyTakenOut = 0;
                    pause();
                }
                else if (choice == 4) {   //Exit
                    flagService = false;
                }
                else {
                    cout << "Incorrect input!!!" << endl;
                }
            }










            /*printPinMenu();
            
            choice = inputNumber(choice);
            if (choice == 1) {
                if (isPinRightEntered()) {
                    flagService = true;
                    while (flagService) {
                        clearConsole();
                        printServiceMenu();

                        choice = inputNumber(choice);

                        if (choice == 1) {  //Money
                            clearConsole();
                            printBalance(balance + balanceInMachine, "money");

                            pause();
                        } else if (choice == 2) {   //Cups
                            clearConsole();
                            cups = inputMaterials(cups, "cups");  //max 700 pcs
                        } else if (choice == 3) {   //Withdraw money
                            clearConsole();
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
                        clearConsole();
                        cout << "The machine is locked after 3 attempts to enter the wrong pin...";
                        cin >> tmp;
                    }
                }
            } else {}*/

        }
    }
}

void printBalance(double material, string nameOfMaterial) {
    cout << "Balance of " << nameOfMaterial << ": " << material << endl;
}

void printWarningIfNoCups(int cups) {
    cout << "**********************************************************************" << endl;

    if (cups < 4) {
        cout << "***************** Warning! Only " << cups << " cups left in machine ***************" << endl;
    }
    else if (cups == 0) {
        cout << "*********************** Warning! NO cups. ****************************" << endl;
        cout << "*** Do not order coffee, otherwise you will be wasting your money. ***" << endl;
    }
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
    cout << "Enter " << word << ": ";
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
            cout << "Too many " << nameOfMaterial << ". You can add " << 700 - material << endl;
            pause();
        } else if (input > 0) {
           material += input;
        }
        else if (input == 0){
           break;
        }
        else {}
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

void printPinMenu() {
    cout << "1. Enter PIN." << endl;
    cout << "0. Exit." << endl;
}

bool isPinRightEntered() {
    int pin = 0, counter = 0;
    bool flag = false;

    while (counter < 3) {
        clearConsole();

        pin = inputNumber(pin, "PIN");

        if (pin == PIN) {
            flag = true;
            break;
        }
        counter++;
    }
    return flag;
}

void printServiceMenu() {
    cout << "Service menu: " << endl;
    cout << "1. Balance of money in machine" << endl;
    cout << "2. Check/Change the number of cups" << endl;
    cout << "3. Withdraw money from the machine" << endl;
    cout << "4. Exit the Service menu" << endl;
}

void clearConsole()
{
    system("cls");
}

int inputPin(int pin)
{
    cout << "Enter PIN: ";
    cin >> pin;
        
    return pin;
}

void lockMachine(){
    while (true) {  //maybe one function like lockMachine();
        int tmp;
        clearConsole();
        cout << "The machine is locked after 3 attempts to enter the wrong pin...";
        cin >> tmp;
    }
}