/*************************************************************************
	> File Name: JosephusOperate.c
	> Author: zhuxinquan
	> Mail: zhuxinquan61@gmail.com
	> Created Time: 2015年09月10日 星期四 21时31分46秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

#define MAX 100

typedef struct NodeType
{
    int id;
    int password;
    struct NodeType *next;
}NodeType;

void CreatList(NodeType **, int);
NodeType * GetNode(int, int);
void Print_List(NodeType *);
int IsEmptyList(NodeType *);
void JosephusOperate(NodeType **, int);

int main(void)
{
    int n = 0, m = 0;
    NodeType *phead = NULL;
    do{
        if(n > MAX)
        {
            printf("人数过多，请重新输入！");
        }
        printf("请输入人数n(最多%d个)", MAX);
        scanf("%d", &n);
    }while(n > MAX);
    printf("请输入初始密码m：");
    scanf("%d", &m);
    CreatList(&phead, n);
    Print_List(phead);
    JosephusOperate(&phead, m);
    return 0;
}

void CreatList(NodeType **phead, int n)
{
    int i = 0;
    int ipassword = 0;
    NodeType *pnew = NULL;
    NodeType *pcur = NULL;
    for(i = 1; i <= n; i++)
    {
        printf("请输入第%d个人的密码：", i);
        scanf("%d", &ipassword);
        pnew = GetNode(i, ipassword);
        if(*phead == NULL)
        {
            *phead = pcur = pnew;
            pcur->next = *phead;
        }
        else{
            pnew->next = pcur->next;
            pcur->next = pnew;
            pcur = pnew;
        }
    }
    printf("单向链表创建完成！\n");
}

NodeType *GetNode(int id, int ipassword)
{
    NodeType *pnew = NULL;
    pnew = (NodeType *)malloc(sizeof(NodeType));
    if(!pnew)
    {
        printf("malloc error!\n");
        exit(-1);
    }
    pnew->id = id;
    pnew->password = ipassword;
    pnew->next = NULL;
    return pnew;
}

void Print_List(NodeType *phead)
{
    NodeType *pcur = phead;
    if(!IsEmptyList(phead))
    {
        printf("id      password\n");
        do{
            printf("%3d, %7d\n", pcur->id, pcur->password);
            pcur = pcur->next;
        }while(pcur != phead);
    }
}

int IsEmptyList(NodeType *phead)
{
    if(!phead)
    {
        printf("the list is empty!\n");
        return 1;
    }
    return 0;
}

void JosephusOperate(NodeType **phead, int ipassword)
{
    int icount = 0;
    int iflag = 1;
    NodeType * prv = NULL;
    NodeType * pcur = NULL;
    NodeType * pdel = NULL;
    prv = pcur = *phead;
    while(prv->next != *phead)
    {
        prv = prv->next;
    }
    while(iflag)
    {
        for(icount = 1; icount < ipassword; icount++)
        {
            prv = pcur;
            pcur = pcur->next;
        }
        if(prv == pcur)
        {
            iflag = 0;
        }
        pdel = pcur;
        prv->next = pcur->next;
        pcur = pcur->next;
        ipassword = pdel->password;
        printf("第%d个人出列（密码：%d）\n", pdel->id, pdel->password);
        free(pdel);
    }
    *phead = NULL;
    getchar();
}	
