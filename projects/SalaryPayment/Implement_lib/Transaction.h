//
// Created by dingguoliang on 2020/11/28.
//

#ifndef TRANSACTION_H
#define TRANSACTION_H


class Transaction
{
public:
    virtual ~Transaction();
    virtual void Execute() = 0;
};






#endif
