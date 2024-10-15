#include <iostream>
#include <cstring>

using namespace std;

void transformString(string& text);
bool replaceNumbers(string& text);
bool replaceE(string& text);

int main() {
    string text;
    getline(cin, text);

    transformString(text);

    cout << text << endl;
    return 0;
}

// Case 1
bool replaceAfterAsterisks(string& text) {
    bool replaceVowels = false;

    for (int i = 0; i < text.length(); i++) {
        char c = text[i];
        if (c == '*') {
            replaceVowels = true;
           continue;
        } else if (replaceVowels) {
            switch (tolower(c)) {
                case 'a':
                case 'e':
                case 'i':
                case 'o':
                case 'u':
                    // Replace vowels with fixed char
                    text[i] = 'i';
                    break;
            }
        }
    }

    return replaceVowels;
}

bool replaceAfterPound(string& text) {
    // Remove leading # 
    if (text[0] == '#') {
        text = text.substr(1);

        // Replace numbers
        bool hasNumbers = replaceNumbers(text);

        if (!hasNumbers) {
            hasNumbers = replaceE(text);
        }

        return hasNumbers;
    }

    return false;
}

bool replaceNumbers(string& text) {
    bool hasNumbers = false;
    int end = text.length();

    for (int i = 0; i < end; i++) {
        char c = text[i];
        if (c >= '0' && c <= '9') {
            hasNumbers = true;
            int num = c - '0';
            text.replace(i, 1, string(num, '-'));
            i += num - 1;
            end = text.length();
        }
     }

     return hasNumbers;
}

bool replaceE(string& text) {
    bool hasEChar = false;
     for (int i = 0; i < text.length(); i++) {
        switch (tolower(text[i])) {
            case 'e':
                // Replace e's with fixed char
                text[i] = '3';
                hasEChar = true;
                break;
        }
    }

    return hasEChar;
}

void transformString(string& text) {
    bool hasAstericks = replaceAfterAsterisks(text);
    bool hasPound = replaceAfterPound(text);

    if (!(hasPound || hasAstericks)) {
        // Insert newline at midpoint
        text.insert(text.length() / 2, 1, '\n');
    }
}

int main_tests() {
    string items[] = {
        "Hello *World",
        "#Create 3 some separation 2 here",
        "#Some *unreadable text as all vowels 2 will be changed",
        "#No numbers in the text",
        "Last transformation"
    };

    for (string testCase : items) {
        cout << testCase << endl;
        transformString(testCase);
        cout << testCase << endl << endl;
    }

    cout << endl;
    return 0;
}
