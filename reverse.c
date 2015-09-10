/*************************************************************************
	> File Name: reverse.c
	> Author: zhuxinquan
	> Mail: zhuxinquan61@gmail.com
	> Created Time: 2015年09月10日 星期四 19时10分52秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *next;
}Node, * LinkList;

LinkList Creat_LinkList()
{
    int i, t;
    LinkList head, tail, p;
    head = tail = (LinkList)malloc(sizeof(Node));
    head->next = NULL;
    while(1)
    {
        printf("input No.%d(end -1)", i+1);
        scanf("%d", &t);
        if(t != -1)
        {
            p = (LinkList)malloc(sizeof(Node));
            p->data = t;
            p->next = NULL;
            tail->next = p;
            tail = p;
        }
        else{
            break;
        }
    }
    return head;
}

void reverse(LinkList head)
{
    LinkList p, q;
    p = head->next;
    head->next = NULL;
    while(p)
    {
        q = p;
        p = p->next;
        q->next = head->next;
        head->next = q;
    }
}

void print_link(LinkList head)
{
    LinkList p = head->next;  
    while(p){
        printf("%3d", p->data);
        p = p->next;
    }
    printf("\n");
}
int main(void)
{
    LinkList head;
    head = Creat_LinkList();
    printf("reverse before:");
    print_link(head);
    reverse(head);
    printf("reverse after:");
    print_link(head);
    return 0;
}
