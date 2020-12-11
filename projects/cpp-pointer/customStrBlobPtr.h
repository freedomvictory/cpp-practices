//
// Created by dingguoliang on 2020/12/2.
//

#ifndef CUSTOMSTRBLOBPTR_H
#define CUSTOMSTRBLOBPTR_H

#include "customStrBlob.h"

using std::weak_ptr;


class customStrBlobPtr {

public:
    customStrBlobPtr() : curr(0){ }
    explicit customStrBlobPtr(customStrBlob &c, std::size_t sz = 0) :
    wptr(c.data), curr(sz) {  }

    string& deref() const;
    customStrBlobPtr& incr();

private:

    shared_ptr<vector<string>> check(std::size_t i, const string& msg) const;
    weak_ptr<vector<string>> wptr;
    std::size_t curr;



};


#endif //CPP_POINTER_CUSTOMSTRBLOBPTR_H
