#include "Stock.hpp"

using namespace std;


Stock::Stock(string n, int q, double p)
    : name(n), quantity(q), price(p), sold(0), total(0.0) {}

void Stock::sell(int amount) {
    if (amount <= quantity) {
        sold += amount;
        quantity -= amount;
        total += amount * price;
    } else {
        std::cout << "Not enough stock for " << name << std::endl;
    }
}

void Stock::displayTotal() const {
    std::cout << "Total for " << name << ": " << total << std::endl;
}

string Stock::getName() const {
    return name;
}

double Stock::getPrice() const {
    return price;
}

int Stock::getQuantity() const {
    return quantity;
}

int Stock::getSold() const {
    return sold;
}

double Stock::getTotal() const {
    return total;
}

