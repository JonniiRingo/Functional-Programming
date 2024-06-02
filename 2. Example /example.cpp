/*
This C++ program demonstrates the use of several standard library features, including vectors, algorithms, 
arrays, and lambda functions. The program defines a Person_t class with a get_age method, representing a person 
with an age attribute. A function named 'foo' is defined which takes an array of 5 integers and prints each element.
Another function named 'addOne' is defined which prints "return 3" and returns the integer 3.
In the main function, a vector of Person_t objects is created, but no objects are added to it in this code.
A lambda function 'older' is defined which takes an integer 'age' and returns another lambda function. 
This returned function takes a Person_t object and checks if its age is greater than the specified 'age'.
The count_if algorithm from the <algorithm> library is used with the 'older' function to count the number 
of people in the 'people' vector who are older than a certain age. However, since the 'people' vector is empty, 
these counts will always be 0. Another lambda function 'func' is defined to double a number.
Finally, another count_if is used with a lambda function to count the number of people older than a limit. 
Again, this will be 0 because the 'people' vector is empty.
Please note that this code will not produce meaningful output as it stands because the 'people' vector 
is empty and no Person_t objects are created or added to it.
*/




#include <iostream>                                       // Include for input/output
#include <vector>                                         // Include for vector data structure
#include <algorithm>                                      // Include for algorithm functions
#include <array>                                          // Include for array data structure
#include <deque>                                          // Include for deque data structure

using namespace std;

class Person_t {                                         // Define a class Person_t
public:
    int get_age() const { return age; }                  // Method to get age
private:
    int age;                                             // Age of the person
};

void foo(array<int, 5> a) {                              // Function taking an array of 5 integers
    for (const auto& i : a) {                            // For each element in the array
        cout << i << " ";                                // Print the element
    }
    cout << endl;
}

int addOne() {                                           // Function to add one
    cout << "return 3 " << endl;                         // Print "return 3"
    return 3;                                            // Return 3
}

int main() {                                             // Main function
    vector<Person_t> people;                             // Vector of Person_t objects

    auto older = [](int age) {                           // Lambda function to check if a person is older 
        return [age](const Person_t& p) {                // than a given age
            return p.get_age() > age;
        };
    };

    cout << "___________________" << endl;
    cout << count_if(begin(people), end(people), older(30)) << endl; 
                                                         // Count people older than 30

    cout << "__________________ num older 30:" << endl;
    cout << count_if(begin(people), end(people), older(30)) << endl; 
                                                         // Count people older than 30

    cout << "__________________ num older 20:" << endl;
    cout << count_if(begin(people), end(people), older(20)) << endl; 
                                                         // Count people older than 20

    auto func = [](int a) { return a * 2; };             // Lambda function to double a number
    cout << func(2) << endl;                             // Call func with argument 2, prints 4

    int limit = 10;                                      // Define limit as 10

    cout << "__________________ num older 10:" << endl;
    cout << count_if(begin(people), end(people), [limit](const Person_t& p) {
        return p.get_age() > limit;                      // Count people older than 10
    }) << endl;

    return 0;
}