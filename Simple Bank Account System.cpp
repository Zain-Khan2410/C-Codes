#include <iostream>
#include <string>

class BankAccount {
private:
    std::string accountNumber; 
    double balance;            

public:
    BankAccount(const std::string& accNumber) {
        accountNumber = accNumber;
        balance = 0.0;
    }

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            std::cout << "Amount deposited: " << amount << std::endl;
        } else {
            std::cout << "Invalid deposit amount." << std::endl;
        }
    }

    void withdraw(double amount) {
        if (amount > balance) {
            std::cout << "Insufficient balance." << std::endl;
        } else if (amount <= 0) {
            std::cout << "Invalid withdrawal amount." << std::endl;
        } else {
            balance -= amount;
            std::cout << "Amount withdrawn: " << amount << std::endl;
        }
    }

    
    void checkBalance() const {
        std::cout << "Current balance: " << balance << std::endl;
    }
};

int main() {
    
    std::string accountNumber;
    std::cout << "Enter account number: ";
    std::cin >> accountNumber;

    BankAccount myAccount(accountNumber);

    int choice;
    do {
        std::cout << "\nBank Account Menu:\n";
        std::cout << "1. Deposit\n";
        std::cout << "2. Withdraw\n";
        std::cout << "3. Check Balance\n";
        std::cout << "4. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
        case 1: {
            double depositAmount;
            std::cout << "Enter amount to deposit: ";
            std::cin >> depositAmount;
            myAccount.deposit(depositAmount);
            break;
        }
        case 2: {
            double withdrawAmount;
            std::cout << "Enter amount to withdraw: ";
            std::cin >> withdrawAmount;
            myAccount.withdraw(withdrawAmount);
            break;
        }
        case 3:
            myAccount.checkBalance();
            break;
        case 4:
            std::cout << "Exiting... Thank you for using the system!" << std::endl;
            break;
        default:
            std::cout << "Invalid choice. Please try again." << std::endl;
        }
    } while (choice != 4);

    return 0;
}
