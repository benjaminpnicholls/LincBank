#include "current.h"
//#include "historyinfo.cpp"


current::current() {
	balance = 0;
	overdraft = 0;
	historyinfo *hi = new historyinfo("Open Current Account", balance);
	history.push_back(hi);
	//delete hi; //will this delete the data or just the pointer?
}


current::current(double initialDeposit) {
	if (initialDeposit < 0) {
		throw std::exception{ "Initial deposit for a current account cannot be negative." };
	}
	balance = initialDeposit;
	overdraft = 0;
	historyinfo* hi = new historyinfo("Open Current Account", balance);
	history.push_back(hi);
}


current::~current() {
}


bool current::deposit(double amount) {
	if (amount <= 0) { return false; }

	double a = amount - overdraft;
	if (a > 0) {
		overdraft = 0;
		balance += a;
	} else {
		overdraft = -a;
	}

	historyinfo* hi = new historyinfo("Deposit", amount);
	history.push_back(hi);
	return true;

}


bool current::withdraw(double amount) {
	if (amount <= 0) { return false; }
	if (balance + overdraftLimit - overdraft <= amount) { return false; }

	balance -= amount;
	if (balance < 0) {
		overdraft = -balance;
		balance = 0;
	}

	historyinfo* hi = new historyinfo("Withdraw", amount);
	history.push_back(hi);
	return true;
}


std::string current::toString() {
	return "";
}
