#ifndef RICKY_TICKETMASTER_H
#define RICKY_TICKETMASTER_H

#include <string>
#include <array>
using namespace std;

class Rick {
    private:
        array <string, 28> ascii;
        string lyrics;
    public:
        Rick ();
        void roll ();
        bool isPasscode (string &);
};

#include "ricky.cpp"

#endif