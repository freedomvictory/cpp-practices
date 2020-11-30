//
// Created by dingguoliang on 2020/11/22.
//

#include "gtest/gtest.h"
#include "Gregorian.h"


TEST(AbsoluteDateTestSuite, ExampleDate){

    GregorianDate gregDate;
    gregDate.SetMonth(12);
    gregDate.SetDay(2);
    gregDate.SetYear(2020);

    EXPECT_EQ(gregDate.getAbsoluteDate(), 737761);

}

TEST(AbsoluteDateTestSuite, IncorrectDate){
    GregorianDate gregDate;
    gregDate.SetMonth(12);
    gregDate.SetDay(0);
    gregDate.SetYear(2020);

    ASSERT_EQ(gregDate.getAbsoluteDate(),0);
}