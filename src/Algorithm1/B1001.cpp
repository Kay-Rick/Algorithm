#include<stdio.h>
/*
 * @Author: Rick
 * @Email: Kay_Rick@outlook.com
 * @Date: 2020-02-15 17:02:26
 * @Last Modified by:   Rick
 * @Last Modified time: 2020-02-15 17:02:26
 * @Description: PAT B1001题
 */

int step = 0;
int func(int n);

int main(void)
{
    printf("%d\n", func(100));
    return 0;
}
int func(int n){
    if (n == 1)
    {
        return step;
    }else if (n % 2 == 0)
    {
        step++;
        func(n / 2);
    }else
    {
        step++;
        func((3 * n + 1) / 2);
    }
    return step;
}
