/*************************************************************************
	> File Name: find_smax.c
	> Author: zhuxinquan
	> Mail: zhuxinquan61@gmail.com
	> Created Time: 2015年09月10日 星期四 16时44分37秒
 ************************************************************************/

#include<stdio.h>

void bubble(int *, int );

int main(void)
{
    int a[10], i;
    for(i = 0; i < 10; i++)
    {
        printf("input No.%d num:", i + 1);
        scanf("%d", a + i);
    }
    bubble(a, 10);
    printf("No.1 is %d, No.2 is %d\n", a[0], a[1]);
}

void bubble(int a[], int n)
{
    int i, j, t;
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n-i-1; j++)
        {
            if(a[j] < a[j+1])
            {
                t = a[j];
                a[j] = a[j+1];
                a[j+1] = t;
            }
        }
    }
}
