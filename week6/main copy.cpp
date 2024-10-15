#include "Rectangle.h"
#include <iostream>

double width;
double height;

double Rectangle::totalArea = 0;

using namespace std;


#include <iostream>

using namespace std;

bool isAnagram(const string& s1, const string& s2);

int main() {
    string string1, string2;
    cout << "Enter a string s1: ";
    cin >> string1;

    cout << "Enter a string s2: ";
    cin >> string2;

    bool isAG = isAnagram(string1, string2);
    cout << endl << string1 << " and " << string2 << (isAG ? " are" : " are not") << " anagrams" << endl;
    return 0;
}

bool isAnagram(const string& s1, const string& s2) {
    // Demo'd in class using sort, trying ad-hoc counting here for fun, and because I'm too lazy to lookup sort (introduced later) at this point.
    int len = s1.length();
    if (len != s2.length()) {
        return false;
    }

    int charCount1[len];
    int charCount2[len];

    for (int i = 0; i < len; i++) {
        char c = s1[i];

        for (int j = 0; j < len; j++) {
            charCount1[i] = (s1[i] == c) ? 1 : 0;
            charCount2[i] = (s2[i] == c) ? 1 : 0;
        }

        if (charCount1[i] != charCount1[i]) {
            return false;
        }
    }

    return true;
}


int main2() {
    Rectangle rect(5, 6);
    rect.setHeight(5);
    return 0;
}

Rectangle::Rectangle(double w, double h) {
    width = 0;
    height = 0;
    setWidth(w);
    setHeight(h);
}

double Rectangle::getWidth() const {
    return width;
}

double Rectangle::getHeight() const {
    return height;
}

void Rectangle::setWidth(double w) {
    double before = width * height;
    width = w;
    double after = width * height;

    // Apply the change to totalArea
    totalArea += after - before;
}

void Rectangle::setHeight(double h) {
    double before = width * height;
    height = h;
    double after = width * height;

    // Apply the change to totalArea
    totalArea += after - before;
}

double Rectangle::getTotalArea() {
    return totalArea;
}
