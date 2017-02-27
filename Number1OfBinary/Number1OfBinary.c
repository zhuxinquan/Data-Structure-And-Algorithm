/*************************************************************************
	> File Name: Number1OfBinary.c
	> Author: zhuxinquan
	> Mail: zhuxinquan61@xiyoulinux.org
	> Created Time: 2017年02月26日 星期日 17时44分04秒
 ************************************************************************/

#include<stdio.h>

/*
 * 若使用原数值移位的方式有可能导致死循环
 * 负数右移会导致最左边的位数一直是1
 * 1的个数也会添加
 */
int number1OfBinary(int n){
    int count = 0;
    int flag = 1;
    int c = 1;
    while(flag){
        if(n & flag){
            count++;
        }
        flag = flag << 1;
        printf("%d  flag:%d\n", ++c, flag);
    }
    return count;
}

int number1OfBinary_1(int n){
    int count = 0;
    while(n){
        count++;
        n = (n - 1) & n;
    }
    return count;
}

int main(void){
    printf("%d\n", number1OfBinary(4));
    printf("%d\n", number1OfBinary_1(4));
    //printf("%d\n", number1OfBinary(0x80000000));
}
