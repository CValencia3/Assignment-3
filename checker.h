#include <iostream>
#include "fileIO.h"

using namespace std;

class Checker
{
    public:
        Checker();
        Checker(string filepath);
        ~Checker();

        bool analyze();
        bool delimMatch(string x, string delimiters);


    private:
        FileIO io;
        string delims;
};
