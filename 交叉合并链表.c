/*************************************************************************
	> File Name: 交叉合并链表.c
	> Author: zhuxinquan
	> Mail: zhuxinquan61@gmail.com
	> Created Time: 2015年09月21日 星期一 21时18分06秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

typedef int ElemType;

typedef struct node{
    ElemType data;
    struct node * next;
}Node, * LinkList;

LinkList Creat_LinkList()
{
    LinkList head = (LinkList)malloc(sizeof(Node));
    head->next = NULL;
    Node * s, * r = head;           //r为尾指针
    int x;
    printf("input and -1 is over:\n");
    scanf("%d", &x);
    while(x != -1){
        s = (LinkList)malloc(sizeof(Node));
        s->data = x;
        s->next = NULL;
        r->next = s;
        r = s;
        scanf("%d", &x);
    }
    return head;
}

LinkList merge_list(LinkList la, LinkList lb)
{
    Node * pa, * pb, * t, * s, * merge;
    t = merge = (LinkList)malloc(sizeof(Node));
    t->next = NULL;     //t为尾指针
    pa = la->next;
    pb = lb->next;
    while(pa && pb)
    {
        s = (Node *)malloc(sizeof(Node));
        s->data = pa->data;
        s->next = NULL;
        t->next = s;
        t = s;
        pa = pa->next;
        s = (Node *)malloc(sizeof(Node));
        s->data = pb->data;
        s->next = NULL;
        t->next = s;
        t = s;
        pb = pb->next;
    }
    while(pa)
    {
        s = (Node *)malloc(sizeof(Node));
        s->data = pa->data;
        s->next = NULL;
        t->next = s;
        t = s;
        pa = pa->next;
    }
    while(pb)
    {
        s = (Node *)malloc(sizeof(Node));
        s->data = pb->data;
        s->next = NULL;
        t->next = s;
        t = s;
        pb = pb->next;
    }
    return merge;
}

void print_link(LinkList head)
{
    Node * p = head->next;
    while(p)
    {
        printf("%3d", p->data);
        p = p->next;
    }
    printf("\n");
}

int main(void)
{
    LinkList la, lb, merge;
    la = Creat_LinkList();
    lb = Creat_LinkList();
    printf("la:");
    print_link(la);
    printf("lb:");
    print_link(lb);
    merge = merge_list(la, lb);
    printf("merge:");
    print_link(merge);
    return 0;
}
