/*
Author: Edmund Gunn Jr
Course: NYU Tandon Bridge Extended J term
Assignment: Hw15
*/
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>

using namespace std;

class PersonNode {
public:
    string name;
    float amount_paid;
    float amount_owed;
    bool has_made_transaction;
    PersonNode* next;

    // Constructor for PersonNode
    PersonNode(string _name, float _amount_paid) {
        name = _name;
        amount_paid = _amount_paid;
        amount_owed = 0;
        has_made_transaction = false;
        next = nullptr;
    }
};

class LinkedList {
public:
    PersonNode* head;
    int size;

    // Constructor for LinkedList
    LinkedList() {
        head = nullptr;
        size = 0;
    }

    // Add a person to the LinkedList
    void addPerson(string name, float amount_paid) {
        PersonNode* new_person = new PersonNode(name, amount_paid);
        if (head == nullptr) {
            head = new_person;
        } else {
            PersonNode* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = new_person;
        }
        size++;
    }
};

// Read the input file and populate the LinkedList
void readFile(LinkedList &list, string filename) {
    ifstream file(filename);
    string line, name;
    float amount_paid;

    while (getline(file, line)) {
        istringstream iss(line);
        iss >> amount_paid;
        getline(iss, name);
        name = name.substr(1); // Remove leading space
        list.addPerson(name, amount_paid);
    }
    file.close();
}

int main() {
    LinkedList people;

    string filename;
    cout << "Enter the filename: ";
    cin >> filename;
    readFile(people, filename);

    // Calculate the total amount paid
    float total_amount = 0;
    PersonNode* current = people.head;
    while (current != nullptr) {
        total_amount += current->amount_paid;
        current = current->next;
    }
    float target_amount = total_amount / people.size;

    // Calculate the amount owed by each person
    current = people.head;
    while (current != nullptr) {
        current->amount_owed = current->amount_paid - target_amount;
        current = current->next;
    }

    // Reimbursement process
    PersonNode* payer = people.head;
    PersonNode* payee = people.head;
    while (payer != nullptr && payee != nullptr) {
        if (payer->amount_owed < 0 && payee->amount_owed > 0) {
            float transfer_amount = min(-payer->amount_owed, payee->amount_owed);
            payer->amount_owed += transfer_amount;
            payee->amount_owed -= transfer_amount;
            payer->has_made_transaction = true;
            cout << fixed << setprecision(2) << payer->name << ", you give " << payee->name << " $" << transfer_amount << endl;
        }
        // Move to the next payer if the current payer doesn't owe any more money
        if (payer->amount_owed >= 0) {
            if (payer->amount_owed == 0 && !payer->has_made_transaction) {
                cout << payer->name << ", you don't need to do anything" << endl;
        }
        payer = payer->next;
    }
    // Move to the next payee if the current payee doesn't need any more money
    if (payee->amount_owed <= 0) {
        payee = payee->next;
    }
}
    cout << "In the end, you should all have spent around $" << fixed << setprecision(2) << target_amount << endl;
    return 0;
}
