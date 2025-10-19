#include <iostream>
#include <vector>
#include <string>
#include "src/Stock.hpp"

using namespace std;


vector<Stock> inventory;

int menu(){
    int choice;
    cout << "Menu:" << endl;
    cout << "1. Chambre disponible" << endl;
    cout << "2. Chambre occupées" << endl;
    cout << "3. Compta" << endl;
    cout << "4. Exit" << endl;
    cout << "Enter your choice: ";
    cin >> choice;
    return choice;
}

void hub(){
    bool flag = true;
    while (flag){
        switch (menu()){
            case 1:
                cout << "Chambre disponible" << endl;
                cout << "Available Stocks: " << Stock::getAvailableStocks() << endl;
                break;
            case 2:
                cout << "Chambre occupées" << endl;
                break;
            case 3:
                cout << "Compta" << endl;
                break;
            case 4:
                flag = false;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }
}




int main(){

    inventory.emplace_back("simple room", 25, 24.99);
    inventory.emplace_back("deluxe room", 15, 49.99);
    inventory.emplace_back("suite", 10, 99.99);

    cout << "Welcome to the Hotel Management System!" << endl;
    cout << "--------------------------------------" << endl;
    hub();

    return 0;
}