#include <iostream>

using namespace std;

class FileIO
{
    public:
        FileIO();
        FileIO(string filepath);

        static void TestPath(string path);
    private:
        string filepath;

}
