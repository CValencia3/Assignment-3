#include <iostream>
#include "genStack.h"

using namespace std;

class Checker
{
    public:
        Checker();
        ~Checker();

        bool analyze(string filepath);

        FileIO io;


    private:
        GenStack myStack;

        int paren;
        int curly;
        int square;

        int length;

        string delims
}
