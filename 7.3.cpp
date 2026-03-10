#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
class Currency {
public:
    double amount;
    string currencyCode;
    string currencySymbol;
    double exchangeRate;
    Currency(double amt, string code, string symbol, double rate) 
        : amount(amt), currencyCode(code), currencySymbol(symbol), exchangeRate(rate) {}
    virtual double convertToBase() {
        return amount / exchangeRate;
    }
    virtual void displayCurrency() {
        cout << currencySymbol << fixed << setprecision(2) << amount << " (" << currencyCode << ")" << endl;
    }
};
class Dollar : public Currency {
public:
    Dollar(double amt) : Currency(amt, "USD", "$", 1.0) {}
    double convertToBase() override {
        return amount; 
    }
    void displayCurrency() override {
        cout << "US Format: " << currencySymbol << fixed << setprecision(2) << amount << endl;
    }
};
class Euro : public Currency {
public:
    Euro(double amt) : Currency(amt, "EUR", "€", 0.92) {}
    double convertToBase() override {
        return amount / exchangeRate;
    }
    void displayCurrency() override {
        cout << "European Format: " << amount << " " << currencySymbol << endl;
    }
};
class Rupee : public Currency {
public:
    Rupee(double amt) : Currency(amt, "PKR", "Rs.", 278.50) {}
    double convertToBase() override {
        return amount / exchangeRate;
    }
    void displayCurrency() override {
        cout << "Local Format: " << currencySymbol << " " << fixed << setprecision(0) << amount << endl;
    }
};
int main() {
    double inputAmount;
    cout << "Enter an amount in Dollars: ";
    cin >> inputAmount;
    Dollar myCash(inputAmount);
    Euro myTravelMoney(inputAmount * 0.92);
    Rupee myLocalCash(inputAmount * 278.50);
    cout << "\n--- Currency Accounts ---" << endl;
    myCash.displayCurrency();
    myTravelMoney.displayCurrency();
    myLocalCash.displayCurrency();
    return 0;
}
