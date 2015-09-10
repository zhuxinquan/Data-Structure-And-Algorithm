/*************************************************************************
	> File Name: 两个集合的差集.c
	> Author: zhuxinquan
	> Mail: zhuxinquan61@gmail.com
	> Created Time: 2015年09月10日 星期四 19时54分59秒
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

void different(LinkList head1, LinkList head2)
{
    LinkList pre = head1, p = head1->next, q, r;
    while(p != NULL)
    {
        q = head2->next;
        while(q != NULL && q->data != p->data){
            q = q->next;
        }
        if(q != NULL)
        {
            r = p;
            pre->next = p->next;
            p = p->next;
            free(r);
        }
        else{
            pre = p;
            p = p->next;
        }
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
    LinkList head1, head2;
    printf("input No.1 set:\n");
    head1 = Creat_LinkList();
    printf("input No.2 set:\n");
    head2 = Creat_LinkList();
    printf("set 1:\n");
    print_link(head1);
    different(head1, head2);
    printf("set 1:\n");
    print_link(head1);
    return 0;
}
