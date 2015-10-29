/*************************************************************************
	> File Name: FastTransposeTSMatrix.c
	> Author: zhuxinquan
	> Mail: zhuxinquan61@gmail.com
	> Created Time: 2015年10月29日 星期四 17时25分53秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

typedef struct {
    int row, col;
    int value;
}Triple;        //定义三元组顺序表的结构

typedef struct{
    Triple data[10];
    int rows, cols, nums;
}TSMatrix;      //定义顺序表

void InitTSM(TSMatrix * tsm)
{
    int i;
    printf("please input rows and cols:");
    scanf("%d%d", &tsm->rows, &tsm->cols);
    printf("input nums:");
    scanf("%d", &tsm->nums);
    for(i = 1; i <= tsm->nums; i++){
        printf("input row、cols、value:");
        scanf("%d%d%d", &tsm->data[i].row, &tsm->data[i].col, &tsm->data[i].value);
    }
}

void  FastTransposeTSMatrix(TSMatrix * A, TSMatrix * B)
{
    int num[10], position[10];
    int col, t, q;
    B->rows = A->cols;
    B->cols = A->rows;
    B->nums = A->nums;
    if(B->nums)
    {
        for(col = 1; col <= A->cols; col++){        //初始化计数数组
            num[col] = 0;
        }
        for(t = 1; t <= A->nums; t++){               //取得每列元素的个数
            num[A->data[t].col]++;
        }
        position[1] = 1;                            //初始化，将三元组顺序最顶端标记为1开始
        for(col = 2; col <= A->cols; col++){
            position[col] = position[col-1] + num[col - 1];     //统计每列的个数，结果为转置后每行的个数
        }
        for(t = 1; t <= A->nums; t++){
            col = A->data[t].col;
            q = position[col];
            B->data[q].row = A->data[t].col;
            B->data[q].col = A->data[t].row;
            B->data[q].value = A->data[t].value;
            position[col]++;
        }
    }
}

void printfTSM(TSMatrix A)
{
    int i;
    for(i = 1; i <= A.nums; i++){
        printf("row:%d, col:%d, value:%d.\n", A.data[i].row, A.data[i].col, A.data[i].value);
    }
}

int main(void)
{
    TSMatrix tsm, tsm1;
    InitTSM(&tsm);
    printf("转置前：\n");
    printfTSM(tsm);
    FastTransposeTSMatrix(&tsm, &tsm1);
    printf("转置后:\n");
    printfTSM(tsm1);
}
