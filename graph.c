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

int visited[MAXVEX] = {0};

void CreatGraph(AdjList * adjacency_list)
{
    int i, adjvex, weight;
    char t;
    ArcNode * pArcNode, * tail;
    printf("input vertex_num and arc_num :");
    scanf("%d %d", &adjacency_list->vexnum, &adjacency_list->arcnum);
    for(i = 1; i <= adjacency_list->vexnum; i++){
        int c;
        do{
            c = fgetc(stdin);
        }while (c != '\n' && c != EOF);
        printf("input No.%d vertex_data:", i);
        scanf("%c", &adjacency_list->vertex[i].vexdata);
        adjacency_list->vertex[i].head = (ArcNode *)malloc(sizeof(ArcNode));
        adjacency_list->vertex[i].head->next = NULL;
    }
    printf("The arc have weight(y/n)?");
    int c;
    do{
        c = fgetc(stdin);
    }while (c != '\n' && c != EOF);
    scanf("%c", &t);
    if(t == 'y' || t == 'Y'){     //have arc weight
        for(i = 1; i <= adjacency_list->vexnum; i++){
            tail = adjacency_list->vertex[i].head;
            while(1){
                printf("input %c adjacency vertex and weight(vertex 0 is over)", adjacency_list->vertex[i].vexdata);
                int c;
                do{
                    c = fgetc(stdin);
                }while(c != '\n' && c != EOF);
                scanf("%d %d", &adjvex, &weight);
                if(adjvex != 0){
                    pArcNode = (ArcNode *)malloc(sizeof(ArcNode));
                    pArcNode->adjvex = adjvex;
                    pArcNode->weight = weight;
                    pArcNode->next = NULL;
                    tail->next = pArcNode;
                    tail = pArcNode;
                }else{
                    break;
                }
            }
        }
    }else{          //without arc weight
        for(i = 1; i <= adjacency_list->vexnum; i++){
            tail = adjacency_list->vertex[i].head;
            while(1){
                printf("input %c adjacency vertex and weight(vertex 0 is over)", adjacency_list->vertex[i].vexdata);
                int c;
                do{
                    c = fgetc(stdin);
                }while(c != '\n' && c != EOF);
                scanf("%d", &adjvex);
                if(adjvex != 0){
                    pArcNode = (ArcNode *)malloc(sizeof(ArcNode));
                    pArcNode->adjvex = adjvex;
                    pArcNode->weight = 0;
                    pArcNode->next = NULL;
                    tail->next = pArcNode;
                    tail = pArcNode;
                }else{
                    break;
                }
            }
        }
    }
    
    printf("adjacency list :\n");
    for(i = 1; i <= adjacency_list->vexnum; i++){
        ArcNode * p = adjacency_list->vertex[i].head->next;
        printf("No.%d %c", i, adjacency_list->vertex[i].vexdata);
        while(p){
            if(t == 'y'){
                printf("->%d, %d", p->adjvex, p->weight);
            }else{
                printf("->%d", p->adjvex);
            }
            p = p->next;
        }
        printf("\n");
    }
}

void DFS(AdjList * adjacency_list, int v0)
{

}

void TraverseGraph(AdjList * adjacency_list)
{
    int i;
    for(i = 1; i <= adjacency_list->vexnum; i++){
        visited[i] = 0;
    }
    for(i = 1; i < adjacency_list->vexnum; i++){
        if(!visited[i]){
            DFS(adjacency_list, i);
        }
    }
}

int main(void)
{
    AdjList * adjacency_list;
    adjacency_list = (AdjList *)malloc(sizeof(AdjList));
    CreatGraph(adjacency_list);
    TraverseGraph(adjacency_list);
}
