/*************************************************************************
	> File Name: prelink.c
	> Author: zhuxinquan
	> Mail: zhuxinquan61@gmail.com
	> Created Time: 2015年09月09日 星期三 21时11分51秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
}node;

void print_link(node * );

node * creat_link()
{
    node * h = (node *)malloc(sizeof(node));
    h->next = NULL;
    node * s, *r = h;
    int x;
    scanf("%d", &x);
    while(x != -1)
    {
        s = (node *)malloc(sizeof(node));
        s->data = x;
        s->next = r->next;
        r->next = s;
        r = s;
        scanf("%d", &x);
    }
    return h;
}

node * prelink(node * h1, node *h2)
{
    node * h, *t, *s, *p;
    h = (node *)malloc(sizeof(node));
    h->next = NULL;
    while(h1->next && h2->next)
    {
        if(h1->next->data < h2->next->data)
        {
            p = h1->next;
            h1->next = p->next;
        }
        else 
        {
            p = h2->next;
            h2->next = p->next;
        }
        p->next = NULL;
        if(!h->next)
        {
            h->next = t = p;
        }
        else 
        {
            if(t->data == p->data)
            {
                free(p);
            }
            else 
            {
                t->next = p;
                t = p;
            }
        }
    }
    if(h1->next){
        s = h1->next;
    }
    else{
        s = h2->next;
    }
    while(s)
    {
        p = s;
        s = s->next;
        p->next = NULL;
        if(t->data == p->data){
            free(p);
        }else{
            t->next = p;
        }
    }
    return h;
}

void print_link(node * h)
{
    node * p;
    p = h->next;
    while(p !=  NULL)
    {
        printf("%4d", p->data);
        p = p->next;
    }
}

int main(void)
{
    node * h1, *h2;
    printf("input link1(-1 end):\n");
    h1 = creat_link();
    printf("input link2(-1 end):\n");
    h2 = creat_link();
    h1 = prelink(h1, h2);
    printf("合并后为：\n");
    print_link(h1);
    printf("\n");
    return 0;
}
