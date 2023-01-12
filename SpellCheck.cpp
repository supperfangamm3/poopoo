#include <iostream>
#include <fstream>
#include <string>
#include <unordered_set>

using namespace std;

int main() {
    unordered_set<string> dictionary;

    ifstream dictFile("dictionary.txt");

    string word;
    while (dictFile >> word) {
        dictionary.insert(word);
    }

    cout << "Enter the text to spell-check: ";
    string text;
    getline(cin, text);

    string delimiters = " ,.!?;:";
    size_t start = text.find_first_not_of(delimiters);
    size_t end = text.find_first_of(delimiters, start);

    while (start != string::npos || end != string::npos) {
        string word = text.substr(start, end - start);
        if (dictionary.count(word) == 0) {
            cout << "Incorrect spelling: " << word << endl;
        }
        start = text.find_first_not_of(delimiters, end);
        end = text.find_first_of(delimiters, start);
    }

    return 0;
}
