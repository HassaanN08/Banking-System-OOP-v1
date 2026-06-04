#include <iostream>
#include <string>
#include <vector>

using namespace std;

double roundToTwo(double num) {
    double val = (int)(num * 100 + 0.5);
    return (float)val / 100;
}

void showMenu() {
    cout << '\n' << '\n' << "1. Create Savings Account" << '\n' << "2. Create Current Account" << '\n'<< "3. Deposit Money" << '\n'<< "4. Withdraw Money" << '\n'<< "5. Show Account Details" << '\n'<< "6. Show All Accounts" << '\n'<< "7. Exit" << '\n' << '\n';
}

int getChoice() {
    int choice;
    cout << "Enter your choice: ";
    cin >> choice;

    while (choice < 1 || choice > 7) {
        cout << "Invalid choice. Pick a number between 1 and 7: ";
        cin.clear();
        cin.ignore(10000, '\n');
        cin >> choice;
    }

    return choice;
}

class BankAccount {
    private:
        string holderName;
    protected:
        int transactions;
        double balance;
        string accountType;
    public:
        BankAccount(string name, double amount) : holderName(name), balance(amount){
            transactions = 0;
        }

        void depositMoney(double amount) {
            while (amount <= 0) {
                cout << "Invalid choice. Enter an amount greter than 0, or enter -1 to go back to the menu: ";
                cin.clear();
                cin.ignore(10000, '\n');
                cin >> amount;
                if (amount == -1) {
                    return;
                }
            }

            balance += amount;
            transactions++;
        }

        double getBalance() {
            return balance;
        }

        string getName() {
            return holderName;
        }

        string getAccountType() {
            return accountType;
        }

        int getTransactions() {
            return transactions;
        }
};

class SavingsAccount : public BankAccount {
    private:
        double interestRate;
    public:
        SavingsAccount(string name, double amount, double interest) : BankAccount(name, amount), interestRate(interest) {
            accountType = "Savings";
        }

        double getInterestRate() {
            return interestRate;
        }

        void withdrawMoneyFromSavings(double amount) {

            while (amount <= 0 || amount > balance) {
                if (amount <= 0) {
                    cout << "Invalid choice. Enter an amount greater 0, or enter -1 to go back to the menu: ";
                } else {
                    cout << "Amount exceeded your balance. Enter an amount within your balance, or enter -1 to go back to the menu: ";
                }
                cin.clear();
                cin.ignore(10000, '\n');
                cin >> amount;
                if (amount == -1) {
                    return;
                }
            }

            balance -= amount;
            transactions++;
        }
};

class CurrentAccount : public BankAccount {
    private:
        double overdraftLimit;
    public:
        CurrentAccount(string name, double amount, double limit) : BankAccount(name, amount), overdraftLimit(limit) {
            accountType = "Current";
        }

        double getOverdraftLimit() {
            return overdraftLimit;
        }

        void withdrawMoneyFromCurrent(double amount) {
            while (amount <= 0 || amount > balance + overdraftLimit) {
                if (amount <= 0) {
                    cout << "Invalid choice. Enter an amount greater 0, or enter -1 to go back to the menu: ";
                } else {
                    cout << "Amount exceeded your maximum withdrawable amount. Enter an amount within it, or enter -1 to go back to the menu: ";
                }
                cin.clear();
                cin.ignore(10000, '\n');
                cin >> amount;
                if (amount == -1) {
                    return;
                }
            }

            balance -= amount;
            transactions++;
        }
};

void traverseVector(int &accChoice, int &index, vector<SavingsAccount> &savingsAccount, vector<CurrentAccount> &currentAccount) {
    for (int i = 0; i < savingsAccount.size(); i++) {
        cout << i + 1 << ". " << savingsAccount[i].getName() << " - " << savingsAccount[i].getAccountType() << " Account" << '\n';
        index++;
    }

    for (int i = 0; i < currentAccount.size(); i++) {
        cout << savingsAccount.size() + i + 1 << ". " << currentAccount[i].getName() << " - " << currentAccount[i].getAccountType() << " Account" << '\n';
        index++;
    }

    cout << "Choose account number: ";
    cin >> accChoice;
    while (accChoice <= 0 || accChoice > index) {
        cout << "Invalid choice. Choose again, or enter -1 to go back to the menu: ";
        cin.clear();
        cin.ignore(10000, '\n');
        cin >> accChoice;
        if (accChoice == -1) {
            break;
        }
    }
}

