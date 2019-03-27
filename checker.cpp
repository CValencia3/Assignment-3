#include <iostream>
#include "checker.h"
#include "genStack.h"

using namespace std;

Checker::Checker()
{
    FileIO io("testFile.c");
}
Checker::Checker(string fp)
{
    FileIO io(fp);
}
Checker::~Checker()
{

}

bool Checker::analyze()
{
    //get a string containg all delimiters
    delims = io.collectDelimiters();

    cout << delims << endl;

    //check for each delimiter and break when an error is found
    if(delimMatch(delims,"()"))
        cout << "all parentheses matched" << endl;
    else
    {
        cout << "file is missing a parentheses" << endl;
        return false;
    }
    if(delimMatch(delims,"{}"))
        cout << "all curly braces matched" << endl;
    else
    {
        cout << "file is missing a curly brace" << endl;
        return false;
    }
    if(delimMatch(delims,"[]"))
        cout << "all square braces matched" << endl;
    else
    {
        cout << "file is missing a square brace" << endl;
        return false;
    }

    return true;

}

bool Checker::delimMatch(string x, string delimiters)
{
    GenStack <char> myStack(128);
    for(int i = 0; i < x.length(); i++)
    {
        if (x[i] == delimiters[0])
        {
            myStack.push(x[i]);
        }
        else if (x[i] ==  delimiters[1])
        {
            if (myStack.isEmpty())
                return false; //Nothing to match with
            myStack.pop();

        }
    }
    if (myStack.isEmpty())
        return true; //every symbol matched
    else
    {
        cout << " contains an unmatched " << delimiters << endl;
        return false; //some symbols were never matched
    }
}
