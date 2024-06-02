 #include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <unordered_map>
using namespace std;

// First
vector<string> words(string text) { 
    vector<string> result; 
    string each_word; 
    for_each(text.begin(), text.end(), 
        [&] (char c){
            if(isalpha(c)){
                each_word.push_back(c);
            }else{
                if (!each_word.empty()){
                    result.push_back(each_word);
                    each_word.clear();
                }
            }
        });

    if (!each_word.empty()){
        result.push_back(each_word);
    }
    return result; 
}

// Second
unordered_map<string, int> count_occurrences(vector<string> words) {
    unordered_map<string, int> word_frequency;
    for (const string& word : words) {
        ++word_frequency[word];
    }
    return word_frequency;
}

// Third
vector <pair<int, string>> reverse_pairs(unordered_map<string, int> pairs) {
    vector<pair<int, string>> reversed_pairs;
    for(const auto& pair : pairs){
        reversed_pairs.push_back(make_pair(pair.second, pair.first)); 
    }
    return reversed_pairs; 
}

// Fourth
vector <pair<int, string>> sort_by_frequency(vector <pair<int, string>> v) {
    sort(v.begin(), v.end(), 
    [](const pair<int, string>& a, const pair<int, string>& b) {
        return a.first > b.first; 
    }); 
    return v; 
}

// Fifth
void print_pairs(vector <pair<int, string>> v) {
    transform(v.begin(), v.end(), ostream_iterator<string>(cout, "\n"),
        [](pair<int, string> p){
            ostringstream oss; 
            oss << p.first << ": " << p.second;
            return oss.str(); 
        }); 
}

// Sixth 
void print_common_words(string text) {
    vector<string> words_vector = words(text); 
    unordered_map<string, int> word_frequencies = count_occurrences(words_vector);
    vector<pair<int, string>> reversed_pairs = reverse_pairs(word_frequencies);
    vector<pair<int, string>> sorted_pairs = sort_by_frequency(reversed_pairs); 
    print_pairs(sorted_pairs); 
}

int main() {
    print_common_words("the.the.the,a,\nword\nword\n,a,b,a");
}