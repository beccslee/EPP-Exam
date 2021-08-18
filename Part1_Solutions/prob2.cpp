//
// EDIT THIS FILE ONLY FOR YOUR OWN TESTING
// WRITE YOUR CODE IN IntegerLinkedList.cpp
//

#include <iostream>
#include <string>
#include "IntegerLinkedList.h"

using std::string;
using std::cout;
using std::endl;
bool checkAnswer(const string &nameOfTest, bool received, bool expected);

int main() {
  cout << "Test if the linked list contains the integers 57 or 1957, but not both" << endl;
  {
    IntegerLinkedList mylist;
    mylist.addFront(57);
    mylist.addFront(30);
    mylist.addFront(20);
    mylist.addFront(57);
    mylist.addFront(10);
    mylist.addFront(10);
	string s = "List: 10 -> 10 -> 57 -> 20 -> 30 -> 57";
	checkAnswer(s, mylist.checkList(), true);
  }
  {
    IntegerLinkedList mylist;
    mylist.addFront(30);
    mylist.addFront(30);
    mylist.addFront(20);
    mylist.addFront(25);
    mylist.addFront(10);
    mylist.addFront(10);
    string s = "List: 10 -> 10 -> 25 -> 20 -> 30 -> 30";
	checkAnswer(s, mylist.checkList(), false);
  }
  {
    IntegerLinkedList mylist;
    mylist.addFront(30);
    mylist.addFront(30);
    mylist.addFront(20);
    mylist.addFront(20);
    mylist.addFront(10);
    mylist.addFront(10);
    mylist.addFront(57);
    string s = "List: 57 -> 10 -> 10 -> 20 -> 20 -> 30 -> 30";
	checkAnswer(s, mylist.checkList(), true);
  }
  {
    IntegerLinkedList mylist;
    mylist.addFront(1957);
    mylist.addFront(30);
    mylist.addFront(20);
    mylist.addFront(20);
    mylist.addFront(10);
    mylist.addFront(10);
    mylist.addFront(57);
    string s = "List: 57 -> 10 -> 10 -> 20 -> 20 -> 30 -> 1957";
	checkAnswer(s, mylist.checkList(), false);
  }
  {
    IntegerLinkedList mylist;
    mylist.addFront(57);
    mylist.addFront(30);
    mylist.addFront(20);
    mylist.addFront(20);
    mylist.addFront(10);
    mylist.addFront(10);
    mylist.addFront(57);
    string s = "List: 57 -> 10 -> 10 -> 20 -> 20 -> 30 -> 57";
	checkAnswer(s, mylist.checkList(), true);
  }
  {
    IntegerLinkedList mylist;
    mylist.addFront(30);
    string s = "List: 30";
	checkAnswer(s, mylist.checkList(), false);
  }
  {
    IntegerLinkedList mylist;
    mylist.addFront(1957);
    mylist.addFront(30);
    string s = "List: 30 -> 1957";
	checkAnswer(s, mylist.checkList(), true);
  }
  // system("pause"); // comment/uncomment if needed
}

bool checkAnswer(const string &nameOfTest, bool received, bool expected) {
    if (received == expected) {
        cout << std::boolalpha << "PASSED " << nameOfTest << ": expected and received " << received << endl;
        return true;
    }
    cout << std::boolalpha << "FAILED " << nameOfTest << ": expected " << expected << " but received " << received << endl;
    return false;
}