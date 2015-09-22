/*************************************************************************
	> File Name: 2.8.c
	> Author: zhuxinquan
	> Mail: zhuxinquan61@gmail.com
	> Created Time: 2015年09月21日 星期一 17时11分23秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node * next;
}Node, * LinkList;

LinkList CreatLink(int * count)
{
    LinkList head, tail, s;
    int x;
    tail = head = (LinkList)malloc(sizeof(Node));
    scanf("%d", &x);
    while(x != -1)
    {
        s = (Node *)malloc(sizeof(Node));
        s->data = x;
        s->next = NULL;
        (*count)++;
        tail->next = s;
        tail = s;
        scanf("%d", &x);
    }
    return head;
}

void la_insert_lb(LinkList head_a, LinkList head_b, int i, int len, int j)
{
    int k;
    Node * pa, * pb, * prea, * preb, * pdel;
    prea = head_a;
    preb = head_b;
    pa = head_a->next;
    pb = head_b->next;
    for(k = 1; k < i; k++)
    {
        prea = prea->next;
    }
    for(k = 1; k < j + 1; k++)
    {
        preb = preb->next;
    }
    for(k = 0; k < len; k++)
    {
        pdel = prea->next;
        prea->next = pdel->next;
        pdel->next = preb->next;
        preb->next = pdel;
        preb = pdel;
    }

}

void print_link(LinkList head)
{
    Node * p = head->next;
    while(p)
    {
        printf("%4d", p->data);
        p = p->next;
    }
    printf("\n");
}

int main(void)
{
    int count_a, count_b, i, len, j;
    LinkList head_a, head_b;
    count_a = 0;
    count_b = 0;
    printf("input la and -1 is over:\n");
    head_a = CreatLink(&count_a);
    printf("input lb and -1 is over:\n");
    head_b = CreatLink(&count_b);
    printf("la:");
    print_link(head_a);
    printf("lb:");
    print_link(head_b);
    while(1)
    {
        printf("input i, len, j(eg: 3,4,2):");
        scanf("%d,%d,%d", &i, &len, &j);
        if( (i + len > count_b) || (j > count_b) || (i < 1) || (j < 0) )
        {
            printf("input error!\n");
            continue;
        }
        else{
            break;
        }
    }
    la_insert_lb(head_a, head_b, i, len, j);
    printf("la:");
    print_link(head_a);
    printf("lb:");
    print_link(head_b);
}
