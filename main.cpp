#include <iostream>
#include "checker.h"

using namespace std;


string UpperString(string str)
{
    string up = str;
    int i = 0;
    char c;
    while (up[i])
    {
      up[i] = toupper(up[i]);
      i++;
    }
    return up;
}


int main(int argc, char** argv )
{
    if(argc > 0)
    {
        bool error = false;
        string io;

        string filepath = argv[1];

        //Main function
        Checker myChecker(filepath);
        error = myChecker.analyze();

        //Looping mechanisms
        while (!error)
        {
            cout << "Would you like to analyze another file? [Y/N]" << endl;
            cin >> io;
            io = UpperString(io);
            if (io == "N")
            {
                cout << "Goodbye!" << endl;
                break;
            }
            else if (io == "Y")
            {
                cout << "Please enter the another file path: ";
                cin >> filepath;
                Checker myChecker(filepath);
                error = myChecker.analyze();
            }
            else
            {
                cout << "Unrecognized input. Please try again." << endl;
            }
        }
    }
    else
    {
        cout << "Please provide the file path for code you would like to check." << endl;
        cout << "USAGE ./main.out <file-path>" << endl;
    }

    cout << "The program exited successfully." << endl;
    return 0;
}
