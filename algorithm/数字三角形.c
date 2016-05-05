/*************************************************************************
	> File Name: 数字三角形.c
	> Author: zhuxinquan
	> Mail: zhuxinquan61@xiyoulinux.org
	> Created Time: 2016年05月04日 星期三 16时36分31秒
 ************************************************************************/

#include<stdio.h>
#include<string.h>

#define MAXNUM  100

//数字三角形元素
int line;
int m[MAXNUM + 1][MAXNUM + 1];
int max[MAXNUM + 1][MAXNUM + 1];
int lr[MAXNUM + 1];

int MaxSum(int i, int j){
    if(i == line){
        return m[i][j];
    }
    if(max[i + 1][j] == -1){
        max[i + 1][j] = MaxSum(i + 1, j);
    }
    if(max[i + 1][j + 1] == -1){
        max[i + 1][j + 1] = MaxSum(i + 1, j + 1);
    }
    if(max[i + 1][j] > max[i + 1][j + 1]){
        lr[i + 1] = 0;
        return max[i + 1][j] + m[i][j];
    }else{
        lr[i + 1] = 1;
        return max[i + 1][j + 1] + m[i][j];
    }
}

int main(void){
    int i, j, l;
    printf("input line:");
    scanf("%d", &line);
    for(i = 1; i <= line; i++){
        for(j = 1; j <= i; j++){
            scanf("%d", &m[i][j]);
        }
    }
    memset(max, -1, sizeof(max));
    printf("max:%d\n", MaxSum(1, 1));
    printf("%d\n", m[1][1]);
    for(i = 2, j = 1; i <= line; i++){
        if(lr[i] == 0){
            printf("%d\n", m[i][j]);
        }else{
            printf("%d\n", m[i][j + 1]);
            j++;
        }
    }
}
