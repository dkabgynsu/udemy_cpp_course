#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <iomanip>
#include <sstream>
#include <cctype>

using std::cout;
using std::cin;
using std::endl;

std::string clean_string(std::string &str)
{
    if(!isalpha(static_cast<char>(str.back())))
    {
        str.pop_back();
    }
    return str;

}

void display(const std::map<std::string, int> &m)
{
    int width_col1 = 15;
    int width_col2 = 10;
    
    std::string title_col1 {"WORD"};
    std::string title_col2 {"COUNT"};

    cout << std::setw((width_col1 - title_col1.length())/2) << ' ' << title_col1 << std::setw((width_col1 - title_col1.length())/2) << ' '; 
    cout << std::setw((width_col2 - title_col2.length())/2) << ' ' << title_col2 << std::setw((width_col2 - title_col2.length())/2) << ' ' << endl;

    for(std::pair<std::string, int>p : m)
    {
        cout << std::setw(width_col1) << std::left << p.first;
        cout << std::setw(width_col2) << p.second << endl;
    }

}

int main()
{
    std::ifstream in_file{"words.txt"};
    std::map<std::string, int> dictionary{};

    if(!in_file.is_open())
    {
        std::cerr << "The input file can not be opened" << endl;
        return -1;
    }

    std::string word{""};
    std::string line {""};
    while(!in_file.eof())
    {
        std::getline(in_file, line);
        std::stringstream ss{line};
        
        while(ss>>word)
        {
            word = clean_string(word);

            if(dictionary.count(word))
            {
                dictionary[word]++;

            }
            else
            {
                dictionary.insert(std::make_pair(word, 1));
            }
            word = "";
        }    
    }
    in_file.close();
    display(dictionary);
    return 0;
}