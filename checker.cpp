#include <iostream>
#include "genStack.h"

using namespace std;

Checker::Checker()
{
    FileIO io(filepath);
}
Checker::~Checker()
{

}

bool Checker::analyze()
{
    delims = io.collectDelimiters();

    cout << endl;
    cout << delims << endl;
    cout << endl;

    if(parenMatch(delims))
        cout << "all parentheses matched" << endl;
    else
    {
        cout << "file is missing a parentheses" << endl;
        return false;
    }
    if(curlyMatch(delims))
        cout << "all curly braces matched" << endl;
    else
    {
        cout << "file is missing a curly brace" << endl;
        return false;
    }
    if(squareMatch(delims))
        cout << "all square braces matched" << endl;
    else
    {
        cout << "file is missing a square brace" << endl;
        return false;
    }

    return true;

}

Bool Checker::parenMatch(string x)
{
    int line;
    GenStack <char> myStack();
    for(int i = 0; i < x.length() - 1; i++)
    {
        if (x[i] == '(')
            if (myStack.empty() && isNumber(x[i-1]))
            {
                line = parseNum(x[i-1]);
            }
            myStack.push(x[i]);
        else if (x[i] == ')')
        {
            if (myStack.empty())
                return false; //Nothing to match with
            if (myStack.top()  =! x[i])
                return false;
            myStack.pop();

        }
    }
    if (myStack.empty())
        return true; //every symbol matched
    else
    {
        cout << "Line " << line << " contains an unmatched (" << endl;
        return false; //some symbols were never matched
    }
}

Checker::curlyMatch(string x)
{
    int line;
    GenStack <char> myStack();
    for(int i = 0; i < x.length() - 1; i++)
    {
        if (x[i] == '{')
            if (myStack.empty() && isNumber(x[i-1]))
            {
                line = parseNum(x[i-1]);
            }
            myStack.push(x[i]);
        else if (x[i] == '}')
        {
            if (myStack.empty())
                return false; //Nothing to match with
            if (myStack.top()  =! x[i])
                return false;
            myStack.pop();

        }
    }
    if (myStack.empty())
        return true; //every symbol matched
    else
    {
        cout << "Line " << line << " contains an unmatched {" << endl;
        return false; //some symbols were never matched
    }
}

Checker::squareMatch(string x)
{
    int line;
    GenStack <char> myStack();
    for(int i = 0; i < x.length() - 1; i++)
    {
        if (x[i] == '[')
            if (myStack.empty() && isNumber(x[i-1]))
            {
                line = parseNum(x[i-1]);
            }
            myStack.push(x[i]);
        else if (x[i] == ']')
        {
            if (myStack.empty())
                return false; //Nothing to match with
            if (myStack.top()  =! x[i])
                return false;
            myStack.pop();

        }
    }
    if (myStack.empty())
        return true; //every symbol matched
    else
    {
        cout << "Line " << line << " contains an unmatched [" << endl;
        return false; //some symbols were never matched
    }
}
