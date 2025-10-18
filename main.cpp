#include <iostream>
#include <vector>
#include <string>
#include "src/Stock.hpp"

using namespace std;


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



int main(){
    vector<Stock> inventory;
    inventory.emplace_back("simple room", 25, 24.99);
    inventory.emplace_back("deluxe room", 15, 49.99);
    inventory.emplace_back("suite", 10, 99.99);

    cout << "Welcome to the Hotel Management System!" << endl;
    cout << "--------------------------------------" << endl;
    cout << "choix %d" << menu() << endl;

    return 0;
}