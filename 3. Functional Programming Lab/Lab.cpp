// 1. words: Takes a string, returns a vector of words. Removes non-alphanumeric chars.
//    Can use a for-loop and transform.

// 2. count_occurrences: Takes a vector of words, returns an unordered map where
//    keys are words and values are frequencies.

// 3. reverse_pairs: Takes the unordered map of word frequencies, returns a vector
//    of pairs. Each pair has the count first and the word second.

// 4. sort_by_frequency: Takes the vector of pairs, sorts it in descending order
//    of frequency. If two words have the same frequency, they are sorted in
//    lexicographical order.

// 5. print_pairs: Takes the sorted vector of pairs, prints each pair in the
//    format "frequency: word".

// 6. print_common_words: Ties all the previous functions together. Takes a string
//    of text, prints the words in the text in descending order of frequency.
//    Steps in this function:
//    - Call words to get a vector of words.
//    - Call count_occurrences to get an unordered map of word frequencies.
//    - Call reverse_pairs to get a vector of pairs with the count first.
//    - Call sort_by_frequency to sort the vector of pairs.
//    - Call print_pairs to print the pairs.

// 7. main: Call print_common_words with the given string of text.


// main: Entry point. Calls print_common_words with a string of text.

// print_common_words: Orchestrates the process. Takes a string of text and:
// - Calls words to split text into a vector of words, removing non-alphanumeric chars.
// - Calls count_occurrences to count word frequency, storing results in a map.
// - Calls reverse_pairs to transform the map into a vector of pairs (count, word).
// - Calls sort_by_frequency to sort pairs in descending order of frequency.
// - Calls print_pairs to print each pair in the format "frequency: word".

// words: Takes a string, splits it into words, removes non-alphanumeric chars,
// and returns a vector of the cleaned words.

// count_occurrences: Takes a vector of words, counts the frequency of each word,
// and returns a map where the keys are words and the values are frequencies.

// reverse_pairs: Takes the map of word frequencies and transforms it into a vector
// of pairs. Each pair has the count as the first element and the word as the second.

// sort_by_frequency: Takes the vector of pairs and sorts it in descending order
// of frequency. If two words have the same frequency, they are sorted lexicographically.

// print_pairs: Takes the sorted vector of pairs and prints each pair in the
// format "frequency: word".

// 6. print_common_words: Ties all the previous functions together. Takes a string
//    of text, prints the words in the text in descending order of frequency.
//    Steps in this function:
//    - Call words to get a vector of words.
//    - Call count_occurrences to get an unordered map of word frequencies.
//    - Call reverse_pairs to get a vector of pairs with the count first.
//    - Call sort_by_frequency to sort the vector of pairs.
//    - Call print_pairs to print the pairs.


#include <string>
#include <cstring>
#include <vector>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <unordered_map>
using namespace std;



// First
vector<string> words(string text){
    // Your code goes here
    vector<string> result;
    string each_word;
    for_each(text.begin(), text.end(),
    [&] (char c){
        if(isalpha(c)){
            each_word.push_back(c);
        } else {
            if (!each_word.empty()){
                result.push_back(each_word);
                each_word.clear();
            }
        }
    }); 
    if(!each_word.empty()){
        result.push_back(each_word); 
    }
    return result;
}


// Second
unordered_map<string, int> count_occurrences(vector<string> words) {
    // Your code goes here
    unordered_map<string, int> word_frequency; 
    for(const string& word: words){
        ++word_frequency[word]; 
    }
    return word_frequency; 
}

// Third
vector <pair<int, string>> reverse_pairs(unordered_map<string, int> pairs) {
    // Your code goes here
    vector<pair<int, string>> reversed_pairs;
    for(const auto& pair : pairs){
        reversed_pairs.push_back(make_pair(pair.second, pair.first)); 
    }
    return reversed_pairs; 
}

// Fourth
vector <pair<int, string>> sort_by_frequency(vector <pair<int, string>> v) {
    // Your code goes here
    sort(v.begin(), v.end(), 
    [](const pair<int, string>& a, const pair<int, string>& b) {
        return a.first > b.first; 
    }); 
    return v; 
}



// Fifth
void print_pairs(vector <pair<int, string>> v) {
    // Your code goes here
    transform(v.begin(), v.end(), ostream_iterator<string>(cout, "\n"),
        [](pair<int, string> p){
            ostringstream oss; 
            oss << p.first << ": " << p.second;
            return oss.str(); 
        }); 
}

// Sixth 
void print_common_words(string text){
    // Your code goes here
    vector<string> words_vector = words(text); 
    unordered_map<string, int> word_frequencies = count_occurrences(words_vector); 
    vector<pair<int, string>> reversed_pairs = reverse_pairs(word_frequencies);
    vector<pair<int, string>> sorted_pairs = sort_by_frequency(reversed_pairs); 
    print_pairs(sorted_pairs); 
}


int main() {
    print_common_words("the.the.the,a,\nword\nword\n,a,b,a");
}

