//
// Created by dingguoliang on 2020/12/1.
//

#include "PayrollDatabase.h"

PayrollDatabase::~PayrollDatabase()
{

}

void PayrollDatabase::AddEmployee(int empid, Employee* emp)
{
    itsEmployees[empid] = emp;
}

Employee* PayrollDatabase::GetEmployee(int empid)
{
    return itsEmployees[empid];
}