#pragma once
#include <vector>
#include <string>
#include "transaction.h"


class Account {
public:
	Account() {};
	~Account() {};
	virtual bool Deposit(double Amount, int Ref = 0) = 0;
	virtual bool Withdraw(double Amount, int Ref = 0) = 0;
	virtual std::string ToString() const = 0;

protected:
	double m_Balance;
	std::vector<Transaction*> m_History;
	double m_OverdraftLimit = 0;
};


// Custom exceptions.
struct InitialDepositBelowZeroException : public std::exception {
public:
	virtual const char* what() const throw() {
		return "ERROR: Initial deposit must be above £0.00.";
	}
};


struct InitialDepositBelowISARequiredException : public std::exception {
public:
	virtual const char* what() const throw() {
		return "ERROR: Initial deposit must be at least £1000.";
	}
};


struct DynamicCastUnsuccessfulException : public std::exception {
public:
	virtual const char* what() const throw() {
		return "ERROR: Selected account is not a savings account.";
	}
};


struct NotIntException : public std::exception {
public:
	virtual const char* what() const throw() {
		return "ERROR: Value was not an integer.";
	}
};


struct NotCurrencyException : public std::exception {
public:
	virtual const char* what() const throw() {
		return "ERROR: Value was not a currency format.";
	}
};


struct NoAccountsCreatedException : public std::exception {
public:
	virtual const char* what() const throw() {
		return "ERROR: You have not opened any accounts yet.";
	}
};


struct NotEnoughAccountsException : public std::exception {
public:
	virtual const char* what() const throw() {
		return "ERROR: You have not opened enough accounts yet.";
	}
};


struct NotEnoughParametersException : public std::exception {
public:
	virtual const char* what() const throw() {
		return "ERROR: You do not have enough parameters.";
	}
};


struct AccountNumberOutOfRangeException : public std::exception {
public:
	virtual const char* what() const throw() {
		return "ERROR: Account number specified out of range.";
	}
};


struct MaxCurrentAccountException : public std::exception {
public:
	virtual const char* what() const throw() {
		return "ERROR: You have opened the maximum number of current account(s).";
	}
};


struct MaxIsaAccountException : public std::exception {
public:
	virtual const char* what() const throw() {
		return "ERROR: You have opened the maximum number of ISA saving account(s).";
	}
};


struct WithdrawFailException : public std::exception {
public:
	virtual const char* what() const throw() {
		return "ERROR: Could not withdraw from the account.";
	}
};

