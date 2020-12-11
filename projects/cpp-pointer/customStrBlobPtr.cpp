//
// Created by dingguoliang on 2020/12/2.
//

#include "customStrBlobPtr.h"
using std::runtime_error;

shared_ptr<vector<string>> customStrBlobPtr::check(std::size_t i, const string &msg) const
{
    shared_ptr<vector<string>> s = wptr.lock();
    if (!s)
    {
        throw runtime_error("unbound customStrBlobPtr");
    }
    if(i >= s->size())
    {
        throw out_of_range(msg);
    }
    return s;
}

string& customStrBlobPtr::deref() const
{
    auto s = check(curr, "dereference past end");
    return (*s)[curr];
}

customStrBlobPtr& customStrBlobPtr::incr()
{
    auto s = check(curr, "increment past end of StrBlobPtr");
    ++curr;
    return *this;
}
