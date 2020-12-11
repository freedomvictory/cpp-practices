//
// Created by dingguoliang on 2020/11/11.
//

#include "customStrBlob.h"
#include "customStrBlobPtr.h"




customStrBlob::customStrBlob()
    : data(make_shared<vector<string>>())
{

}

customStrBlob::customStrBlob(std::initializer_list <string> il)
    : data(make_shared<vector<string>>(il))
{

}

void customStrBlob::check(size_type i, const string &msg) const
{
    if(i >= data->size())
        throw out_of_range(msg);
}

std::string& customStrBlob::front() const
{
    check(0, "front on empty StrBlob");
    return data->front();
}

std::string& customStrBlob::back() const
{
    check(0, "back on empty StrBlob");
    return data->back();
}

void customStrBlob::pop_pack()
{
    check(0, "pop back on empty StrBlob");
    data->pop_back();
}

customStrBlobPtr customStrBlob::begin()
{
    return customStrBlobPtr(*this);
}

customStrBlobPtr customStrBlob::end()
{
    return customStrBlobPtr(*this, data->size());
}