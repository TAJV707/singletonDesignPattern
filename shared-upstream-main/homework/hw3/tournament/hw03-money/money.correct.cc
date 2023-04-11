#include "money.h"
#define EUR_TO_USD 1.08
#define JPY_TO_USD 0.01
#define GBP_TO_USD 1.32
#define AUD_TO_USD 0.74
#define CAD_TO_USD 0.79
#define RUB_TO_USD 0.01

// Constructors
Money::Money() {
    this->usd = 0.0;
}

Money::Money(double usd) {
    this->usd = usd;
}

Money::Money(double amount, const std::string& type) {
    if (type == "EUR") {
        this->usd = amount * EUR_TO_USD;
    }
    else if (type == "JPY") {
        this->usd = amount * JPY_TO_USD;
    }
    else if (type == "GBP") {
        this->usd = amount * GBP_TO_USD;
    }
    else if (type == "AUD") {
        this->usd = amount * AUD_TO_USD;
    }
    else if (type == "CAD") {
        this->usd = amount * CAD_TO_USD;
    }
    else if (type == "RUB") {
        this->usd = amount * RUB_TO_USD;
    }
    else {
        this->usd = amount;
    }
}


// Actual functions
void Money::addTax() {
    this->usd = this->usd * 1.06875;
}

void Money::buyMeal() {
    if (this->usd >= 8.50)
        this->usd = this->usd - 8.50;
    else
        std::cout << "Insufficient funds." << std::endl;
}

void Money::removeLargestDenomination() {
    if (this->usd >= 100)
        this->usd = this->usd - 100;
    else if (this->usd >= 50)
        this->usd = this->usd - 50;
    else if (this->usd >= 20)
        this->usd = this->usd - 20;
    else if (this->usd >= 10)
        this->usd = this->usd - 10;
    else if (this->usd >= 5)
        this->usd = this->usd - 5;
    else if (this->usd >= 2)
        this->usd = this->usd - 2;
    else if (this->usd >= 1)
        this->usd = this->usd - 1;
}


// Getters
double Money::getUSD() const {
    return this->usd;
}

double Money::getJPY() const {
    return this->usd / JPY_TO_USD;
}

double Money::getGBP() const {
    return this->usd / GBP_TO_USD;
}

double Money::getAUD() const {
    return this->usd / AUD_TO_USD;
}

double Money::getCAD() const {
    return this->usd / CAD_TO_USD;
}

double Money::getRUB() const {
    return this->usd / RUB_TO_USD;
}

// Operator overloads
Money Money::operator+(const Money &other) const {
    return Money(this->usd + other.usd);
}

Money Money::operator-(const Money &other) const {
    return Money(this->usd - other.usd);
}

Money Money::operator*(const int other) const {
    return Money(this->usd * other);
}

Money Money::operator/(int other) const {
    return Money(this->usd / other);
}

Money Money::operator%(int denomination) const {
    return Money((int) this->usd % denomination);
}

bool Money::operator>(const Money &other) const {
    return (this->usd > other.usd);
}

bool Money::operator<(const Money &other) const {
    return (this->usd < other.usd);
}

bool Money::operator>=(const Money &other) const {
    return (this->usd >= other.usd);
}

bool Money::operator<=(const Money &other) const {
    return (this->usd <= other.usd);
}

bool Money::operator==(const Money& other) const {
    return (this->usd == other.usd);
}

bool Money::operator!=(const Money &other) const {
    return (this->usd != other.usd);
}
