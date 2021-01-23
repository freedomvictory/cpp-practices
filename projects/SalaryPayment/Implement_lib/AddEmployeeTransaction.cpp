//
// Created by dingguoliang on 2020/12/26.
//

#include "AddEmployeeTransaction.h"
#include "PayrollDatabase.h"

class PaymentMethod;

extern PayrollDatabase GpayrollDatabase;

AddEmployeeTransaction::~AddEmployeeTransaction() noexcept
{

}

AddEmployeeTransaction::AddEmployeeTransaction(int empid, string address, string name)
:itsEmpid(empid)
,itsName(name)
,itsAddress(address)
{

}

void AddEmployeeTransaction::Execute()
{
    PaymentClassfication *pc = GetClassfication();
    PaymentSchedule *ps = GetSchedule();
    PaymentMethod *pm = new HoldMethod();
    Employee *e = new Employee(itsEmpid, itsName, itsAddress);
    e->SetClassfication(pc);
    e->SetSchedule(ps);
    e->SetMethod(pm);
    GpayrollDatabase.AddEmployee(itsEmpid, e);


}