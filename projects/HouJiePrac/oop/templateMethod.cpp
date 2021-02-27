//
// Created by dingguoliang on 2021/2/25.
//

#include <iostream>

using namespace std;


//template method
class CDocument
{
public:
    void OnFileOpen()
    {
        cout << "dialog .." << endl;
        cout << "check file status..." << endl;
        cout << "open file..." << endl;
        Serialize();
        cout << "close file ..." << endl;
        cout << "update all views ..." << endl;
    }
    virtual void Serialize()
    {} ;
};

class CMyDoc : public CDocument
{
public:
    virtual void Serialize() override
    {
        cout << "CMyDoc::Serialize()" << endl;
    }
};
int main()
{
    CMyDoc myDoc;
    myDoc.OnFileOpen();
}