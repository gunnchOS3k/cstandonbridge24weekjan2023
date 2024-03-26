/*
Author: Edmund Gunn Jr
Assignment: hw7 NYU Tandon Bridge J Extened
*/
#include <iostream>
#include <vector>
using namespace std;

//analyze divisor function
void analyzeDivisors(int num, int& outCountDivs, int& outSumDivs) {
    outCountDivs = 0;
    outSumDivs = 0;
    for (int i = 1; i * i <= num; i++) {
        if (num % i == 0) {
            outCountDivs += 2;
            outSumDivs += i + num / i;
            if (i * i == num) { // num is a perfect square
                outCountDivs--;
                outSumDivs -= i;
            }
        }
    }
    outSumDivs -= num; // subtract num itself from the sum
}
//check if nunber is perfect
bool isPerfect(int num) {
    int countDivs, sumDivs;
    analyzeDivisors(num, countDivs, sumDivs);
    return (num == sumDivs && countDivs == 2*num);
}
//main function
int main() {
    int M;
    cin >> M;

    vector<int> perfectNumbers;
    vector<pair<int, int>> amicablePairs;

    for (int i = 2; i <= M; i++) {
        int countDivs, sumDivs;
        analyzeDivisors(i, countDivs, sumDivs);
        if (sumDivs == i) { // i is a perfect number
            perfectNumbers.push_back(i);
            for (int j = perfectNumbers.size() - 2; j >= 0; j--) {
                if (i == perfectNumbers[j] + sumDivs) { // i and j form an amicable pair
                    amicablePairs.emplace_back(j+2, i);
                    break;
                }
            }
        }
    }

    cout << "Perfect numbers between 2 and " << M << ":" << endl;
    for (int i = 0; i < perfectNumbers.size(); i++) {
        cout << perfectNumbers[i] << " ";
    }
    cout << endl << "Amicable pairs between 2 and " << M << ":" << endl;
    for (int i = 0; i < amicablePairs.size(); i++) {
        cout << amicablePairs[i].first << " " << amicablePairs[i].second << endl;
    }

    return 0;
}
