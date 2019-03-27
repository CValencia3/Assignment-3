#include <iostream>
#include <fstream>
#include "fileIO.h"

using namespace std;

FileIO::FileIO()
{
    filepath = "testFile.c";
}
FileIO::FileIO(string fp)
{
    filepath = fp;
}
FileIO::~FileIO()
{

}

string FileIO::collectDelimiters()
{
    int count = 0;
    char c;
    string output;
    string line;

    ifstream file (filepath);

    if(file.is_open())
    {
        file.clear();
        file.seekg(0);

        while (getline (file, line))
        {
            //Keep track of what line you are on
            //output.append(to_string(++count));
            //iterate through each character and see if its a delimiter
            for (int i = 0; i < (line.size()-1); i++)
            {
                c = line[i];
                if(c == '(' || c == '{' || c == '[' || c == ']' || c == '}' || c == ')')
                {
                    output.append(1, c);
                }
            }
        }
        file.close();
    }
    else
    {
        cout << "Invalid filepath" << endl;
    }
    return output;
}
