//
// Created by dingguoliang on 2020/11/22.
//

#include "gtest/gtest.h"


TEST(PayrollTest, TestAddSalariedEmployee) {

    int empId = 1;
    AddSalariedEmployee t(empId, "Bob", "Home", 1000);
    t.Execute();

    Employee* e = GpayrollDatabase.GetEmployee(empId);
    EXPECT_EQ("Bob", e->GetName());

    PaymentClassfication* pc = e->GetClassification();
    SalariedClassification* sc = dynamic_cast<SalariedClassification*>(pc);
    assert(sc);

    EXPECT_EQ(1000.00, sc->GetSalary());

    PaymentSchedule* ps = e->GetSchedule();
    MonthlySchedule* ms = dynamic_cast<MonthlySchedule*>(ps);
    assert(ms);

    PaymentMethod *pm = e->GetMethod();
    HoldMethod *hm = dynamic_cast<HoldMethod*>(pm);
    assert(hm);



}

