/*************************************************************************
	> File Name: graph.c
	> Author: zhuxinquan
	> Mail: zhuxinquan61@gmail.com
	> Created Time: 2015年12月06日 星期日 04时56分51秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

#define MAXVEX 20

typedef struct ArcNode{
    int adjvex;         //邻接点域
    int weight;
    struct ArcNode * next;
}ArcNode;

typedef struct VertexNode{
    char vexdata;       //vertex_data
    ArcNode * head;     //vertex_adjacency
}VertexNode;

typedef struct{
    VertexNode vertex[MAXVEX];
    int vexnum;         //vertex_num
    int arcnum;         //arc_num
}AdjList;

void CreatGraph(AdjList * adjacency_list)
{
    printf("input vertex_num and ");
}

int main(void)
{
    AdjList * adjacency_list;
    adjacency_list = (AdjList *)malloc(sizeof(AdjList));
    CreatGraph(adjacency_list);
}
