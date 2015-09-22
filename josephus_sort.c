/*************************************************************************
	> File Name: josephus_sort.c
	> Author: zhuxinquan
	> Mail: zhuxinquan61@gmail.com
	> Created Time: 2015年09月21日 星期一 23时31分40秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node * next;
}Node, * LinkList;

LinkList Creat_Link(int n)
{
    int i = 1;
    LinkList head;
    Node * p, *t;
    t = head = (LinkList)malloc(sizeof(Node));
    while(i <= n)
    {
        p = (Node *)malloc(sizeof(Node));
        p->data = i++;
        p->next = NULL;
        t->next = p;
        t = p;
    }
    t->next = head->next;
    return t;
}

void josephus(LinkList tail, int m)
{
    int i;
    Node * pdel;
    Node * pcur = tail->next;
    Node * pre = tail;
    while(pcur != pcur->next)
    {
        for(i = 1; i < m; i++)
        {
            pre = pre->next;
        }
        pdel = pre->next;
        pcur = pdel->next;
        pre->next = pcur;
        printf("%3d", pdel->data);
        free(pdel);
    }
    printf("%3d", pcur->data);
    free(pcur);
    printf("\n");
}

int main(void)
{
    int n, m;
    LinkList tail;
    printf("input n, m(eg: 7,3):");
    scanf("%d,%d", &n, &m);
    tail = Creat_Link(n);
    josephus(tail, m);
    return 0;
}
