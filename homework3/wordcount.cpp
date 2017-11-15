#include <iostream>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

string fullText = "";
string currentWord = "";
map<string, int> words = { };

int main() {
    for (string line; std::getline(std::cin, line);) {
        fullText += line + " ";
    }
    for(char& c : fullText) {
        if (c == ' ') {
            transform(currentWord.begin(), currentWord.end(), currentWord.begin(), ::tolower);

            if (words.count(currentWord) == 0) {
                words.insert(pair<string,int>(currentWord, 1));
            } else {
                words[currentWord] += 1;
            }
            currentWord = "";
        } else {
            currentWord += c;
        }
    }

    for (auto it = words.cbegin(); it != words.cend(); ++it) {
        cout << (*it).first << " " << (*it).second << " \n";
    }
}
