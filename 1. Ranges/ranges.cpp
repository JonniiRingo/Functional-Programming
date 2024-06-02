#include <iostream>                                       // Include for input/output
#include <vector>                                         // Include for vector data structure
#include <algorithm>                                      // Include for algorithm functions
#include <ranges>                                         // Include for range functions
using namespace std;                                      // Use standard namespace

void print_squares(const vector<int>& vec) {              // Function to print squares of vector elements
    for (int i : vec) {                                   // For each element in vector
        cout << i * i << " ";                             // Print square of element
    }
}

void print_squares2(const vector<int>& vec) {             // Function to print squares using transform

    vector<int> v;                                        // Create new vector
    transform(vec.begin(), vec.end(), back_inserter(v),   // Transform input vector to squares
        [](int i) {
            return i * i;
        });
    for_each(v.begin(), v.end(),                          // For each element in new vector
        [](int i) {
            cout << i << " ";                             // Print element
        });
}

void print_squares3(const vector<int>& vec) {             // Function to print squares using ranges

    ranges::transform(vec, ostream_iterator<int>{cout, "\n"}, // Transform and print squares
        [](int i) {
        return i * i;
    });
}

void print_even_squares(const vector<int>& vec) {         // Function to print squares of even numbers
    for (int i : vec) {                                   // For each element in vector
        if (i % 2 == 0) {                                 // If element is even
            cout << i * i << " ";                         // Print square of element
        }
    }
}

void print_even_squares2(vector<int>& vec) {              // Function to print squares of even numbers using transform

    auto removed = remove_if(vec.begin(), vec.end(),      // Remove odd numbers from vector
        [](int i) {
            return i % 2 != 0;
        });

    transform(vec.begin(), removed,                       // Transform remaining elements to squares
        ostream_iterator<int>{cout, " "},
        [](int i) {
            return i * i;
        });
}

void print_even_squares3(const vector<int>& vec) {        // Function to print squares of even numbers using ranges

    auto square = [](auto i) {return i * i; };            // Lambda to square a number
    auto is_even = [](auto i) {return i % 2 == 0; };      // Lambda to check if a number is even

    auto view = ranges::views::transform(                 // Transform filtered vector to squares
        ranges::views::filter(vec, is_even), square);

    ranges::copy(view, ostream_iterator<int>{cout, " "}); // Print the squares
}


void print_even_squares4(const vector<int>& vec) {        // Function to print squares of even numbers using ranges

    auto square = [](auto i) {return i * i; };            // Lambda to square a number
    auto is_even = [](auto i) {return i % 2 == 0; };      // Lambda to check if a number is even

    auto view = vec
        | ranges::views::filter(is_even)                  // Filter even numbers
        | ranges::views::transform(square);               // Transform filtered vector to squares

    ranges::copy(view, ostream_iterator<int>{cout, " "}); // Print the squares
}

int main()                                                // Main function
{
    vector<int> v{ 1, 2, 3, 4, 5, 6, 7 };                 // Create vector

    print_squares3(v);                                    // Call function to print squares
    print_even_squares3(v);                                // Call function to print squares of even numbers
}