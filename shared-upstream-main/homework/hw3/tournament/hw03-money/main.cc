#include "money.h"

int main() {
    Money m1 = Money(12.75);
    Money m2 = Money(1.25, "AUD");

    std::cout << m1.getUSD() << std::endl;
    std::cout << m2.getUSD() << std::endl;
    std::cout << m2.getAUD() << std::endl;

    std::cout << std::endl << "Operators" << std::endl;
    std::cout << (m1 + m2).getUSD() << std::endl;
    std::cout << (m1 - m2).getUSD() << std::endl;
    std::cout << (m1 * 2).getUSD() << std::endl;
    std::cout << (m2 * 2).getUSD() << std::endl;
    std::cout << (m1 / 2).getUSD() << std::endl;
    std::cout << (m2 / 2).getUSD() << std::endl;

    std::cout << std::endl << "Relational" << std::endl;
    std::cout << (m1 == m2) << std::endl;
    std::cout << (m1 != m2) << std::endl;
    std::cout << (m1 > m2) << std::endl;
    std::cout << (m1 < m2) << std::endl;

    std::cout << std::endl << "Functions" << std::endl;
    m1.addTax();
    std::cout << m1.getUSD() << std::endl;
    m1.removeLargestDenomination();
    std::cout << m1.getUSD() << std::endl;
    m1.buyMeal();
    std::cout << m1.getUSD() << std::endl;

    std::cout << std::endl << "Conversions" << std::endl;
    std::cout << m1.getUSD() << std::endl;
    std::cout << m1.getAUD() << std::endl;
    std::cout << m1.getRUB() << std::endl;
    std::cout << m1.getCAD() << std::endl;
    std::cout << m1.getGBP() << std::endl;
    std::cout << m1.getJPY() << std::endl;

}
