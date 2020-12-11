//
// Created by dingguoliang on 2020/12/1.
//

#ifndef PAYROLLDATABASE_H
#define PAYROLLDATABASE_H

#include <map>
using std::map;
class Employee;

class PayrollDatabase {

public:
    virtual ~PayrollDatabase();
    void AddEmployee(int empid, Employee *emp);
    Employee* GetEmployee(int empid);

private:
    map<int, Employee*> itsEmployees;

};


#endif
