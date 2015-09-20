/*************************************************************************
	> File Name: inverse_list.c
	> Author: zhuxinquan
	> Mail: zhuxinquan61@gmail.com
	> Created Time: 2015年09月18日 星期五 19时51分45秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node * next;
}LNode, *LinkList;

LinkList Creat_LinkList()   //链表创建函数,头插法
{
    LinkList tail, head;
    tail = head = (LinkList)malloc(sizeof(LNode));
    head->next = NULL;
    LNode * s;
    int x;
    printf("please input x and x=-1 end:\n");
    scanf("%d", &x);
    while(x != -1)
    {
        s = (LinkList)malloc(sizeof(LNode));
        s->data = x;
        s->next = NULL;
        tail->next = s;
        tail = s;
        scanf("%d", &x);
    }
    return head;
}

void inverse_list(LinkList head)    //链表逆置函数
{
    LNode *p, *t;
    p = head->next;
    head->next = NULL;
    while(p != NULL){
        t = p;
        p = p->next;
        t->next = head->next;
        head->next = t;
    }
}

void print_link(LinkList head)
{
    LinkList p = head->next;
    while(p)
    {
        printf("%3d", p->data);
        p = p->next;
    }
    printf("\n");
}

void destory(LinkList head)     //链表销毁
{
    LinkList del, p = head->next;
    while(p->next)
    {
        del = p;
        head->next = del->next;
        free(del);
        p = head->next;;
    }
    free(p);                    //释放最后一个节点
    free(head);                 //释放头结点
}

int main(void)
{
    LinkList head;
    head = Creat_LinkList();
    print_link(head);
    inverse_list(head);
    print_link(head);
    destory(head);
    return 0;
}
