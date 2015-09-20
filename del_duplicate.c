/*************************************************************************
	> File Name: del_duplicate.c
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
        printf("input No.%d(end -1)", (i++) + 1);
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

void del_duplicate(LinkList head)
{
    LinkList p = head->next, q, r;
    if(p != NULL)
    {
        while(p->next)
        {
            q = p;
            while(q->next)
            {
                if(q->next->data == p->data)
                {
                    r = q->next;
                    q->next = r->next;
                    free(r);
                }
                else{
                    q = q->next;
                }
            }
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
    LinkList head;
    head = Creat_LinkList();
    printf("before delete:");
    print_link(head);
    del_duplicate(head);
    printf("after delete:");
    print_link(head);
    return 0;
}
