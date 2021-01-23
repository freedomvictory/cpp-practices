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

    PaymentClassfication* pc = e->GetClassification(); //核算薪资的方式：有的是按小时，有的是按月，有的是按月薪和酬金
    SalariedClassification* sc = dynamic_cast<SalariedClassification*>(pc);
    assert(sc);

    EXPECT_EQ(1000.00, sc->GetSalary());

    PaymentSchedule* ps = e->GetSchedule(); //时间表
    MonthlySchedule* ms = dynamic_cast<MonthlySchedule*>(ps);
    assert(ms);

    PaymentMethod *pm = e->GetMethod(); //支付方法
    HoldMethod *hm = dynamic_cast<HoldMethod*>(pm);
    assert(hm);



}

