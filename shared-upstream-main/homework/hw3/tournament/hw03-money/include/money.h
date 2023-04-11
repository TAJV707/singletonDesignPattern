#ifndef MONEY_H_
#define MONEY_H_

#include <string>
#include <iostream>

class Money {
    public:
        // Constructors
        Money();
        Money(double usd);
        Money(double amount, const std::string& type);

        // Actual functions
        /**
         * Adds a 6.875% sales tax.
         */
        void addTax();

        /**
         * Purchases a $8.50 meal if there is enough money.
         */
        void buyMeal();

        /**
         * Removes the largest USD denomination ($100, $50, $20, $10, $5, $2, $1).
         */
        void removeLargestDenomination();

        // Getters
        double getUSD() const;
        double getJPY() const;
        double getGBP() const;
        double getAUD() const;
        double getCAD() const;
        double getRUB() const;

        // Operator overloads
        Money operator+(const Money& other) const;
        Money operator-(const Money& other) const;
        Money operator*(int other) const;
        Money operator/(int other) const;
        Money operator%(int denomination) const;
        bool operator>(const Money& other) const;
        bool operator<(const Money& other) const;
        bool operator>=(const Money& other) const;
        bool operator<=(const Money& other) const;
        bool operator==(const Money& other) const;
        bool operator!=(const Money& other) const;

    private:
        double usd;
};

#endif //MONEY_H_
