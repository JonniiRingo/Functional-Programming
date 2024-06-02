unordered_map<string, int> count_occurences(vector<string> names) {

    // Your code goes here
    unordered_map<string, int>temp;
    for (auto it: names) {
        if(temp.find(it)== temp.end()){
            temp[it] = 1;
        }
        else {
            temp[it]++;
        }
     
       
    }
    cout << "---------------------------------------------------" << endl;
    for (auto i : temp) {
        cout << i.first << " " << i.second << endl;
    }
   

    return temp;

}

// Use transform and a for-loop
vector<string> words(string text) {

    // It is OK to use this for loop in your code
     //for (string w; iss >> w; )
       // sv.push_back(w);
    vector<string> tempv;
    string temp = "";
    for (int i = 0; i < text.size(); i++) {
        if (isalpha(text[i]) && text[i] != '\n') {
            temp += text[i];
        }
        else {
           
            if (temp != "") {
                tempv.push_back(temp);
                temp = "";
            }
        }
        if (i == text.size() - 1 && temp != "") {
            tempv.push_back(temp);
        }
    }

    for (int i = 0; i < tempv.size(); i++) {
        cout << tempv[i] << endl;
    }
    return tempv;
}   




vector<pair<int, string>> reverse_pairs(unordered_map<string, int> pairs) {
    vector<pair<int, string>> reversed_pairs;
    for (const auto& pair : pairs) {
        reversed_pairs.push_back(make_pair(pair.second, pair.first));
    }
    return reversed_pairs;
}




// Fourth
vector <pair<int, string>> sort_by_frequency(vector <pair<int, string>> v) {
    sort(v.begin(), v.end(), [](const pair<int, string>& a, const pair<int, string>& b) {
        return a.first > b.first;
    });
    return v;
}


// Fifth

void print_pairs(vector <pair<int, string>> v) {
    transform(v.begin(), v.end(), ostream_iterator<string>(cout, "\n"), [](pair<int, string> p) {
        ostringstream oss;
        oss << p.first << ": " << p.second;
        return oss.str();
    });
}


void print_common_words(string text) {
    // Call words to get a vector of words.
    vector<string> words_vector = words(text);

    // Call count_occurrences to get an unordered map of word frequencies.
    unordered_map<string, int> word_frequencies = count_occurrences(words_vector);

    // Call reverse_pairs to get a vector of pairs with the count first.
    vector<pair<int, string>> reversed_pairs = reverse_pairs(word_frequencies);

    // Call sort_by_frequency to sort the vector of pairs.
    vector<pair<int, string>> sorted_pairs = sort_by_frequency(reversed_pairs);

    // Call print_pairs to print the pairs.
    print_pairs(sorted_pairs);
}