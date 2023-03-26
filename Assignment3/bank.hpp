#ifndef _BANK_H_
#define _BANK_H_

#include <string>
#include <iostream>
#include <fstream>

using namespace std;


using std::string;

class Bank
{
	private:
		void print_menu();
	protected:
	public:
		void menu();
		int new_customer();
		int deposit();
		int withdraw();
		int check_balance();
		int list_customers();
		int delete_customer();
		// update_customer_details();
		void exit_system();
};

class Account
{
protected:
	string customer_name;
	int account_number;
	string account_type;
	double amount;
	string account_record;

	int generate_account_number();
	string retrieve_records(string name, string type);

	virtual void update(string message)=0;
	virtual void deposit(float amount)=0;
	virtual int withdraw(float amount)=0;

public:
	int get_account_number();
	string get_customer_name();
	string get_account_type();
	double get_amount();
	void set_amount(double new_amount);


	// set_customer_name();

	// print_balance();


};

class Savings : public Account
{
private:
	double compute_compound_interest(double amount, int time);

protected:
public:

	Savings();
	Savings(string name);
	void update(string message);
	void deposit(float amount);
	int withdraw(float amount);

};

class Current : public Account
{
private:
	int service_charge();
	int create_customer_record();
protected:
public:
	Current();
	Current(string name);
	void update(string message);
	void deposit(float amount);

	int withdraw(float amount);

};

#endif /* _BANK_H_ */
