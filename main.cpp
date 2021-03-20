#include <iostream>

using namespace std;

#define ESPRESSO_PRICE 1.5
#define CAPPUCCINO_PRICE 2.5
#define LATTE_PRICE 3.0
#define PIN 1234


int main() {
    bool flag = true;
    int choose = 0, sugar = 0, cups = 7, attempts = 3, insertCups = 0;
    double balance = 0.0, cash = 0, money = 0.0, moneyTakenOut = 0.0;

    while (true) {
        do {
            flag = true;
            if (cups == 0) {
                cout << "WARNING! There are NO cups in the coffee machine." << endl;
            }
            cout << "           Balance: " << balance << " BYN" << endl;
            cout << "1. Espresso " << ESPRESSO_PRICE << " BYN\n" << "2. Cappuccino " << CAPPUCCINO_PRICE << " BYN\n"
                 << "3. Latte " << LATTE_PRICE << " BYN\n" << "4. Put money\n" << "5. Service\n" << endl;
            cout << "Input: ";
            cin >> choose;
        } while (choose < 1 or choose > 5);
        switch (choose) {
            case 1: //Espresso
                while (cash != 0 or balance > ESPRESSO_PRICE) {
                    if (balance < ESPRESSO_PRICE) {
                        cout << "Not enough money!!! " << ESPRESSO_PRICE - balance << " BYN left.\n0 - Exit" << endl;
                        cout << endl;
                        cout << "Bill acceptor: ";
                        cin >> cash;
                        balance += cash;
                        if (cash == 0) {
                            break;
                        }
                    } else {
                        if (cups == 0) {
                            balance -= ESPRESSO_PRICE;
                            money += ESPRESSO_PRICE;
                            cups--;
                            break;
                        }
                        balance -= ESPRESSO_PRICE;
                        money += ESPRESSO_PRICE;
                        cups--;
                        cout
                                << "Enter the number of spoons of sugar(0 - if sugar-free;1-5 the number of tablespoons of sugar): ";
                        cin >> sugar;
                        cout << "Your coffee with " << sugar << " spoon(s) of sugar is ready! Have a nice day!!!"
                             << endl;
                        break;
                    }
                }
                break;
            case 2: //Cappuccino
                //the same code like for espresso
                while (cash != 0 or balance > CAPPUCCINO_PRICE) {
                    if (balance < CAPPUCCINO_PRICE) {
                        cout << "Not enough money!!! " << CAPPUCCINO_PRICE - balance << " BYN left.\n0 - Exit" << endl;
                        cout << endl;
                        cout << "Bill acceptor: ";
                        cin >> cash;
                        balance += cash;
                        if (cash == 0) {
                            break;
                        }
                    } else {
                        if (cups == 0) {
                            balance -= CAPPUCCINO_PRICE;
                            money += CAPPUCCINO_PRICE;
                            cups--;
                            break;
                        }
                        balance -= CAPPUCCINO_PRICE;
                        money += CAPPUCCINO_PRICE;
                        cups--;
                        cout
                                << "Enter the number of spoons of sugar(0 - if sugar-free;1-5 the number of tablespoons of sugar): ";
                        cin >> sugar;
                        cout << "Your coffee with " << sugar << " spoon(s) of sugar is ready! Have a nice day!!!"
                             << endl;
                        break;
                    }
                }
                break;
            case 3: //Latte
                //the same code like for espresso
                while (cash != 0 or balance > LATTE_PRICE) {
                    if (balance < CAPPUCCINO_PRICE) {
                        cout << "Not enough money!!! " << LATTE_PRICE - balance << " BYN left.\n0 - Exit" << endl;
                        cout << endl;
                        cout << "Bill acceptor: ";
                        cin >> cash;
                        balance += cash;
                        if (cash == 0) {
                            break;
                        }
                    } else {
                        if (cups == 0) {
                            balance -= LATTE_PRICE;
                            money += LATTE_PRICE;
                            cups--;
                            break;
                        }
                        balance -= LATTE_PRICE;
                        money += LATTE_PRICE;
                        cups--;
                        cout
                                << "Enter the number of spoons of sugar(0 - if sugar-free;1-5 the number of tablespoons of sugar): ";
                        cin >> sugar;
                        cout << "Your coffee with " << sugar << " spoon(s) of sugar is ready! Have a nice day!!!"
                             << endl;
                        break;
                    }
                }
                break;
            case 4: //Put money
                while (cash != 0) {
                    cout << "           Balance: " << balance << " BYN" << endl;
                    cout << "0 - Exit" << endl;
                    cout << endl;
                    cout << "Bill acceptor: ";
                    cin >> cash;
                    balance += cash;
                }
                break;
            case 5: //Service
                int input = 0;
                while (input != PIN) {
                    if (attempts == 0) {
                        while (true) {
                            int tmp;
                            cout << "The machine is locked after 3 attempts to enter the wrong pin...";
                            cin >> tmp;
                        }
                    }
                    cout << "Enter PIN (" << attempts << " attempts left): ";
                    cin >> input;
                    attempts--;
                    while (flag) {
                        flag = true;
                        do {
                            attempts = 3;
                            cout << "Service menu:" << endl;
                            cout << "1. Balance\n" << "2. Cups\n3. Extract cash\n4. Back" << endl;
                            cout << endl;
                            cout << "Input: ";
                            cin >> choose;
                        } while (choose < 1 or choose > 4);
                        switch (choose) {
                            case 1: //Balance
                                cout << "Total money: " << money << endl;
                                break;
                            case 2: //Cups
                                while (true) {
                                    cout << "Number of cups: " << cups << "\n0 - Exit" << endl;
                                    cout << endl;
                                    cout << "Cups acceptor: ";
                                    cin >> insertCups;
                                    cups += insertCups;
                                    if (insertCups == 0) {
                                        flag = true;
                                        break;
                                    }
                                }
                                break;
                            case 3: //Extract cash
                                cout << "Operation completed successfully!" << endl;
                                moneyTakenOut += money + balance;
                                money = 0;
                                balance = 0;
                                flag = false;
                                break;
                            case 4: //Exit
                                flag = false;
                                break;
                        }
                    }
                }
                break;
        }
//        return 0;
    }
}