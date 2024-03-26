/*
Author: Edmund Gunn Jr
Course: NYU Tandon Bridge Extended J term
Assignment: Hw16 Problem 2
*/
#include <iostream>
#include <vector>

class Queue {
private:
    std::vector<int> vec; // The vector to store the queue elements
    int start; // The starting position of the queue
    int end;   // The ending position of the queue

public:
    // Constructor to initialize the start and end positions
    Queue() : start(0), end(-1) {}

    // Function to add an element to the end of the queue
    void push(int value) {
        vec.push_back(value);
        end++;
    }

    // Function to remove the element at the front of the queue
    void pop() {
        if (isEmpty()) {
            std::cout << "Queue is empty. Cannot pop." << std::endl;
            return;
        }
        start++;
        if (isEmpty()) {
            reset();
        }
    }

    // Function to return the element at the front of the queue
    int front() {
        if (isEmpty()) {
            std::cout << "Queue is empty." << std::endl;
            return -1;
        }
        return vec[start];
    }

    // Function to check if the queue is empty
    bool isEmpty() {
        return (start > end);
    }

    // Function to reset the queue and the start and end positions
    void reset() {
        vec.clear();
        start = 0;
        end = -1;
    }
};

