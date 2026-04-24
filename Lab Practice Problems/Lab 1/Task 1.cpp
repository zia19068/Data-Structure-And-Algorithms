/*Q1. Suppose you are developing a bank account management system, and you have defined the
BankAccount class with the required constructors. You need to demonstrate the use of these
constructors in various scenarios.
1. Default Constructor Usage: Create a default-initialized BankAccount object named
account1. Print out the balance of account1.
2. Parameterized Constructor Usage: Create a BankAccount object named account2 with
an initial balance of $1000. Print out the balance of account2.
3. Copy Constructor Usage: Using the account2 you created earlier, create a new
BankAccount object named account3 using the copy constructor. Deduct $200 from
account3 and print out its balance. Also, print out the balance of account2 to ensure it
hasn't been affected by the transaction involving account3.*/
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
