//
// Created by dingguoliang on 2020/11/11.
//

#ifndef CPP_POINTER_CUSTOMSTRBLOB_H
#define CPP_POINTER_CUSTOMSTRBLOB_H

#include <iostream>
#include <vector>
#include <memory>

using std::string;
using std::vector;
using std::shared_ptr;
using std::make_shared;
using std::out_of_range;



class customStrBlobPtr;
class customStrBlob {


    friend class customStrBlobPtr;

public:



    typedef vector<string>::size_type size_type;
    customStrBlob();
    customStrBlob(std::initializer_list<string> il);
    size_type size()  const { return data->size(); }
    bool empty() const { return data->empty();}
    void push_back(const string &t) {data->push_back(t);}
    void pop_pack();

    string& front() const;
    string& back() const;
    customStrBlobPtr begin();
    customStrBlobPtr end();


private:
    shared_ptr<vector<string>> data;
    void check(size_type i, const string &msg) const;




};


#endif //CPP_POINTER_CUSTOMSTRBLOB_H
