#ifndef Screen_H
#define Screen_H

using namespace std;

// Screen Text
string colorize(const string& text, const string& colorCode);
string titleText(const string& text);
string headingText(const string& text);

void clearScreen();
void initMenu(const string& title);
void printSeparator();
string separator();
void reportChoiceError(char choice);
void choiceRow(const string& text);
char getMenuChoice();
void pauseForEnter();

#endif
