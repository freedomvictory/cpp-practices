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
    TestVaList(3, array, 88, 123.8829, a);


    return 0;

}

