/**
 * Created Puppy struct which is object that holds id, breed, and age for each line read in from the text file
 * Class BreedAnalysis has private member variable that is a vector of Puppy objects which stores each lines information from text file as new puppy object
 *
 * Public Member Functions of BreedAnalysis:
 * readFile(string) - This function is used to read all the data from file.
 * Takes in filename as param and reads each line, then creates new Puppy object with data from each line to push back into puppyList vector
 *
 * averageAge(string) - This function will return average age of desired breed from list.
 * Takes in breed name as argument and loops through the puppyList to either return average age of desired breed or 0 if breed is not found in the list.
 *
 * mostPopularBreed() - This function will return the most popular breed from the vector.
 * Function loops through each index in vector, and for each index loops again in the same loop to increment the count of the current breed. Then simple comparison of breed counts to assign and return correct popularBreed from the list.
 * ----------------------------
 */
#include <string>
#include <vector>
using namespace std;

// Puppy object that each line read in from file will be
struct Puppy {
public:
    string id;
    string breed;
    int age;
};

class BreedAnalysis {
private:
    // Array vector of Puppy objects
    vector<Puppy> puppyList;
public:
    // default constructor
    BreedAnalysis();
    void readFile(string file);
    double averageAge(string breed);
    string mostPopularBreed();
};
