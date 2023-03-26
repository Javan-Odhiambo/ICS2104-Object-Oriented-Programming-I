#include <iostream>
#include <cstring>
#include <cmath>
#define RATE 0.16

using namespace std;

int get_operation(char *name, char *reg);
int get_details(char name[], char reg[]);
void get_more_details(char *name, char *reg, float* principle, int* years);
void calculate_savings(float *principle, int *years, float *interest, float *acured);
void calculate_fixed(float *principle, int *years, float *interest, float *acured);
int print(char *name, char *reg, float *principle, float *interest, float *acured);
void print_heading(char *name, char *reg);

int main(void)
{
    int op;
    int years;
    float interest;
    float principle;
    float acured;
    char name[50], reg[20];

    get_details(name, reg);
    op = get_operation(name, reg);
    get_more_details(name, reg, &principle, &years);
    if (op == 1)
    {
        calculate_savings(&principle, &years, &interest, &acured);
    }
    else
    {
        calculate_fixed(&principle, &years, &interest, &acured);
    }
    print(name, reg, &principle, &interest, &acured);
    return (0);
}

int get_operation(char *name, char *reg)
{
    int op;

    print_heading(name, reg);
    cout << "Where would you like to deposit money in today saving or fixed account?" << endl;
    cout << "1. Saving Account" << endl;
    cout << "2. Fixed deposit Account" << endl;
    cin >> op;

    if (!(op == 1 || op == 2))
    {
        cout << "\nError, Your input is incorrect" << endl;
        cout << "Please enter a valid option:\n " << endl;
        cout << " >> ";
        op = get_operation(name, reg);
    }

    return (op);
}

int get_details(char name[], char reg[])
{
    cout << "Enter your name: " ;
    cin.getline(name, 50);
    cout << "Enter your Registration Number: " ;
    cin >> reg;

    if (strlen(name) < 2)
    {
        cout << "\nYou entered an invalid name" << endl;
        get_details(name, reg);
    }

    return (0);
}
void get_more_details(char *name, char *reg, float* principle, int* years)
{
    print_heading(name, reg);
    cout << "Enter the principle amount: " ;
    cin >> *principle;
    cout << "Enter the number of years you wish to keep your money: " ;
    cin >> *years;
}

void calculate_savings(float *principle, int *years, float *interest, float *acured)
{
    *interest = *principle * RATE * *years;
    *acured = *principle + *interest;
}

void calculate_fixed(float *principle, int *years, float *interest, float *acured)
{
    *acured = *principle * pow((1 + RATE), *years);
    *interest = *acured - *principle;
}

int print(char *name, char *reg, float *principle, float *interest, float *acured)
{
    print_heading(name, reg);
    printf("PRINCIPLE: %.2f\n", *principle);
    printf("INTEREST: %.2f\n", *interest);
    printf("ACURED AMOUNT: %.2f\n", *acured);

    return(0);
}

void print_heading(char *name, char *reg)
{
    printf("\n---------------------------------------------------------\n");
    printf("NAME: %s\n", name);
    printf("REGISTRATION NUMBER: %s\n", reg);
    printf("---------------------------------------------------------\n");
}
