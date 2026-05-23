/*
  ================================================
   ATM System - HEM Bank
   printBanner() - () border style
  ================================================
*/

#include <iostream>
#include <string>
using namespace std;

void printBanner() {
    cout << "\n";
    cout << "  (==========================================)\n";
    cout << "  (                                          )\n";
    cout << "  (    ___  ____  ____                       )\n";
    cout << "  (   / _ )/ __ \\/ __ \\                      )\n";
    cout << "  (  / _  / /_/ / /_/ /                      )\n";
    cout << "  ( /____/\\____/\\____/                       )\n";
    cout << "  (                                          )\n";
    cout << "  (      AUTOMATED TELLER MACHINE            )\n";
    cout << "  (        Secure * Reliable * Fast          )\n";
    cout << "  (==========================================)\n";
    cout << "\n";
}

class CreateAccount {
public:
    string name;
    int accountNumber;
    int registerPin;

    void create() {
        cout << "Welcome to BDO Bank ATM System!\n";

        cout << "Insert your card to begin registration.\n";
        cout << "Press Enter to continue...";
        cin.get();

        cout << "Let's start by creating your account.\n";

        cout << "Enter your name: ";
        getline(cin, name);  // no extra ignore needed here now

        do {
            cout << "Enter your account number: ";
            cin >> accountNumber;
            if (accountNumber <= 0)
                cout << "Invalid account number. Please try again.\n";
        } while (accountNumber <= 0);

        do {
            cout << "Set your PIN (must be greater than 0): ";
            cin >> registerPin;
            if (registerPin <= 0)
                cout << "Invalid PIN. Please try again.\n";
        } while (registerPin <= 0);

        cout << "Account created successfully for " << name
            << " with account number " << accountNumber << ".\n\n";
    }

    void inputPin() {
        int attempts = 0;
        int enteredAccount;

        do {
            cout << "Please insert your card.\n";
            cout << "Enter your account number: ";
            cin >> enteredAccount;

            if (enteredAccount != accountNumber) {
                cout << "Account not found. Please try again.\n";
                continue;
            }

            cout << "Enter your PIN: ";
            int pin;
            cin >> pin;

            if (pin == registerPin) {
                cout << "PIN accepted. Access granted.\n\n";
                return;
            }
            else {
                attempts++;
                cout << "Incorrect PIN. Attempts remaining: " << (3 - attempts) << "\n";
            }

        } while (attempts < 3);

        cout << "Too many failed attempts. Card blocked.\n";
        exit(0);
    }
};

class ATMFunctions {
public:
    CreateAccount& account;
    long balance = 0;

    ATMFunctions(CreateAccount& acc) : account(acc) {}

    void Menu() {
        int choice;

        do {
            cout << "\n";
            cout << "  (==========================================)\n";
            cout << "  (            BDO Bank ATM Menu             )\n";
            cout << "  (==========================================)\n";
            cout << "  (   [1] Deposit      [2] Withdraw          )\n";
            cout << "  (   [3] Balance      [4] Transfer          )\n";
            cout << "  (   [5] Change PIN   [0] Exit              )\n";
            cout << "  (==========================================)\n";
            cout << "  Enter your choice: ";
            cin >> choice;
            cout << "\n";

            switch (choice) {
            case 1:
                cout << "You selected Deposit.\n";
                Deposit();
                break;
            case 2:
                cout << "You selected Withdraw.\n";
                Withdraw();
                break;
            case 3:
                cout << "You selected Balance.\n";
                Balance();
                break;
            case 4:
                cout << "You selected Transfer.\n";
                Transfer();
                break;
            case 5:
                cout << "You selected Change PIN.\n";
                ChangePin();
                break;
            case 0:
                cout << "Exiting. Thank you for using BDO Bank ATM!\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
            }

        } while (choice != 0);
    }

    void Deposit() {
        long amount;
        cout << "Enter amount to deposit: ";
        cin >> amount;
        if (amount <= 0) {
            cout << "Invalid amount.\n";
            return;
        }
        balance += amount;
        cout << "You have deposited: " << amount << "\n";
        cout << "Current balance: " << balance << "\n";
    }

    void Withdraw() {
        double amount;
		double dailyLimit = 50000; // Example daily limit
		double atmCashLimit = 1000000; // Example ATM cash limit
        cout << "Enter amount to withdraw: ";
        cin >> amount;
        if (amount <= 0) {
            cout << "Invalid amount.\n";
            return;
        }
		if (amount > dailyLimit) {
			cout << "Amount exceeds daily withdrawal limit of " << dailyLimit << ".\n";
			return;
		}
		if (amount > atmCashLimit) {
			cout << "Amount exceeds ATM cash limit of " << atmCashLimit << ".\n";
			return;
		}
        if (amount > balance) {
            cout << "Insufficient funds.\n";
        }
        else {
            balance -= amount;
            cout << "You have withdrawn: " << amount << "\n";
            cout << "Current balance: " << balance << "\n";
        }
    }

    void Balance() {
        cout << "Current balance: " << balance << "\n";
    }

    void Transfer() {
        int recipientAccount;

        bool validAccount = false;

        do {
            cout << "Enter recipient account number: ";
            cin >> recipientAccount;

            if (recipientAccount <= 0) {
                cout << "Invalid account number. Please try again.\n";
            }
            else if (recipientAccount == account.accountNumber) {
                cout << "Cannot transfer to your own account.\n";
            }
            else {
                validAccount = true;
            }

        } while (!validAccount);

        double amount;
        cout << "Enter amount to transfer: ";
        cin >> amount;

        if (amount <= 0) {
            cout << "Invalid amount.\n";
            return;
        }
        if (amount > balance) {
            cout << "Insufficient funds.\n";
        }
        else {
            balance -= amount;
            cout << "Transferred: " << amount << " to account " << recipientAccount << "\n";
            cout << "Current balance: " << balance << "\n";
        }
    }

    void ChangePin() {
        int currentPin, newPin, confirmPin;

        cout << "Enter current PIN: ";
        cin >> currentPin;

        if (currentPin != account.registerPin) {
            cout << "Incorrect current PIN. Cannot change PIN.\n";
            return;
        }

        cout << "Enter new PIN: ";
        cin >> newPin;
        cout << "Confirm new PIN: ";
        cin >> confirmPin;

        if (newPin == confirmPin) {
            account.registerPin = newPin;
            cout << "PIN changed successfully.\n";
        }
        else {
            cout << "PINs do not match. PIN not changed.\n";
        }
    }
};

int main() {
    printBanner();

    CreateAccount account;
    account.create();
    account.inputPin();

    ATMFunctions atm(account);
    atm.Menu();

    return 0;
}