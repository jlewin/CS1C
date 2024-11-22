// Constants.h
#ifndef CONSTANTS_H
#define CONSTANTS_H

const int MAX_COMPARTMENTS = 15;

class FormattingOptions {
    public:
        static FormattingOptions& getInstance() {
            static FormattingOptions instance;
            return instance;
        }

        bool showEmptyCompartments = false;
        bool showCheckedOutOnly = true;
        bool showAllItems = false;
        bool showCheckedInOnly = false;
    private:
        FormattingOptions() = default; // Private constructor
};

#endif // CONSTANTS_H