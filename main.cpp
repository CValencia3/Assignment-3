#include <iostream>
#include "genStack.h"

using namespace std;

int main(int argc, char** argv )
{
    bool error = false;

    string filepath = "testfile.c";

    //Main function
    Checker myChecker(filepath);
    error = myChecker.analyze();

    cout << "is there an error?" << endl;
    cout << error << endl;

    return 0;

    /*
    if(argc > 0)
    {
        bool error = false;
        string io;

        string filepath = argv[1];

        //Main function
        Checker myChecker();
        error = myChecker.analyze(filepath);

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
                error = myChecker.analyze(filepath);
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
    */
}
