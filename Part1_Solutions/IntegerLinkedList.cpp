// ADD ANSWER TO THIS FILE
#include <iostream>
using namespace std;

#include "IntegerLinkedList.h"

bool IntegerLinkedList::checkList() {
    // COMPLETE THIS FOR PROBLEM 2
    bool hasFiftySeven = false;
    bool hasNineteenFiftySeven = false;

    SNode *current = head;
    while (current != nullptr) {
        if (current->elem == 57 && !hasFiftySeven) {
            hasFiftySeven = true;
        } else if (current->elem == 1957 && !hasNineteenFiftySeven) {
            hasNineteenFiftySeven = true;
        }
        current = current->next;
    }
    return (hasFiftySeven && !hasNineteenFiftySeven) || (!hasFiftySeven && hasNineteenFiftySeven);

}

bool IntegerLinkedList::checkRecurse (SNode *ptr) {
    // COMPLETE THIS FOR PROBLEM 3
    if (ptr == nullptr) {
        return false;
    } else {
        return (ptr->elem == 57 || ptr->elem == 1957) || checkRecurse(ptr->next);
    }
}

void IntegerLinkedList::addFront(int x) {
    SNode *tmp = head;
    head = new SNode;
    head->next = tmp;
    head->elem = x;
}

// recursion helper function called from main for PROBLEM 3
bool IntegerLinkedList::checkRecurseHelper () {
    return checkRecurse(head);
}
