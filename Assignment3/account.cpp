#include "bank.hpp"
#include <random>
#include <sstream>

int Account::generate_account_number()
{
	srand((unsigned) time(NULL));
	return (10000 + (rand() % 90000));
}

string Account::retrieve_records(string name, string type)
{
	string filename = "./" + type + "/" + name;
    ifstream fin;
    fin.open(filename);
	string lastLine;
	string trav;

	while(getline(fin,trav))
	{
		lastLine = trav;
	}
	fin.close();
	return (lastLine);
}


int Account::get_account_number(){return (account_number);}
void Account::set_amount(double new_amount){amount = new_amount;}
double Account::get_amount(){return (amount);}
string Account::get_customer_name(){return (customer_name);}
string Account::get_account_type(){return (account_type);}




