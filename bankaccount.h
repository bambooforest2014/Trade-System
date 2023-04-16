#pragma once
#include <iostream>
#include <cstring>
#include <string.h>
using namespace std;

class Bank
{
private:
	int account = 0;
	double balance = 0;

	int apple = 0;
	int melon = 0;

public:
	Bank(int accountl)
	{
		account = accountl;
	}
	~Bank()
	{}

	void show();
	int getaccount() { return account; }

	void deposit(double num);
	void withdraw(double num);
	double getbalance() { return balance; }

	int getapple() { return apple; }
	void buyapple(int num);
	int getmelon() { return melon; }
	void buymelon(int num);
};

void Bank::show()
{
	cout << "BANK ACCOUNT"  << endl;
	cout << "Account:\t" <<getaccount() << endl;
	cout << "Balance:\t" << getbalance() << endl;
	cout << endl;
}

void Bank::deposit(double num)
{
	balance += num;
}
void Bank::withdraw(double num)
{
	balance -= num;
}

void Bank::buyapple(int num)
{
	apple += num;
}
void Bank::buymelon(int num)
{
	melon += num;
}
