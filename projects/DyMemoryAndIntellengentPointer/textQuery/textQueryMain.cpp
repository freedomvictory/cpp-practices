#include <iostream>
#include <fstream> 
#include <vector> 
#include <set> 
#include <string> 
#include <sstream> 

using std::cin; using std::cout; using std::endl; 
using std::ifstream; using std::istringstream; 
using std::string; using std::vector; using std::set; 

class TextQuery{

public:
    TextQuery() = default;
    TextQuery(ifstream&);
    string query(string);

private:
    vector<string> lines; 
    set<int> lineNums; 
    int wordOccur = 0; 

};

TextQuery::TextQuery(ifstream &file)
{
    string line;
    while(std::getline(file, line))
    {
        lines.push_back(line);
    }    
}

string TextQuery::query(string s)
{
    wordOccur = 0;
    lineNums.clear();

    int i = 0;
    for(auto line : lines)
    {
        i++; 
        istringstream is(line); 
        string word; 
        while(is >> word)
        {
            if(s == word)
            {
                lineNums.insert(i);
                wordOccur++;
            }
        }
    } 

    if (wordOccur == 0)
    {
        return "no any item!";
    }

    std::ostringstream outs; 
    outs << "element occurs " << wordOccur << "times" << "\n"; 

    for(auto p = lineNums.begin(); p != lineNums.end(); p++)
    {
        outs << "(line " << *p << ") " << lines[*p - 1] << "\n";
    }
    return outs.str(); 
}


void runQueries(ifstream &infile)
{
    TextQuery tq(infile);

    while(true)
    {
        cout << "enter word to llok for, or q to quit: ";
        string s;
        if(!(cin >> s) || s == "q")
            break;
        cout<< tq.query(s) << endl;  
    }
}


int main(int argc, char** argv)
{
    ifstream myfile; 
    myfile.open("example.txt");

    runQueries(myfile); 
    
}