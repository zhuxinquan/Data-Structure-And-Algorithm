/*************************************************************************
> File Name: 矩阵连乘.c
> Author: zhuxinquan
> Mail: zhuxinquan61@xiyoulinux.org
> Created Time: 2016年04月27日 星期三 19时41分02秒
************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAXSIZE  100

//矩阵a和矩阵b相乘结果存入矩阵c
void matrixMultiply(int ** a, int ** b, int ** c, int ra, int ca, int rb, int cb){
    if(ca != rb) {
        printf("矩阵不满足相乘条件");
        exit(1);
    }

    //i为a矩阵的行, j为b矩阵的列, k控制a矩阵的列
    int i, j, k;
    for(i = 0; i < ra; i++){
        for(j = 0; j < cb; j++){
            int sum = a[i][0] * b[0][j];
            for(k = 0; k < ca; k++){
                sum += a[i][k] * b[k][j];
            }
            c[i][j] = sum;
        }
    }
}

//二维数组m[i][j]代表从第i个矩阵到第j个矩阵连乘计算的次数
//s[i][j]代表从第i个矩阵到第j个矩阵之间分割的位置
//一维数组p代表当前所有矩阵的行,p[n]最后一个代表列
void MatriChain(int  p[MAXSIZE], int n, int  m[MAXSIZE][MAXSIZE], int s[MAXSIZE][MAXSIZE]){
    int i, j, r, k, t;

    //初始化单一矩阵相乘计算次数为0
    for(i = 1; i <= n; i++){
        m[i][i] = 0;
    }

    //n代表n个矩阵相乘,当有r个矩阵相乘时，所有的情况
    for(r = 2; r <= n; r++){
        //递推式的起始位置  
        for(i = 1; i <= n - r + 1; i++){ 
            //递推式的终止位置
            j = i + r - 1;   
            //当从第一处分割时进行初始化
            m[i][j] = m[i + 1][j] + p[i - 1] * p[i] * p[j];    
            s[i][j] = i;
            //递推求得每一种分割的结果，若某种分割结果求得计算次数少于当前值则更新
            for(k = i + 1; k < j; k++){
                int t = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if(t < m[i][j]){
                    //更新最少计算次数和分割的位置
                    m[i][j] = t;
                    s[i][j] = k;
                }
            }
        }   
    }
}


int main(int argc, char * argv[]){
    int n, i, j;
    int m[MAXSIZE][MAXSIZE] = {0};
    int s[MAXSIZE][MAXSIZE] = {0};
    //memset(m, 0, sizeof(m));
    //memset(s, 0, sizeof(s));
    int p[MAXSIZE] = {30, 35, 15, 5, 10, 20, 25};

    n = 6;

    MatriChain(p, n, m, s);
    printf("\nm[i][j]:\n\n");
    printf("        +%7d%7d%7d%7d%7d%7d\n", 1, 2, 3, 4, 5, 6);
    printf("   ++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
    for(i = 1; i <= n; i++){
        printf("%7d +", i);
        for(j = 1; j <= n; j++){
            printf("%7d", m[i][j]);
        }
        printf("\n");
    }

    printf("\ns[j][j]:\n\n");
    printf("    +    1   2   3   4   5   6\n");
    printf("  ++++++++++++++++++++++++++++\n");
    for(i = 1; i <= n; i++){
        printf("%3d + ", i);
        for(j = 1; j <= n; j++){
            printf("%4d", s[i][j]);
        }
        printf("\n");
    }
    return 0;
}
