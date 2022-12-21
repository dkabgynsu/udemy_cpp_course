#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <iomanip>

using std::cout;
using std::cin;
using std::endl;

void display(std::map<std::string, int> m)
{
    int width_col1 = 15;
    int width_col2 = 10;
    
    std::string title_col1 {"WORD"};
    std::string title_col2 {"COUNT"};

    cout << std::setw((width_col1 - title_col1.length())/2) << ' ' << title_col1 << std::setw((width_col1 - title_col1.length())/2) << ' '; 
    cout << std::setw((width_col2 - title_col2.length())/2) << ' ' << title_col2 << std::setw((width_col2 - title_col2.length())/2) << ' ' << endl;

    for(std::pair<std::string, int>p : m)
    {
        
    }

}

int main()
{
    std::ifstream in_file{"words.txt"};
    std::string line{};
    std::map<std::string, int> dictionary{};

    if(!in_file.is_open())
    {
        std::cerr << "The input file can not be opened" << endl;
        return -1;
    }

    while(!in_file.eof())
    {
        std::getline(in_file, line);
        std::string word{};
        for(char c: line)
        {
            if(c==' ' || c == '\n')
            {
                if(dictionary.count(word))
                {
                    dictionary[word]++;
                }
                else
                {
                    dictionary.insert(std::make_pair(word, 0));
                }
            }
            else
            {
                word += c;
            }
        }
    }
    




    return 0;
}