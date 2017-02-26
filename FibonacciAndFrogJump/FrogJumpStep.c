/*************************************************************************
	> File Name: FrogJumpStep.c
	> Author: zhuxinquan
	> Mail: zhuxinquan61@xiyoulinux.org
	> Created Time: 2017年02月26日 星期日 15时13分00秒
 ************************************************************************/

/**
 * 青蛙可以跳1,2,3，，，n级台阶
 * 求跳n级台阶有多少中跳法
 */
#include<stdio.h>

int frogJumpStep(int n){

    if(n <= 0){
        return 0;
    }
    if(n == 1){
        return 1;
    }
    int methods = 1;

/*    int fib = 0;
    int fibOne = 0;
    int fibTwo = 1;*/
    for(int i = 1; i < n; i++){
/*        fib = fibOne + fibTwo;
        fibOne = fibTwo;
        fibTwo = fib;*/
        methods += frogJumpStep(n - i);
    }

    return methods;
}

/*
 * f(n) = f(n - 1) + f(n - 2) +...+ f(1) + 1 = 2 * f(n - 1) = 2^(n - 1)
int frogJumpStep_circulation(int n){
    if(n <= 0){
        return 0;
    }
    if(n == 1){
        return 1;
    }

    int methods = 1;
    for(int i = 1; i < n; i++){
        methods *= 2;
    }
    return methods;
}
*/

int main(int argc, char * argv[]){
    printf("%d\n", frogJumpStep(5));
}
