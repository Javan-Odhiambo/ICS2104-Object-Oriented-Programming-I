#include "bank.hpp"
#include <string.h>

Current::Current()
{
	string base;
	string path;
	string name;
	fstream file;

	cout << "Enter name of the customer: ";
	cin >> name;
	for (int i; i < name.length(); i++)
		name[i] = toupper(name[i]);

	base = "./current/";
	path = base + name;
	file.open(path, ios::in);

	if (file.fail())
	{
		file.open(path, ios::out);
		file << name << " " << generate_account_number() << " " << "1000 " << "current\n";
		cout << "Current Account successfully created for " << name << endl;
		file.close();

		file.open("./Current_customer_list.txt", ios::app);
		file << name << '\n';
		file.close();

	}
	else
	{
		cout << "Error: Account already exists" << endl;
	}
}
Current::Current(string name)
{
	string base;
	string path;
	fstream file;

	base = "./current/";
	path = base + name;
	file.open(path, ios::in);

	if (file.fail())
	{
		cout << "Current Account for " << name << " does not exist." << endl;
		file.close();
	}
	else
	{
		string record;
		record = retrieve_records(name, "current");
		char *dup = strdup(record.c_str());
		customer_name = strtok(dup, " ");
		account_number = atoi(strtok(NULL, " "));
		amount = atoi(strtok(NULL, " "));
		account_type = strtok(NULL, " ");
	}

}

void Current::update(string message)
{
	string base;
	string path;
	string name;
	fstream file;

	name = get_customer_name();
	base = "./current/";
	path = base + name;
	file.open(path, ios::app);

	if (!file.fail())
	{
		file << get_customer_name() << " " << get_account_number() << " " << get_amount() << " current " << message << "\n";
	}
	file.close();
}



void Current::deposit(float amount)
{
	set_amount(get_amount() + amount);
}

int Current::withdraw(float amount)
{
	if (get_amount() > amount)
	{
		set_amount(get_amount() - amount);
		cout << "Withdrawal was successful\nNew balance is: " << get_amount() << endl;

		if (get_amount() < 500)
		{
			cout << "A service charge of $40 will be deducted from your account." << endl;
			cout << "Select an option\n1.Confirm\n2.Cancel" << endl;
			char c;
			cin >> c;

			if (c == '1')
				set_amount(get_amount() - 40);
			else
				return (1);
		}
	}
	else
	{
		cout << "You do not have enough funds to withdraw " << (int) amount << endl;
	}

	return (0);
}

