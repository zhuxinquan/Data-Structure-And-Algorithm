/*************************************************************************
	> File Name: find_smax_two_select.c
	> Author: zhuxinquan
	> Mail: zhuxinquan61@gmail.com
	> Created Time: 2015年09月10日 星期四 17时07分29秒
 ************************************************************************/

#include<stdio.h>

int main(void)
{
    int a[10], max, smax, i;
    for(i = 0; i < 10; i++)
    {
        printf("input No.%d num:", i+1);
        scanf("%d", a+i);
    }

    max = a[0];
    for(i = 0; i < 10; i++)
    {
        if(max < a[i])
        {
            max = a[i];
        }
    }
    if(max != a[0])
    {
        smax = a[0];
    }
    else
    {
        smax = a[1];
    }
    for(i = 0; i < 10; i++)
    {
        if(a[i] < max && a[i] > smax)
        {
            smax = a[i];
        }
    }

    printf("No.1 is %d, No.2 is %d\n", max, smax);
}
