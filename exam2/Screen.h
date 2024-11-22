#ifndef Screen_H
#define Screen_H

using namespace std;

class Screen {
    public:
        static string colorize(const string& text, const string& colorCode);
        static string heading(const string& text);
};

#endif
