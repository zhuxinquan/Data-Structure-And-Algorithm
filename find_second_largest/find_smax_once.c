/*************************************************************************
	> File Name: find_smax_once.c
	> Author: zhuxinquan
	> Mail: zhuxinquan61@gmail.com
	> Created Time: 2015年09月10日 星期四 17时28分01秒
 ************************************************************************/

#include<stdio.h>

int main(void)
{
    int a[10], i, max, smax;
    for(i = 0; i < 10; i++)
    {
        printf("input No.%d num:", i+1);
        scanf("%d", a+i);
    }
    max = smax = a[0];
    for(i = 0; i < 10; i++)
    {
        if(a[i] > max)
        {
            smax = max;
            max = a[i];
        }
        else
        {
            if(a[i] > smax)
            {
                smax = a[i];
            }
        }
    }
    printf("No.1 is %d, No.2 is %d\n", max, smax);
}
