#include <iostream>
#include <vector>
using namespace std;

struct StockItem {
    string name;
    int quantity;
    double price;
    int sold;
    double total;
};

int main(){
    int quantity = 5;
    int choix = 2;

    vector<StockItem> options = {
        {"Room", 10, 2.5, 0, 0.0},
        {"Suite", 5, 5.0, 0, 0.0},
        {"Deluxe", 2, 10.0, 0, 0.0}
    };

    for (auto& current : options) {
        std:cout << current.name << endl;
        cin >> current.sold;
        current.total = current.sold * current.price;
        std::cout << "Total for " << current.name << ": " << current.total << endl;
    }

    return 0;
}