/*************************************************************************
	> File Name: hanoi.c
	> Author: zhuxinquan
	> Mail: zhuxinquan61@gmail.com
	> Created Time: 2015年09月27日 星期日 19时11分41秒
 ************************************************************************/

#include<stdio.h>

int i = 1;                  //记录第几步

void move(int n, char from, char to)
{
    printf("第%d步，将编号为%d从盘子%c移到%c\n", i++, n, from, to);     //输出当前操作
}

void hanoi(int n, char from, char depend_on, char to)
{
    if(n == 1)
    {
        move(n, from, to);
    }
    else
    {
        hanoi(n-1, from, to, depend_on);                //将上面n-1个移到过度塔座
        move(n, from, to);                              //将剩余的最后一个大的直接移到目的塔座
        hanoi(n-1, depend_on, from, to);                //将过度塔座上的移到目的塔座
    }
}

void main(void)
{
    int n;
    printf("请输入盘子个数：");
    scanf("%d", &n);
    printf("盘子异动情况如下：\n");
    hanoi(n, 'A', 'B', 'C');
}
