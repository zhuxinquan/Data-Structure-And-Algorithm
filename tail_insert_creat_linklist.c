/*************************************************************************
	> File Name: head_insert_creat_linklist.c
	> Author: zhuxinquan
	> Mail: zhuxinquan61@gmail.com
	> Created Time: 2015年09月09日 星期三 16时57分27秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

typedef int ElemType;

typedef struct node{
    ElemType    data;
    struct node *next;
}LNode, * LinkList;

LinkList Creat_LinkList1()
{
    LinkList H = (LinkList)malloc(sizeof(LNode));
    H->next = NULL;
    LNode * s, *r = H;
    int x;
    scanf("%d", &x);
    while(x != -1){
        s = (LinkList)malloc(sizeof(LNode));
        s->data = x;
        s->next = r->next;
        r->next = s;
        r = s;
        scanf("%d", &x);
    }
    return H;
}

void print_link(LinkList H)
{
    LNode * p;
    p = H->next;
    while(p != NULL)
    {
        printf("%4d", p->data);
        p = p->next;
    }
}

int main(void)
{
    LNode * H;
    H = Creat_LinkList1();
    print_link(H);
}
