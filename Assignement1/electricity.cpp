#include <iostream>
#include <string>

void calculate_charges(double* charges, unsigned int units);

int main(void)
{
    char name[50];
    unsigned int units;
    double charges = 0;

    std::cout << "Enter your name: ";
    std::cin.getline(name, 50);
    std::cout << "Enter your electricity units: ";
    std::cin >> units;

    calculate_charges(&charges, units);
    std::cout << "\nYour charges are: " << charges << std::endl;

    return (0);
}

void calculate_charges(double* charges, unsigned int units)
{
    // Calculate charges
    if (units <= 100) {
        *charges = units * 60.0;
    } else if (units <= 300) {
        *charges = 6000.0 + (units - 100) * 80.0;

    } else {
        *charges = 6000.0 + 16000.0 + (units - 300) * 90.0;

    }

    if (*charges < 50.0) {
        *charges = 50.0;
    }

    if (*charges > 300.0) {
        *charges *= 1.15;
    }

}
