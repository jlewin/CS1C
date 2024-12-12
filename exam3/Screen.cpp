#include <iostream>
#include <string>
#include <sstream>

#include "Screen.h"

// Helper for Ansi color codes
string colorize(const string& text, const string& colorCode) {
    stringstream  buffer;
    buffer << "\033[" << colorCode << text << "\033[0m";

    return buffer.str();
}

string headingText(const string& text) {
    return colorize(text, "0;33m");
}

string titleText(const string& text) {
    return colorize(text, "2;34m");
}

void choiceRow(const string& text)
{
    cout << ' ' << headingText(text);
}

void reportChoiceError(char choice)
{
    cout << "'\033[1;31m" << choice
          << "\033[0m' is an invalid option, please try again.\n";
}

char getMenuChoice()
{
    choiceRow("Enter Your Choice: ");
    //cout << "\033[1;33m";

    char choice = ' ';
    cin >> choice;
    choice = toupper(choice);

    //cout << "\033[0m";

    return choice;
}

void pauseForEnter()
{
    cin.ignore(10, '\n');

    char nextChar;
    // Referenced implementation from https://stackoverflow.com/a/17665821/84369
    do
    {
        cout << "Press <\033[1;33mEnter\033[0m> to continue... ";
        nextChar = cin.get();
    } while (nextChar != '\n');
    cin.putback('\n');
}

void clearScreen()
{
    // See - https://stackoverflow.com/a/32008479/84369
   // cout << "\033[2J\033[1;1H";
}

void showHeading(const string& title, string indent)
{
    clearScreen();

    cout << titleText(title) << endl;
    printSeparator(indent);
}

string separator(string indent) {
    return indent + "─────────────────────────────────────────────────────────────────────────────";
}

void printSeparator(string indent) {
    cout << separator(indent) << endl;
}

