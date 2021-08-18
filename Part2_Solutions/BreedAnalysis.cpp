//
// Created by Beccs on 8/31/20.
//
#include <fstream>
#include <sstream>
#include <iostream>
using namespace std;

#include "BreedAnalysis.h"

// No real use for default constructor
BreedAnalysis::BreedAnalysis() {
    cout << "Default constructor called" << endl;
}

void BreedAnalysis::readFile(string file) {
    string buffer;
    ifstream inputFile;
    string str;

    inputFile.open(file);
    if (inputFile.is_open()) {
        // Loop while we keep getting input lines from text file
        while (getline(inputFile, buffer)) {
            // Empty buffer line at end of files so only when it's not empty line
            if (!buffer.empty()) {
                // Create new puppy object and assign id, breed, age from string of each input line
                istringstream ss(buffer);
                Puppy newPup;
                while (ss >> newPup.id >> newPup.breed >> newPup.age) {
                    puppyList.push_back(newPup);
                }
            }
        }
    }
}

double BreedAnalysis::averageAge(string breed) {
    int count = 0;
    int totalAge = 0;
    for (int i = 0; i < puppyList.size(); i++) {
        if (puppyList[i].breed == breed) {
            count++;
            totalAge += puppyList[i].age;
        }
    }
    // Return 0 when breed not found in list
    if (count == 0) {
        return 0;
    }
    // Otherwise we cast to double and return average age
    return (double)totalAge / (double)count;
}

string BreedAnalysis::mostPopularBreed() {
    string popularBreed;
    int popularCount = 0;
    int currentBreedCount;
    int listSize;

    for (int i = 0; i < puppyList.size(); i++) {
        // Reset listSize and currentBreedCount for every loop iteration of puppy list
        listSize = puppyList.size();
        currentBreedCount = 0;
        // Loop through entire list for current index breed and increment count for occurrence of current breed
        while (listSize > 0) {
            if (puppyList[i].breed == puppyList[listSize].breed) {
                currentBreedCount++;
            }
            listSize--;
        }
        // Re-Assign popularBreedCount when currentBreedCount is higher, and set the popularBreed to be current indexed breed
        if (currentBreedCount > popularCount) {
            popularCount = currentBreedCount;
            popularBreed = puppyList[i].breed;
        }
    }
    return popularBreed;
}
