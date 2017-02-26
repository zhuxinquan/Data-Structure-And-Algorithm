/*************************************************************************
	> File Name: Fibonacci_recursion.c
	> Author: zhuxinquan
	> Mail: zhuxinquan61@xiyoulinux.org
	> Created Time: 2017年02月26日 星期日 14时50分41秒
 ************************************************************************/

#include<stdio.h>

int fibonacci(int n){
    if(n <= 0){
        return 0;
    }
    if(n == 1){
        return 1;
    }

    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main(int argc, char * argv[]){
    printf("%d\n", fibonacci(6));
}
