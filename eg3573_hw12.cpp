/*
Author: Edmund Gunn Jr
Course: NYU Tandon Bridge Extended J term
Assignment: Hw12
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

// Money class definition
class Money {
public:
    // Constructor with dollars and cents as arguments
    Money(long dollars, int cents) {
        all_cents = dollars * 100 + cents;
    }

    // Constructor with only dollars as argument
    Money(long dollars) {
        all_cents = dollars * 100;
    }

    // Default constructor
    Money() {
        all_cents = 0;
    }

    // Getter for the value of the money object
    double get_value() const {
        return all_cents / 100.0;
    }

    // Overloaded input operator
    friend istream& operator>>(istream& ins, Money& amount) {
        char dollarSign;
        double value;
        ins >> dollarSign >> value;
        amount.all_cents = round(value * 100);
        return ins;
    }

    // Overloaded output operator
    friend ostream& operator<<(ostream& outs, const Money& amount) {
        outs << '$' << amount.get_value();
        return outs;
    }

    // Overloaded addition operator
    friend Money operator+(const Money& amount1, const Money& amount2) {
        return Money(0, amount1.all_cents + amount2.all_cents);
    }

    // Overloaded subtraction operator
    friend Money operator-(const Money& amount1, const Money& amount2) {
        return Money(0, amount1.all_cents - amount2.all_cents);
    }

    // Overloaded unary negation operator
    friend Money operator-(const Money& amount) {
        return Money(0, -amount.all_cents);
    }

    // Overloaded equality operator
    friend bool operator==(const Money& amount1, const Money& amount2) {
        return amount1.all_cents == amount2.all_cents;
    }

    // Overloaded less than operator
    friend bool operator<(const Money& amount1, const Money& amount2) {
        return amount1.all_cents < amount2.all_cents;
    }

private:
    // Private member variable to store money in cents
    long all_cents;
};

// Check class definition
class Check {
public:
    // Default constructor
    Check() : checkNumber(0), amount(0), cashed(false) {}

    // Constructor with checkNumber, amount, and cashed status as arguments
    Check(int checkNumber, const Money &amount, bool cashed)
        : checkNumber(checkNumber), amount(amount), cashed(cashed) {}

    // Getter for check number
    int getCheckNumber() const {
        return checkNumber;
    }

    // Getter for check amount
    Money getAmount() const {
        return amount;
    }

    // Getter for cashed status
    bool isCashed() const {
        return cashed;
    }

    // Setter for check number
    void setCheckNumber(int checkNumber) {
        this->checkNumber = checkNumber;
    }

    // Setter for check amount
    void setAmount(const Money &amount) {
        this->amount = amount;
    }

    // Setter for cashed status
    void setCashed(bool cashed) {
        this->cashed = cashed;
    }

    // Overloaded input operator
    friend istream &operator>>(istream &ins, Check &check) {
        int checkNumber;
        Money amount;
        bool cashed;

        ins >> checkNumber >> amount; // Read check number and amount
        int temp;
        ins >> temp; // Read cashed status as an integer
        cashed = temp == 1; // Convert the integer to a boolean

        // Set check properties using the setters
        check.setCheckNumber(checkNumber);
        check.setAmount(amount);
        check.setCashed(cashed);

        return ins;
    }

    // Overloaded output operator
    friend ostream &operator<<(ostream &outs, const Check &check) {
        // Output formatted check information
        outs << "Check #" << check.getCheckNumber() << ": " << check.getAmount() << ", ";
        outs << (check.isCashed() ? "Cashed" : "Not cashed");
        return outs;
    }

private:
    // Private member variables for check number, amount, and cashed status
    int checkNumber;
    Money amount;
    bool cashed;
};

// Function to compare checks by check number
bool compareChecks(const Check &a, const Check &b) {
    return a.getCheckNumber() < b.getCheckNumber();
}

int main() {
    int numChecks;
    cout << "Enter the number of checks: ";
    cin >> numChecks;

    vector<Check> checks(numChecks);
    cout << "Enter check number, amount, and cashed status (1 for cashed, 0 for not cashed) for each check:\n";
    for (int i = 0; i < numChecks; ++i) {
        cin >> checks[i];
    }

    int numDeposits;
    cout << "Enter the number of deposits: ";
    cin >> numDeposits;

    vector<Money> deposits(numDeposits);
    cout << "Enter the deposit amounts:\n";
    for (int i = 0; i < numDeposits; ++i) {
        cin >> deposits[i];
    }

    Money oldBalance, newBalance;
    cout << "Enter the old balance: ";
    cin >> oldBalance;
    cout << "Enter the new balance: ";
    cin >> newBalance;

    Money totalCashed(0), totalDeposits(0);
    vector<Check> cashedChecks, uncashedChecks;

    for (size_t i = 0; i < checks.size(); ++i) {
        if (checks[i].isCashed()) {
            cashedChecks.push_back(checks[i]);
            totalCashed = totalCashed + checks[i].getAmount();
        } else {
            uncashedChecks.push_back(checks[i]);
        }
    }

    for (size_t i = 0; i < deposits.size(); ++i) {
        totalDeposits = totalDeposits + deposits[i];
    }

    Money calculatedNewBalance = oldBalance + totalDeposits - totalCashed;
    Money difference = newBalance - calculatedNewBalance;

    sort(cashedChecks.begin(), cashedChecks.end(), compareChecks);
    sort(uncashedChecks.begin(), uncashedChecks.end(), compareChecks);

    cout << "Total checks cashed: " << totalCashed << endl;
    cout << "Total deposits: " << totalDeposits << endl;
    cout << "Calculated new balance: " << calculatedNewBalance << endl;
    cout << "Difference with bank's new balance: " << difference << endl;

    cout << "\nCashed checks:" << endl;
    for (size_t i = 0; i < cashedChecks.size(); ++i) {
        cout << cashedChecks[i] << endl;
    }

    cout << "\nUncashed checks:" << endl;
    for (size_t i = 0; i < uncashedChecks.size(); ++i) {
        cout << uncashedChecks[i] << endl;
    }

    return 0;
}

