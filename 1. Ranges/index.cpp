/*
Coding Challenge:

This code demonstrates the use of STL algorithms and the new ranges library 
to print the squares of numbers in a vector. It defines several functions 
that print the squares of all numbers or just the even numbers.

Your task is to extend this code with the following features:

1. Add a function that prints the squares of the odd numbers in the vector 
using a for loop.

2. Add a function that prints the squares of the odd numbers using the 
`transform` algorithm and a lambda function.

3. Add a function that prints the squares of the odd numbers using the 
ranges library.

4. Modify the `main` function to call these new functions with the `v` 
vector.

5. Add error checking to the code that removes odd numbers from the vector. 
If the vector contains only even numbers, print a message and skip the 
removal operation.

Remember to follow best practices for using STL algorithms and the ranges 
library: use iterators to access elements, check the result of operations 
like `remove_if`, and be aware of the characteristics of each algorithm.


*/


#include <iostream>
#include <vector>
#include <algorithm> 
#include <ranges>
using namespace std;


////////////////////// 1. FOR LOOP FUNCTIONS    ////////////////////////////


void print_squares(const vector<int>& vec){          // Print all 
    for(int i: vec ){
        cout << i * i << " ";
    }
}

void print_even_squares(const vector<int>& vec ){     // Print even 
    for(int i: vec){
        if (i % 2 == 0){
            cout << i * i << " "; 
        }
    }
}

void print_squares_odd(const vector<int>& vec) {   // Print odd 
    for(int i: vec ){
        if(i % 2 != 0 ){
            cout << i * i << " ";
        }
    }
}


////////////////////// 2. TRANSFORM FUNCTIONS    ////////////////////////////

void print_squares2(const vector<int>& vec ){     // Print all 

    vector<int> v;
    transform(vec.begin(), vec.end(), back_inserter(v),
        [](int i){
            return i * i; 
        }); 
    for_each(v.begin(), v.end(), 
        [](int i ){
            cout << i << " "; 
        }); 
}


void print_even_squares2(vector<int>& vec){           // Print Even
    
    auto removed = remove_if(vec.begin(), vec.end(),
    [](int i) {
        return i % 2 != 0; 
    });

    transform(vec.begin(), removed, 
    ostream_iterator<int>{cout, " "}, 
    [](int i ){
        return i * i; 
    }); 
}

void print_squares2_odd(vector<int>& vec ){              // Print Odd 
 
    auto removed_even = remove_if(vec.begin(), vec.end(), 
        [](int i){
            return i % 2 == 0; 
        });

        transform(vec.begin(), removed_even,
            ostream_iterator<int>{cout, " "}, 
            [](int i ){
                return i * i; 
            });
}

////////////////////// 3. RANGES FUNCTIONS    ////////////////////////////


void print_squares3(const vector<int>& vec ){                   // Print all 

    ranges::transform(vec, ostream_iterator<int>(cout, " "), 
        [](int i){
            return i * i; 
        }); 
}


void print_even_squares3(const vector<int>& vec){              // Print even 
    auto square = [](auto i) {return i * i; }; 
    auto is_even = [] (auto i) {return i % 2 == 0; };

    auto view = ranges::views::transform(
            ranges::views::filter(vec, is_even), square);

    ranges::copy(view, ostream_iterator<int>{cout, " "});
}



void print_odd_squares3(const vector<int>& vec){              // Print even 
    auto square = [](auto i) {return i * i; }; 
    auto is_odd = [] (auto i) {return i % 2 != 0; };

    auto view = ranges::views::transform(
            ranges::views::filter(vec, is_odd), square);

    ranges::copy(view, ostream_iterator<int>{cout, " "});
}




int main(){
    vector<int> v1a{1,2,3,4,5,6,7 };
    vector<int> v1b{1,2,3,4,5,6,7 };

    vector<int> v2a{1,2,3,4,5,6,7 };
    vector<int> v2b{1,2,3,4,5,6,7 };

    vector<int> v3a{1,2,3,4,5,6,7 };
    vector<int> v3b{1,2,3,4,5,6,7 };


    cout << "" << endl;   
    cout << "First test " << endl; 
    print_squares(v1a);
    cout << "" << endl; 
    print_even_squares(v1a);
    cout << "" << endl; 
    print_squares_odd(v1b); 
    cout << "\n" << endl; 

    cout << "Second test " << endl; 
    print_squares2(v2a); 
    cout << "" << endl; 
    print_even_squares2(v2a);
    cout << "" << endl; 
    print_squares2_odd(v2b);
    cout << "\n" << endl; 

    cout << "" << endl;   
    cout << "Third test " << endl; 
    print_squares3(v3a);
    cout << "" << endl; 
    print_even_squares3(v3a);
    cout << "" << endl; 
    print_odd_squares3(v3b); 
    cout << "\n" << endl; 



}