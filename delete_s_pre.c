/*************************************************************************
	> File Name: delete_s_pre.c
	> Author: zhuxinquan
	> Mail: zhuxinquan61@gmail.com
	> Created Time: 2015年09月20日 星期日 19时58分00秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *next;
}Node, * LinkList;

LinkList Creat_LinkList()
{
    int i = 0, t;
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
    tail->next = head->next;        //构成循环链表
    return head;
}

void del_pre(Node * s)
{
    Node * del;
    Node * t = s;
    while(1)
    {
        if(t->next->next != s){
            t = t->next;
        }else{
            del = t->next;
            t->next = del->next;
            free(del);
            break;
        }
    }
}

void print_list(Node * s)
{
    Node * t = s;
    
    while(1)
    {
        printf("%3d", t->data);
        if(t->next == s){
            break;
        }else{
            t = t->next;
        }
    }
    printf("\n");
}

int main(void)
{
    LinkList head;
    Node * s;
    int t, flag = 1;
    head = Creat_LinkList();
    printf("创建的链表为:\n");
    print_list(head->next);
    printf("请输入要删除哪个节点的前驱节点：");
    scanf("%d", &t);
    if(head->next->data == t){
        s = head->next;
    }
    else{
        s = head ->next->next;
        while(1){
            if(s == head->next)
            {
                printf("节点未找到\n");
                exit(1);
            }
            else if(s->data == t)
            {
                break;
            }
            else
            {
                s = s->next;
            }
        }
    }
    del_pre(s);
    print_list(s);
    return 0;
}



