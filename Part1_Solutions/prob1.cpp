#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::endl;
bool checkAnswer(const string &nameOfTest, bool received, bool expected);

// Implement printString here
void printString(string s);

// Implement testString here
bool testString(string s);


// EDIT CODE BELOW *ONLY* FOR TESTING (ANY CODE BELOW WILL BE OVER-WRITTEN DURING GRADING WITH DIFFERENT TESTS)

int main() {
    cout << "Test if the string contains any of the characters: c, s, u, or f" << endl;
    {
        string s = "calif";
        cout << "Contents of array : ";
        printString(s);
        checkAnswer(s, testString(s), false);
    }
    {
        string s = "hheelllloo";
        cout << "Contents of array : ";
        printString(s);
        checkAnswer(s, testString(s), true);
    }
    {
        string s = "ookk";
        cout << "Contents of array : ";
        printString(s);
        checkAnswer(s, testString(s), true);
    }
    {
        string s = "abcc";
        cout << "Contents of array : ";
        printString(s);
        checkAnswer(s, testString(s), false);
    }
    {
        string s = "a";
        cout << "Contents of array : ";
        printString(s);
        checkAnswer(s, testString(s), true);
    }
    {
        string s = "daabb";
        cout << "Contents of array : ";
        printString(s);
        checkAnswer(s, testString(s), true);
    }
    {
        string s = "daabbc";
        cout << "Contents of array : ";
        printString(s);
        checkAnswer(s, testString(s), false);
    }
    {
        string s = "aabbccd";
        cout << "Contents of array : ";
        printString(s);
        checkAnswer(s, testString(s), false);
    }
    //  system("pause"); // comment/uncomment if needed

    return 0;
}

bool checkAnswer(const string &nameOfTest, bool received, bool expected) {
    if (received == expected) {
        cout << std::boolalpha << "PASSED " << nameOfTest << ": expected and received " << received << endl;
        return true;
    }
    cout << std::boolalpha << "FAILED " << nameOfTest << ": expected " << expected << " but received " << received << endl;
    return false;
}

void printString(string s) {
    string::iterator it = s.begin();
    while (it != s.end()) {
        cout << *it << " ";
        it++;
    }
    cout << endl;
}

// testString() should return true if the string does not contain any of the characters: ‘c’, ‘s’, ‘u’, or ‘f’, and false otherwise
bool testString(string s) {
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'c' || s[i] == 's' || s[i] == 'u' || s[i] == 'f') {
            return false;
        }
    }
    return true;
}