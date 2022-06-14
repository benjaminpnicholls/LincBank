#include "savings.h"
#include <cmath>  // Exponent.

Savings::Savings(double InitialDeposit, bool Isa) {
	if (InitialDeposit < 0) {
		throw InitialDepositBelowZeroException();
	}
	m_Balance = InitialDeposit;
	m_ISA = Isa;
	m_InterestRate = 0.85;
	std::string accountType = "Savings";
	if (m_ISA) {
		if (InitialDeposit < 1000) {
			throw InitialDepositBelowISARequiredException();
		}
		m_InterestRate = 1.15;
		accountType = "ISA";
	}
	Transaction* t = new Transaction("Open " + accountType + " Account", m_Balance);
	m_History.push_back(t);
}	


Savings::~Savings() {
}


bool Savings::Deposit(double Amount, int Ref) {
	if (Amount <= 0) { return false; }
	m_Balance += Amount;
	std::string desc = "Deposit";
	if (Ref != 0) { desc = "Transfer from account " + std::to_string(Ref); }
	Transaction* t = new Transaction(desc, Amount);
	m_History.push_back(t);
	return true;
}


bool Savings::Withdraw(double Amount, int Ref) {
	if (Amount <= 0.00) { return false; }
	if (m_Balance - Amount < 0.00) { return false; }
	m_Balance -= Amount;
	std::string desc = "Withdraw";
	if (Ref != 0) { desc = "Transfer to account " + std::to_string(Ref); }
	Transaction* t = new Transaction(desc, Amount);
	m_History.push_back(t);
	return true;
}


double Savings::ComputeInterest(int Years) const {
	int n = 12;  // Unit time (monthly = 12).
	double finalAmount = m_Balance * pow(1 + m_InterestRate / 100 / n, n * Years);
	return finalAmount;
}


std::string Savings::Truncate2dp(double Value) const {
	std::string value = std::to_string(Value);
	value = value.substr(0, value.find('.')  + 3);
	return value;
}


std::string Savings::ToString() const {
	std::string a = "Savings";
	if (m_ISA) { a = "ISA"; }
	a += " account | Balance: £" + Savings::Truncate2dp(m_Balance) + "\n";
	for (auto entry : m_History) {
		a += entry->ToString();
    }
	return a;   
}
