#include "iooper.h"
#include <iostream> 
#include <vector> 
#include <string>
#include <fstream>
#include <sstream>


using std::vector; 
using std::istringstream;
using std::ifstream;
using std::string;


void IoOper::ReadFileWord()
{
    ifstream file("test.txt");
    vector<string> lines_content;

    for(string line; std::getline(file, line); lines_content.push_back(line));
    for(const auto &val : lines_content)
    {
        istringstream stream(val);
        for(string word; stream >> word; std::cout << word << std::endl);
        std::cout << "------------------------------\n";
    }





}