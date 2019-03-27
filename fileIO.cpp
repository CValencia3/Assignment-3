#include <iostream>

using namespace std;

FileIO::FileIO(string fp)
{
    filepath = fp;
    ifstream file (filepath);
}
FileIO::~FileIO()
{
    file.close();
}

string FileIO::collectDelimiters()
{
    int count = 0;
    char c;
    string output;
    if(file.is_open())
    {
        file.clear();
        file.seekg(0);

        while (getline (file, line))
        {
            //Keep track of what line you are on
            output.append(++count);
            //iterate through each character and see if its a delimiter
            for (int i = 0; i < (line.size()-1); i++)
            {
                c = line[i];
                if(c == '(' || c == '{' || c == '[' || c == ']' || c == '}' || c == ')')
                {
                    output.append(c);
                } 
            }
        }

    }
}
