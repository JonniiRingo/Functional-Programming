// OVERVIEW:
// This program takes a string as input and applies various operations on it.
// It demonstrates the use of functional programming by applying different
// functions to manipulate and display the string's characters. It uses both
// traditional STL algorithms and modern C++20 ranges for this purpose.







#include <iostream>
#include <string>
#include <algorithm> 
#include <ranges>
using namespace std;

// Print all characters using a for loop
void print_characters(const string& str) {
    for(char c: str) {
        cout << c << " ";
    }
    cout << "\n";
}

// Print uppercase characters using a for loop and if statement
void print_uppercase_characters(const string& str) {
    for(char c: str) {
        if (isupper(c)) {
            cout << c << " ";
        }
    }
    cout << "\n";
}

// Print lowercase characters using the `remove_if` algorithm and a lambda function
void print_lowercase_characters(string& str) {
    auto removed = remove_if(str.begin(), str.end(),
    [](char c) {
        return !islower(c); 
    });

    for(auto it = str.begin(); it != removed; ++it) {
        cout << *it << " ";
    }
    cout << "\n";
}

// Print lowercase characters using the ranges library
void print_lowercase_characters_ranges(const string& str) {
    auto is_lower = [] (auto c) {return islower(c); };

    auto view = ranges::views::filter(str, is_lower);

    ranges::copy(view, ostream_iterator<char>{cout, " "});
    cout << "\n";
}

int main() {
    string s = "Hello, World!";

    print_characters(s);
    print_uppercase_characters(s);
    print_lowercase_characters(s);
    print_lowercase_characters_ranges(s);

    return 0;
}