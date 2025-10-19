#ifndef DEF_STOCK
#define DEF_STOCK

#include <iostream>
#include <string>

class Stock {
    private:
        std::string name;
        int quantity;
        double price;
        int sold;
        double total;
        static int availableStocks;

    public:
        Stock(std::string n, int q, double p);
        void sell(int amount);
        void displayTotal() const;
        std::string getName() const;
        double getPrice() const;
        int getQuantity() const;
        int getSold() const;
        double getTotal() const;
        static int getAvailableStocks();
};
#endif // DEF_STOCK