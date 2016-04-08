/*************************************************************************
	> File Name: 矩阵乘法.c
	> Author: zhuxinquan
	> Mail: zhuxinquan61@xiyoulinux.org
	> Created Time: 2016年04月08日 星期五 23时22分52秒
 ************************************************************************/

#include<stdio.h>

void Mul(int a[][3], int b[][2], int c[][2], int m, int s, int n){
    int i, j, k;
    for(i = 0; i < m; i++) {
        for(j = 0; j < s; j++) {
            c[i][j] = 0;
            for(k = 0; k < n; k++) {
                c[i][j] += a[i][k]*b[k][j];
            }
        }
    }
}

int main(int argv, char* argc[])
{
    int a[2][3] = {1, 2, 3, 4, 5, 6};
    int b[3][2] = {2, 3, 4, 5, 6, 7};
    int c[2][2];
    int i, j;

    Mul(a, b, c, 2, 2, 3);

    for(i = 0; i < 2; i ++){
        for(j = 0; j < 2; j++){
            printf("%d  ", c[i][j]);
        }
        printf("\n\n");
    }
}
