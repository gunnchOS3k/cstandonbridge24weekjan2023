/*
Author: Edmund Gunn Jr
Course: NYU Tandon Bridge Extended J term
Assignment: Hw14
*/
#include <iostream>
#include <vector>
#include <limits>

using namespace std;

// Helper function to find min and max recursively in the given range of the input vector
pair<int, int> findMinMax(const vector<int>& data, int start, int end) {
    // If there is only one element, it is the min and max
    if (start == end) {
        return make_pair(data[start], data[start]);
    // If there are two elements, compare them to find min and max
    } else if (start + 1 == end) {
        if (data[start] < data[end]) {
            return make_pair(data[start], data[end]);
        } else {
            return make_pair(data[end], data[start]);
        }
    // If there are more than two elements, divide the input into two halves
    } else {
        int mid = start + (end - start) / 2;
        // Recursively find min and max for the left half
        pair<int, int> leftMinMax = findMinMax(data, start, mid);
        // Recursively find min and max for the right half 
        pair<int, int> rightMinMax = findMinMax(data, mid + 1, end);

        // Find min and max between the left and right halves
        int min_val = min(leftMinMax.first, rightMinMax.first);
        int max_val = max(leftMinMax.second, rightMinMax.second);
        // Return the min and max as a pair
        return make_pair(min_val, max_val);
    }
}

// Main function to find min and max of the input vector
vector<int> findMinMax(const vector<int>& data) {
    if (data.empty()) {
        return vector<int>();
    }
    
    // Call the helper function with the full range of the input vector
    pair<int, int> minMax = findMinMax(data, 0, data.size() - 1);
    vector<int> result(2); // Create a vector of size 2
    result[0] = minMax.first; // Set the min value
    result[1] = minMax.second; // Set the max value
    return result;
}

int main() {
    // Create an empty input vector
    vector<int> data;

    // Populate the input vector using the push_back method
    data.push_back(5);
    data.push_back(2);
    data.push_back(9);
    data.push_back(1);
    data.push_back(5);
    data.push_back(6);

    // Call the findMinMax function to get min and max values
    vector<int> result = findMinMax(data);

    // If the result is not empty, print the min and max values
    if (!result.empty()) {
        cout << "Min: " << result[0] << ", Max: " << result[1] << endl;
    } else {
        cout << "Input vector is empty" << endl;
    }

    return 0;
}
