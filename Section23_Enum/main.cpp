#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    std::ifstream in_file;
    in_file.open("a.txt");
    if(in_file)
    {
        cout << "File is opened succesfully" << endl;
        in_file.close();
    }
    else
    {
        cerr << "File in not opened" << endl;
    }

    
    return 0;
}