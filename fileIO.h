#include <iostream>

using namespace std;

class FileIO
{
    public:
        FileIO();
        FileIO(string filepath);
        ~FileIO();

        string collectDelimiters();

        string filepath;
};
