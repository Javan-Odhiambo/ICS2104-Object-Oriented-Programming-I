#include "bank.hpp"
#include <string.h>
#include <math.h>

Savings::Savings(string name)
{
	string base;
	string path;
	fstream file;

	base = "./savings/";
	path = base + name;
	file.open(path, ios::in);

	if (file.fail())
	{
		cout << "Savings Account for " << name << " does not exist." << endl;
		file.close();
	}
	else
	{
		string record;
		record = retrieve_records(name, "savings");
		char *dup = strdup(record.c_str());
		customer_name = strtok(dup, " ");
		account_number = atoi(strtok(NULL, " "));
		amount = atoi(strtok(NULL, " "));
		account_type = strtok(NULL, " ");

	}
}

Savings::Savings()
{
	string base;
	string path;
	char name[20];
	fstream file;

	cout << "Enter name of the customer: ";
	cin >> name;

	for (int i; i < strlen(name); i++)
		name[i] = toupper(name[i]);

	base = "./savings/";
	path = base + name;
	file.open(path, ios::in);

	if (file.fail())
	{
		file.open(path, ios::out);
		file << name << " " << generate_account_number() << " " << "1000 " << "savings\n";
		cout << "Savings Account successfully created for " << name << endl;
		file.close();

		file.open("./Savings_customer_list.txt", ios::app);
		file << name << '\n';
		file.close();

	}
	else
	{
		cout << "Error: Account already exists" << endl;
	}

}

void Savings::deposit(float amount)
{
	int time;

	cout << "How long will you be saving the amount? ";
	cin >> time;
	cout << "Your interest will be: " << compute_compound_interest(amount, time) << endl;

	set_amount(get_amount() + amount);
}
double Savings::compute_compound_interest(double amount, int time)
{
	double interest;
	interest = amount * pow(1.12, time);
	return interest;
}

void Savings::update(string message)
{
	string base;
	string path;
	string name;
	fstream file;

	name = get_customer_name();
	base = "./savings/";
	path = base + name;
	file.open(path, ios::app);

	if (!file.fail())
	{
		file << get_customer_name() << " " << get_account_number() << " " << get_amount() << " savings " << message << "\n";
	}
	file.close();

}
int Savings::withdraw(float amount)
{
	if (get_amount() > amount)
	{
		set_amount(get_amount() - amount);
		cout << "Withdrawal was successful\nNew balance is: " << get_amount() << endl;
	}
	else
	{
		cout << "You do not have enough funds to withdraw " << (int) amount << endl;
	}

	return (0);
}
