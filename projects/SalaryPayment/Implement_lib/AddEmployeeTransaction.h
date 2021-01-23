//
// Created by dingguoliang on 2020/12/26.
//

#ifndef ADDEMPLOYEETRANSACTION_H
#define ADDEMPLOYEETRANSACTION_H

#include <iostream>
#include "Transaction.h"
using std::string;


class PaymentClassfication;
class PaymentSchedule;

class AddEmployeeTransaction : public Transaction{

public:
    virtual ~AddEmployeeTransaction();
    AddEmployeeTransaction(int empid, string address, string name);
    virtual PaymentClassfication* GetClassfication() const = 0;
    virtual PaymentSchedule* GetSchedule() const = 0;
    virtual void Execute();


private:
    int itsEmpid;
    string itsAddress;
    string itsName;

};


#endif
