/*************************************************************************
	> File Name: sequence_reverse.c
	> Author: zhuxinquan
	> Mail: zhuxinquan61@gmail.com
	> Created Time: 2015年09月20日 星期日 17时42分27秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

#define N 20

struct seqlist{
    int data[N];
    int length;
};

typedef struct seqlist * Sequence;

void CreatSequence(Sequence L)
{
    int x, i = 0;
    printf("please input and enter -1 end：\n");
    scanf("%d", &x);
    while(x != -1)
    {
        L->data[i++] = x;
        scanf("%d", &x);
    }
    L->length = i;
}

void reverse(Sequence  L)
{
    int i, temp;
    int middle = (L->length + 1)/2;
    for(i = 0; i < middle; i++)
    {
        temp = L->data[i];
        L->data[i] = L->data[L->length - i -1];
        L->data[L->length -i -1] = temp;
    }
}

void PrintSequence(Sequence  L)
{
    int i;
    for(i = 0; i < L->length; i++)
    {
        printf("%3d", L->data[i]);
    }
    printf("\n");
}

int main(void)
{
    Sequence L;
    L = (Sequence)malloc(sizeof(struct seqlist));
    CreatSequence(L);
    PrintSequence(L);
    reverse(L);
    PrintSequence(L);
}