int main() {
    cout << "======================" << '\n' << "    Banking System    " << '\n' << "======================";
    showMenu();
    int choice = getChoice();

    vector<SavingsAccount> savingsAccount;
    vector<CurrentAccount> currentAccount;

    while (choice != 7) {
        if (choice == 1) {
            string name;
            double balance;
            double interestRate;

            cout << '\n' << "Enter account holder name: ";
            cin >> name;
            cout<< "Enter starting balance: $";
            cin >> balance;
            while (balance < 0) {
                cout << "Enter an amount equal to or greater than 0: ";
                cin.clear();
                cin.ignore(10000, '\n');
                cin >> balance;
            }
            cout<< "Enter interest rate: ";
            cin >> interestRate;
            while (interestRate < 0) {
                cout << "Enter an amount equal to or greater than 0: ";
                cin.clear();
                cin.ignore(10000, '\n');
                cin >> interestRate;
            }

            SavingsAccount acc(name, balance, interestRate);
            savingsAccount.push_back(acc);

            cout << "Savings account created successfully." << '\n' << '\n';
        } else if (choice == 2) {
            string name;
            double balance;
            double overdraftLimit;

            cout << '\n' << "Enter account holder name: ";
            cin >> name;
            cout<< "Enter starting balance: $";
            cin >> balance;
            while (balance < 0) {
                cout << "Enter an amount equal to or greater than 0: ";
                cin.clear();
                cin.ignore(10000, '\n');
                cin >> balance;
            }
            cout<< "Enter overdraft limit: $";
            cin >> overdraftLimit;
            while (overdraftLimit < 0) {
                cout << "Enter an amount equal to or greater than 0: ";
                cin.clear();
                cin.ignore(10000, '\n');
                cin >> overdraftLimit;
            }

            CurrentAccount acc(name, balance, overdraftLimit);
            currentAccount.push_back(acc);

            cout << "Current account created successfully." << '\n' << '\n';
        } else if (choice == 3) {
            int accChoice;
            int index = 0;
            double amt;

            traverseVector(accChoice, index, savingsAccount, currentAccount);

            if (accChoice == -1) {
                showMenu();
                choice = getChoice();
                continue;
            }

            cout << "Enter deposit ammount: $";
            cin >> amt;
            
            if (accChoice <= savingsAccount.size()) {
                savingsAccount[accChoice - 1].depositMoney(amt);
            } else if (accChoice > savingsAccount.size()) {
                currentAccount[accChoice - savingsAccount.size() - 1].depositMoney(amt);
            }
        } else if (choice == 4) {
            int accChoice;
            int index = 0;
            double amt;

            traverseVector(accChoice, index, savingsAccount, currentAccount);

            if (accChoice == -1) {
                showMenu();
                choice = getChoice();
                continue;
            }

            cout << "Enter withdrawal ammount: $";
            cin >> amt;
            
            if (accChoice <= savingsAccount.size()) {
                savingsAccount[accChoice - 1].withdrawMoneyFromSavings(amt);
            } else if (accChoice > savingsAccount.size()) {
                currentAccount[accChoice - savingsAccount.size() - 1].withdrawMoneyFromCurrent(amt);
            }
        } else if (choice == 5) {
            int accChoice;
            int index = 0;

            traverseVector(accChoice, index, savingsAccount, currentAccount);

            if (accChoice == -1) {
                showMenu();
                choice = getChoice();
                continue;
            }

            cout << '\n';
            
            if (accChoice <= savingsAccount.size()) {
                cout << "Account type: " << savingsAccount[accChoice - 1].getAccountType() << '\n';
                cout << "Holder name: " << savingsAccount[accChoice - 1].getName() << '\n';
                cout << "Balance: " << roundToTwo(savingsAccount[accChoice - 1].getBalance()) << '\n';
                cout << "Interest Rate: " << roundToTwo(savingsAccount[accChoice - 1].getInterestRate()) << '\n';
                cout << "Transactions: " << savingsAccount[accChoice - 1].getTransactions() << '\n';
            } else if (accChoice > savingsAccount.size()) {
                cout << "Account type: " << currentAccount[accChoice - savingsAccount.size() - 1].getAccountType() << '\n';
                cout << "Holder name: " << currentAccount[accChoice - savingsAccount.size() - 1].getName() << '\n';
                cout << "Balance: " << roundToTwo(currentAccount[accChoice - savingsAccount.size() - 1].getBalance()) << '\n';
                cout << "Overdraft limit: " << roundToTwo(currentAccount[accChoice - savingsAccount.size() - 1].getOverdraftLimit()) << '\n';
                cout << "Transactions: " << currentAccount[accChoice - savingsAccount.size() - 1].getTransactions() << '\n';
            }
        } else if (choice == 6) {
            int accChoice;
            int index = 1;

            for (int i = 0; i < savingsAccount.size(); i++) {
                cout << i + 1 << ". " << savingsAccount[i].getName() << " - " << savingsAccount[i].getAccountType() << " Account - " << "Balance: $" << roundToTwo(savingsAccount[i].getBalance()) << '\n';
                index++;
            }

            for (int i = 0; i < currentAccount.size(); i++) {
                cout << savingsAccount.size() + i + 1 << ". " << currentAccount[i].getName() << " - " << currentAccount[i].getAccountType() << " Account - " << "Balance: $" << roundToTwo(currentAccount[i].getBalance()) << '\n';
                index++;
            }
        }

        showMenu();
        choice = getChoice();
    }

    return 0;
}