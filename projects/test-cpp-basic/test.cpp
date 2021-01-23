#include <iostream>
#include <cstdarg>
#include <stdio.h>
#include <string.h>


//0:int, 1:double, 2:float
void TestVaList(int count, int array[] ,...)
{

    va_list args;
    va_start(args, array);

    for(int i = 0; i < count; i++)
    {
        switch(array[i])
        {
            case 0:
                printf("value is %d\n", va_arg(args,int));
                break;
            case 1:
                double d = va_arg(args, double);
                unsigned char d_bytes[8];
                memcpy(d_bytes, &d, 8);
                printf("value is %lf\n", va_arg(args, double));
                break;

        }
    }
    

    va_end(args);

}


int main(void)
{
    int array[] = {0, 1, 2};
    float a = 22.3; 
  //  TestVaList(3, array, 88, 123.8829, a);

    float val_std = 180;
    float test_val_a = 180.015;
    float test_val_b = 179.074;

    float val_std_2 = 45;
    float test_val_c = 44.8676;
    float test_val_d = 219.343;

    float val_std_4 = 16;
    float test_val_e = 15.8335;

    bool ret = false;
    if(test_val_a > (val_std - 1) && test_val_a < (val_std + 1))
    {
        ret = true;
    }
    std::cout << "---1----ret: " << ret << std::endl;

    ret = false;
    if(test_val_b > (val_std - 1) && test_val_b < (val_std + 1))
    {
        ret = true;
    }
    std::cout << "----2-----ret:" << ret << std::endl;

    ret = false;
    if (test_val_c > (val_std_2 - 0.5) && test_val_c < (val_std_2 + 0.5))
    {
        ret = true;
    }
    std::cout << "----3-----ret:" << ret << std::endl;
    ret = false;
    if(test_val_e > (val_std_4 - 0.2) && test_val_e < (val_std_4 + 0.2))
    {
        ret = true;
    }
    std::cout << "----4-----ret:" << ret << std::endl;
    return 0;

}

