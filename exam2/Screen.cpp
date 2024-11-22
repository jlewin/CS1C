#include <iostream>
#include <string>
#include <sstream>

#include "Screen.h"

// Helper for Ansi color codes
string Screen::colorize(const string& text, const string& colorCode) {
    stringstream  buffer;
    buffer << "\033[" << colorCode << text << "\033[0m ";

    return buffer.str();
}

string Screen::heading(const string& text) {
    return colorize(text, "2;33m");
}

