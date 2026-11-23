#include <iostream>
#include <string>
#include <iomanip>

class Product;

class Currency {
private:
    std::string name;
    double amount;
    long long cents;

public:
    Currency() : name("USD"), amount(0.0), cents(0) {}
    
    Currency(std::string n, double a) : name(n), amount(a) {
        cents = static_cast<long long>(amount * 100) % 100;
    }

    void input() {
        std::cout << "Enter currency name: ";
        std::cin >> name;
        std::cout << "Enter amount: ";
        std::cin >> amount;
        cents = static_cast<long long>(amount * 100) % 100;
    }

    void print() const {
        std::cout << std::fixed << std::setprecision(2);
        std::cout << amount << " " << name;
    }

    Currency operator+(const Currency& other) const {
        if (name != other.name) {
            std::cerr << "Error: Cannot add different currencies without conversion.\n";
            return *this;
        }
        return Currency(name, amount + other.amount);
    }

    Currency operator-(const Currency& other) const {
        if (name != other.name) {
            std::cerr << "Error: Cannot subtract different currencies without conversion.\n";
            return *this;
        }
        return Currency(name, amount - other.amount);
    }

    friend void exchangeCurrency(Currency& curr, const std::string& targetName, double rate);
};

class Product {
private:
    std::string name;
    double price;
    std::string currencyName;
    std::string unit;

public:
    Product() : name("Unknown"), price(0.0), currencyName("USD"), unit("pcs") {}
    
    Product(std::string n, double p, std::string c, std::string u) 
        : name(n), price(p), currencyName(c), unit(u) {}

    void input() {
        std::cout << "Enter product name: ";
        std::cin >> name;
        std::cout << "Enter price: ";
        std::cin >> price;
        std::cout << "Enter currency: ";
        std::cin >> currencyName;
        std::cout << "Enter unit (e.g. kg, pcs): ";
        std::cin >> unit;
    }

    void print() const {
        std::cout << "Product: " << name 
                  << ", Price: " << std::fixed << std::setprecision(2) << price << " " << currencyName 
                  << ", Unit: " << unit;
    }

    Product operator+(const Product& other) const {
        if (currencyName != other.currencyName) {
            std::cerr << "Error: Cannot add products in different currencies.\n";
            return *this;
        }
        if (name != other.name || unit != other.unit) {
            std::cerr << "Error: Cannot add different products or units.\n";
            return *this;
        }
        return Product(name, price + other.price, currencyName, unit);
    }

    Product operator-(const Product& other) const {
        if (currencyName != other.currencyName) {
            std::cerr << "Error: Cannot subtract products in different currencies.\n";
            return *this;
        }
        if (name != other.name || unit != other.unit) {
            std::cerr << "Error: Cannot subtract different products or units.\n";
            return *this;
        }
        return Product(name, price - other.price, currencyName, unit);
    }

    friend void exchangeCurrency(Product& prod, const std::string& targetName, double rate);
};

void exchangeCurrency(Currency& curr, const std::string& targetName, double rate) {
    std::cout << "Exchanging " << curr.name << " to " << targetName << " at rate " << rate << "...\n";
    curr.amount *= rate;
    curr.name = targetName;
    curr.cents = static_cast<long long>(curr.amount * 100) % 100;
}

void exchangeCurrency(Product& prod, const std::string& targetName, double rate) {
    std::cout << "Exchanging product price from " << prod.currencyName << " to " << targetName << "...\n";
    prod.price *= rate;
    prod.currencyName = targetName;
}

int main() {
    std::cout << "=== Task 10: Currency and Product ===\n\n";

    Currency usd1("USD", 100.50);
    Currency usd2("USD", 50.25);
    
    std::cout << "Currency 1: "; usd1.print(); std::cout << "\n";
    std::cout << "Currency 2: "; usd2.print(); std::cout << "\n";
    
    Currency sum = usd1 + usd2;
    std::cout << "Sum: "; sum.print(); std::cout << "\n";
    
    Currency diff = usd1 - usd2;
    std::cout << "Difference: "; diff.print(); std::cout << "\n\n";

    Product apple1("Apple", 2.50, "USD", "kg");
    Product apple2("Apple", 1.50, "USD", "kg");
    
    std::cout << "Product 1: "; apple1.print(); std::cout << "\n";
    std::cout << "Product 2: "; apple2.print(); std::cout << "\n";
    
    Product totalPrice = apple1 + apple2;
    std::cout << "Total price: "; totalPrice.print(); std::cout << "\n\n";

    std::cout << "--- Currency Exchange ---\n";
    exchangeCurrency(sum, "EUR", 0.92);
    std::cout << "Currency after exchange: "; sum.print(); std::cout << "\n";
    
    exchangeCurrency(totalPrice, "EUR", 0.92);
    std::cout << "Product after exchange: "; totalPrice.print(); std::cout << "\n";

    return 0;
}