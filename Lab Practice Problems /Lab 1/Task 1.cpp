#include <iostream>
using namespace std;

class BankAccount {
    double balance;
public:
    BankAccount() : balance(0) {
	}
    BankAccount(double b) : balance(b) {
	}
    BankAccount(const BankAccount& other) : balance(other.balance) {
	}
    double g_balance() { 
	return balance; 
	}
    void withdraw(double amount) { 
	if (amount <= balance) 
	balance -= amount; 
	}
};

int main() {
    BankAccount acc1;
    cout << "Account 1 Balance: " << acc1.g_balance() << endl;

    BankAccount acc2(1000);
    cout << "Account 2 Balance: " << acc2.g_balance() << endl;

    BankAccount acc3(acc2);
    acc3.withdraw(200);
    cout << "Account 3 Balance after withdrawal: " << acc3.g_balance() << endl;
    cout << "Account 2 Balance remains: " << acc2.g_balance() << endl;

    return 0;
}
