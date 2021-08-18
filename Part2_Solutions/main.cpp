#include <iostream>
#include <string>
#include "BreedAnalysis.h"

using std::string;
using std::endl;
using std::cout;

bool testAnswer(const string &nameOfTest, double received, double expected);

template <typename T>
bool testAnswer(const string &nameOfTest, const T& received, const T& expected);


int main() {
    {
        cout << "Testing with small data file ..." << endl;
        BreedAnalysis ba;
        ba.readFile("dogs10.txt");

        testAnswer("averageAge of Shih_Tzu", ba.averageAge("Shih_Tzu"), 29);
        testAnswer("averageAge of Dachshund", ba.averageAge("Dachshund"), 41);
        testAnswer("averageAge of Cavalier_King_Charles_Spaniel", ba.averageAge("Cavalier_King_Charles_Spaniel"), 33.5);
        testAnswer("averageAge of Pomeranian", ba.averageAge("Pomeranian"), 0);
        testAnswer("mostPopularBreed", ba.mostPopularBreed(), string("Dachshund"));
    }
    {
        cout << "Testing with large data file ..." << endl;
        BreedAnalysis ba;
        ba.readFile("dogs1000.txt");

        testAnswer("averageAge of Shih_Tzu", ba.averageAge("Shih_Tzu"), 39.0909);
        testAnswer("averageAge of Dachshund", ba.averageAge("Dachshund"), 46.4211);
        testAnswer("averageAge of Cavalier_King_Charles_Spaniel", ba.averageAge("Cavalier_King_Charles_Spaniel"), 46.9333);
        testAnswer("averageAge of Pomeranian", ba.averageAge("Pomeranian"), 37.3617);
        testAnswer("mostPopularBreed", ba.mostPopularBreed(), string("Brittany"));
    }
    return (0);
}

template <typename T>
bool testAnswer(const string &nameOfTest, const T& received, const T& expected) {
    if (received == expected) {
        cout << "PASSED " << nameOfTest << ": expected and received " << received << endl;
        return true;
    }
    cout << "FAILED " << nameOfTest << ": expected " << expected << " but received " << received << endl;
    return false;
}

bool testAnswer(const string &nameOfTest, double received, double expected) {
    if ((received - expected) > -0.01 && (received - expected) < 0.01) {
        cout << "PASSED " << nameOfTest << ": expected and received " << received << endl;
        return true;
    }
    cout << "FAILED " << nameOfTest << ": expected " << expected << " but received " << received << endl;
    return false;
}
