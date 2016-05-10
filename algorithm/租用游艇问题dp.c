/*************************************************************************
	> File Name: 租用游艇问题dp.c
	> Author: zhuxinquan
	> Mail: zhuxinquan61@xiyoulinux.org
	> Created Time: 2016年05月04日 星期三 21时21分00秒
 ************************************************************************/

#include<stdio.h>
#include<string.h>
#include<limits.h>
#include<math.h>

#define MAX 100
#define INTMAX 0xF

int num;
int rent[MAX + 1][MAX + 1];
int minRent[MAX + 1][MAX + 1];
int s[MAX + 1][MAX + 1];

void findMinRent(int num){
    int i, j, k, r;

    //定义站点计算相邻的个数
    for(r = 2; r <= num; r++){
        //定义起始站点
        for(i = 1; i <= num - r + 1; i++){
            j = i + r - 1;
            minRent[i][j] = rent[i][j];
            s[i][j] = -1;
            for(k = i + 1; k < j; k++){
                int tem = minRent[i][k] + minRent[k][j];
                if(tem < minRent[i][j]){
                    minRent[i][j] = tem;
                    s[i][j] = k;
                }
            }
        }
    }
}

int main(void){
    int i, j, start, end;
    printf("input station number :");
    scanf("%d", &num);
    memset(rent, -1, sizeof(rent));
    memset(minRent, INTMAX, sizeof(minRent));
    for(i = 1; i < num; i++){
        for(j = i + 1; j <= num; j++){
            printf("input station[%d][%d] rent:", i, j);
            scanf("%d", &rent[i][j]);
            //minRent[i][j] = rent[i][j];
        }
    }

    for(i = 0; i <= MAX + 1; i++){
        rent[i][i] = 0;
    }
    findMinRent(num);
    printf("input start and end(split by space):");
    scanf("%d %d", &start, &end);
    printf("station %d--%d minRent is: %d\n", start, end, minRent[start][end]);
}
