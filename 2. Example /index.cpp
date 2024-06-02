/*
Coding Challenge:

This code demonstrates the use of STL algorithms, lambda functions, and 
functors. It defines a `Person_t` struct and a number of functions and 
functors that operate on `Person_t` objects. It then creates a vector of 
`Person_t` objects and performs various operations on them.

Your task is to extend this code with the following features:

1. Add a new member function to the `Person_t` struct that returns whether 
the person is a senior (age 65 or older).

2. Modify the `main` function to count the number of seniors in the `people` 
vector using the `count_if` algorithm and a lambda function.

3. Add a new function that takes a vector of `Person_t` objects and a 
predicate function. This function should return a new vector that contains 
only the objects for which the predicate returns true.

4. Modify the `main` function to call this new function with the `people` 
vector and a lambda function that checks whether a person is a senior. Print 
the returned vector.

5. Add error checking to the code that sorts the `people` vector. If the 
vector is already sorted, print a message and skip the sorting operation.

Remember to follow best practices for using STL containers and algorithms: 
use iterators to access elements, check the result of operations like 
`find`, and be aware of the characteristics of each container type.

*/



/*
 * This program demonstrates object-oriented programming in C++, using a class
 * to represent a person with a name and an age. It shows how to define a class
 * with private data members and public member functions, and how to use a
 * constructor to initialize the data members.
 *
 * The Person_t class includes a is_senior() member function that checks if
 * the person is a senior (age 65 or older). This demonstrates how to
 * encapsulate behavior in a class.
 *
 * The main() function creates a std::vector<Person_t> to store a collection
 * of people. This demonstrates how to use a vector to store multiple objects
 * of the same type.
 *
 * The print_people() function takes a vector of Person_t objects and prints
 * each person's name and age. This demonstrates how to pass a vector to a
 * function and how to iterate over a vector.
 *
 * The filter_seniors() function takes a vector of Person_t objects and
 * returns a new vector that contains only the seniors. This demonstrates how
 * to use the std::copy_if() algorithm to filter a collection based on a
 * predicate.
 *
 * Overall, this program is a good example of how to use classes, vectors, and
 * algorithms in C++. It could be extended in many ways, for example by adding
 * more data members or member functions to the Person_t class, or by adding more
 * functionality to the main() function.
 */


#include <iostream>
#include <vector>
#include <algorithm>

class Person_t {
private:
    int age;
    std::string name;
public:
    Person_t(std::string name, int age) : name(name), age(age) {}
    int get_age() const { return age; }
    std::string get_name() const { return name; }
    bool is_senior() const { return age >= 65; }
};

void print_people(const std::vector<Person_t>& people) {
    for (const auto& person : people) {
        std::cout << person.get_name() << " is " << person.get_age() << " years old.\n";
    }
}

std::vector<Person_t> filter_seniors(const std::vector<Person_t>& people) {
    std::vector<Person_t> seniors;
    std::copy_if(people.begin(), people.end(), std::back_inserter(seniors), [](const Person_t& p) {
        return p.is_senior();
    });
    return seniors;
}

int main() {
    std::vector<Person_t> people = {
        Person_t("Alice", 20),
        Person_t("Bob", 65),
        Person_t("Charlie", 70),
        Person_t("Dave", 30)
    };

    std::cout << "All people:\n";
    print_people(people);

    std::cout << "\nSeniors:\n";
    std::vector<Person_t> seniors = filter_seniors(people);
    print_people(seniors);

    return 0;
}