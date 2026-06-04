# OOP Banking System

A terminal-based banking system built in C++ to practice object-oriented programming concepts such as classes, objects, constructors, access specifiers, inheritance, protected members, and vectors of objects.

This project was created as part of my C++ learning journey after studying classes, constructors, access specifiers, and inheritance.

## Project Goal

The goal of this project is not to build a production-ready banking application, but to solidify core object-oriented programming concepts in C++ using a real-world example.

The system supports two types of bank accounts:

* Savings Account
* Current Account

Both account types share common bank account behavior, while also having their own specific data and withdrawal rules.

## Features

* Create a savings account
* Create a current account
* Store multiple savings accounts
* Store multiple current accounts
* Deposit money into an account
* Withdraw money from an account
* Show details for a selected account
* Show all created accounts
* Track transaction count
* Validate invalid account choices
* Validate invalid deposit amounts
* Validate invalid withdrawal amounts
* Support overdraft rules for current accounts

## Menu Options

```text
1. Create Savings Account
2. Create Current Account
3. Deposit Money
4. Withdraw Money
5. Show Account Details
6. Show All Accounts
7. Exit
```

## Account Types

### Savings Account

A savings account has:

* Account holder name
* Balance
* Account type
* Transaction count
* Interest rate

Withdrawal rule:

```text
A savings account cannot withdraw more than the current balance.
```

### Current Account

A current account has:

* Account holder name
* Balance
* Account type
* Transaction count
* Overdraft limit

Withdrawal rule:

```text
A current account can withdraw beyond the current balance, but only up to the overdraft limit.
```

Example:

```text
Balance: $500
Overdraft Limit: $1000
Maximum Withdrawable Amount: $1500
```

## Concepts Practiced

This project helped me practice:

* Classes
* Objects
* Constructors
* Constructor initialization lists
* Private members
* Protected members
* Public methods
* Inheritance
* Base classes
* Derived classes
* Constructor chaining
* Vectors of objects
* Function-based menu flow
* Input validation
* Basic object-oriented design

## OOP Design

The project uses a base class for shared account behavior and derived classes for account-specific behavior.

The shared account data and behavior are handled by a general bank account class. Savings and current accounts inherit from it and add their own specific fields and withdrawal rules.

The balance is not directly editable from `main()`. It is updated through account methods such as deposit and withdrawal functions.

This helps practice the idea that an object should manage its own state instead of allowing outside code to directly modify important data.

## Example Terminal Flow

```text
======================
    Banking System    
======================

1. Create Savings Account
2. Create Current Account
3. Deposit Money
4. Withdraw Money
5. Show Account Details
6. Show All Accounts
7. Exit

Enter your choice: 1

Enter account holder name: Hassaan
Enter starting balance: $1000
Enter interest rate: 5

Savings account created successfully.
```

## Sample Account Details Output

```text
Account type: Savings
Holder name: Hassaan
Balance: 1500
Interest Rate: 5
Transactions: 2
```

For a current account:

```text
Account type: Current
Holder name: Ali
Balance: -200
Overdraft limit: 1000
Transactions: 1
```

## How to Compile

Use `g++`:

```bash
g++ -Wall -Wextra -std=c++17 main.cpp -o banking
```

## How to Run

```bash
./banking
```

## Current Limitations

This is version 1, so the program is intentionally simple.

Current limitations:

* Account holder names currently accept one word only
* Account data is not saved after the program exits
* Savings and current accounts are stored in separate vectors
* The program does not use polymorphism yet
* The program does not use virtual functions yet
* Some menu and selection logic is repeated
* Input/output logic is still mixed with some class methods
* The project is contained in a single `main.cpp` file

## Future Improvements

Possible improvements for future versions:

* Support full names with spaces
* Format money consistently to two decimal places
* Save account data to a file
* Load saved accounts when the program starts
* Add account numbers or IDs
* Search accounts by name or account number
* Add delete account functionality
* Reduce repeated account selection code
* Move classes into separate header/source files
* Use polymorphism after learning virtual functions
* Store all account types in a single collection using base-class pointers
* Add more account types
* Improve separation between business logic and terminal input/output

## Project Status

Version 1 is complete.

This version focuses on mastering core C++ OOP concepts up to inheritance, including classes, constructors, access control, protected members, derived classes, and vectors of objects.
