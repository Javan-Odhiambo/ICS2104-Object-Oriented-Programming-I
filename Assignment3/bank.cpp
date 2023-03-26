#include "bank.hpp"
#include <cstdio>
using namespace std;

void Bank::print_menu()
{
	cout << "+----------------------BANK-------------------------------+" << endl;
	cout << "|1.New Customer   \t|\t" << "5.List Customers          |" << endl;
	cout << "|2.Deposit        \t|\t" << "6.Delete Customer         |" << endl;
	cout << "|3.Withdraw       \t|\t" << "7.Update Customer Details |" << endl;
	cout << "|4.Check Balance  \t|\t" << "8.Exit System             |\n" << endl;
	cout << "Please select an operation from the menu above: " << endl;
	cout << ">>> ";
}

void Bank::menu()
{
	int choice;

	print_menu();
	cin >> choice;
	switch (choice)
	{
	case 1:
		new_customer();
		break;
	case 2:
		deposit();
		break;
	case 3:
		withdraw();
		break;
	case 4:
		check_balance();
		break;
	case 5:
		list_customers();
		break;
	case 6:
		delete_customer();
		break;
	// case 7:
	// 	update_customer_details();
	// 	break;
	case 8:
		cout << "Thank you for using the bank :)" << endl;
		exit_system();
		break;
	default:
		cout << "Invalid choice," << endl;
		break;
	}
	menu();
}

int Bank::new_customer()
{
	int account_type;
	int confirmation;

	cout << "What type of account would you like to create?\n1.Savings account\n2.Current account" <<endl;
	cin >> account_type;

	cout << "You will need to deposit $1000 for account activation.\nIs that okay with you?\n1.Yes\n2.No" <<endl;
	cin >> confirmation;

	if (confirmation == 1)
		if (account_type == 1)
		{
			Savings saving_account;
		}
		else if (account_type == 2)
		{
			Current current_account;
		}
		else
			cout << "Invalid Choice: "<< endl;

	return (0);

}

int Bank::deposit()
{
	string name;
	char type;
	double amount;
	string message;


	cout << "What type of account do you want to deposit in?\n1.Savings\n2.Current" << endl;
	cin >> type;
	cout << "Enter the name of the customer: ";
	cin >> name;
	cout << "Enter amount to deposit: ";
	cin >> amount;

	message = "Deposit: " + to_string(amount);

	if (type == '1')
	{
		Savings sav(name);
		sav.deposit(amount);
		sav.update(message);
		cout << "Deposit was successful\nNew balance is: " << sav.get_amount() << endl;
	}
	else if (type == '2')
	{
		Current curr(name);

		curr.deposit(amount);
		curr.update(message);
		cout << "Deposit was successful\nNew balance is: " << curr.get_amount() << endl;
	}
	else
	{
		cout << "invalid choice" << endl;
	}
	return (0);
}

int Bank::withdraw()
{
	string name;
	char type;
	double amount;
	string message;


	cout << "What type of account do you want to withdraw from?\n1.Savings\n2.Current" << endl;
	cin >> type;
	cout << "Enter the name of the customer: ";
	cin >> name;
	cout << "Enter amount to withdraw: ";
	cin >> amount;

	message = "Withdraw " + to_string(amount);

	if (type == '1')
	{
		Savings sav(name);
		if (sav.withdraw(amount) == 0)
			sav.update(message);
		else
			withdraw();
	}
	else if (type == '2')
	{
		Current curr(name);

		if (curr.withdraw(amount) == 0)
			curr.update(message);
		else
			withdraw();
	}
	else
	{
		cout << "invalid choice" << endl;
	}
	return (0);
}

int Bank::check_balance()
{
	string name;
	char type;

	cout << "What type of account do you want to the balance of?\n1.Savings\n2.Current" << endl;
	cin >> type;
	cout << "Enter the name of the customer: ";
	cin >> name;

		if (type == '1')
	{
		Savings sav(name);
		cout << "Your balance is: " << sav.get_amount() << endl;
	}
	else if (type == '2')
	{
		Current curr(name);
		cout << "Your balance is: " << curr.get_amount() << endl;
	}
	else
	{
		cout << "invalid choice" << endl;
	}
	return (0);
}

int Bank::list_customers()
{
	ifstream file;
	string buff;

	cout << "Savings account Customers: " << endl;
	file.open("./Savings_customer_list.txt");
	while (getline(file, buff))
		cout << buff << endl;
	file.close();

	cout << "\nCurrent account Customers: " << endl;
	file.open("./Current_customer_list.txt");
	while (getline(file, buff))
		cout << buff << endl;
	file.close();

	return (0);

}
int Bank::delete_customer()
{
	string name;
	string path;
	char type;

	cout << "What type of account do you want to the balance of?\n1.Savings\n2.Current" << endl;
	cin >> type;
	cout << "Enter the name of the customer: ";
	cin >> name;

	if (type == '1')
	{
		path = "./savings/" + name;
		remove(path.c_str());
	}
	else if (type == '2')
	{
		path = "./current/" + name;
		remove(path.c_str());
	}
	else
	{
		cout << "invalid choice" << endl;
	}
	return (0);
}
void Bank::exit_system()
{
	exit(0);
}
