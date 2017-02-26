/*************************************************************************
	> File Name: Fibonacci_circulation.c
	> Author: zhuxinquan
	> Mail: zhuxinquan61@xiyoulinux.org
	> Created Time: 2017年02月26日 星期日 14时54分28秒
 ************************************************************************/

#include<stdio.h>

int fibonacci(int n){
    int result[2] = {0, 1};
    if(n < 2){
        return result[n];
    }

    long long fibOne = 0;
    long long fibTwo = 1;
    long long fib = 0;
    for(int i = 2; i <= n; i++){
        fib = fibOne + fibTwo;
        fibOne = fibTwo;
        fibTwo = fib;
    }

    return fib;
}

int main(int argc, char * argv[]){
    printf("%d\n", fibonacci(6));
}
