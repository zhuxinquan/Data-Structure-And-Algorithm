/*************************************************************************
	> File Name: graph.c
	> Author: zhuxinquan
	> Mail: zhuxinquan61@gmail.com
	> Createed Time: 2015年12月06日 星期日 04时56分51秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

#define MAXVEX 20

typedef struct QNode{
    int data;
    struct QNode * next;
}QNode;

typedef struct Queue{
    struct QNode * front;
    struct QNode * rear;
}LQueue;

void InitQueue(LQueue * LQ)
{
    LQ = (LQueue *)malloc(sizeof(LQueue));
    QNode * p = (QNode *)malloc(sizeof(QNode));
    p->next = NULL;
    LQ->front = p;
    LQ->rear = p;
}

void EnterQueue(LQueue * LQ, int v0)
{
    QNode * t = (QNode *)malloc(sizeof(QNode));
    t->data = v0;
    t->next = NULL;
    LQ->rear->next = t;
    LQ->rear = t;
}

int Empty(LQueue * LQ)
{
    if(LQ->front == LQ->rear){
        return 1;
    }else{
        return 0;
    }
}

void DeleteQueue(LQueue * LQ, int * v)
{
    QNode * t;
    if(Empty(LQ)){
        printf("LQueue empty!\n");
        exit(0);
    }
    *v = LQ->front->next->data;
    t = LQ->front->next;
    LQ->front->next = LQ->front->next->next;
    if(LQ->front->next == NULL){
        LQ->rear = LQ->front;
    }
    free(t);
}

typedef struct ArcNode{
    int adjvex;         //adjacency vertex
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

void CreateGraph(AdjList * adjacency_list)
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
                printf("input %c adjacency vertex(vertex 0 is over):", adjacency_list->vertex[i].vexdata);
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
            if(t == 'y' || t == 'Y'){
                printf("->%d, %d", p->adjvex, p->weight);
            }else{
                printf("->%d", p->adjvex);
            }
            p = p->next;
        }
        printf("\n");
    }
}

int FirstAdjVex(AdjList * adjacency_list, int v0)
{
    return adjacency_list->vertex[v0].head->next?adjacency_list->vertex[v0].head->next->adjvex:-1;
}

int NextAdjVex(AdjList * adjacency_list, int v0, int v)
{
    ArcNode * temp;
    temp = adjacency_list->vertex[v0].head->next;
    while(temp){
        if(temp->adjvex == v && temp->next != NULL){
            return temp->next->adjvex;
        }else{
            temp = temp->next;
        }
    }
    return -1;
}

void DFS(AdjList * adjacency_list, int v0)
{
    int first_adj_vex;
    printf("%c", adjacency_list->vertex[v0].vexdata);
    visited[v0] = 1;
    first_adj_vex = FirstAdjVex(adjacency_list, v0);
    while(first_adj_vex != -1){
        if(!visited[first_adj_vex]){
            DFS(adjacency_list, first_adj_vex);
        }
        first_adj_vex = NextAdjVex(adjacency_list, v0, first_adj_vex);
    }
}

void BFS(AdjList * adjacency_list, int v0)
{
    LQueue * Q;
    int v, w;
    printf("%c", adjacency_list->vertex[v0].vexdata);
    visited[v0] = 1;
    InitQueue(Q);
    EnterQueue(Q, v0);
    while(!Empty(Q)){
        DeleteQueue(Q, &v);
        w = FirstAdjVex(adjacency_list, v);
        while(w != -1){
            if(!visited[w]){
                printf("%c", adjacency_list->vertex[w].vexdata);
                visited[w] = 1;
                EnterQueue(Q, w);
            }
            w = NextAdjVex(adjacency_list, v, w);
        }
    }
}

void TraverseGraph(AdjList * adjacency_list)
{
    int i;
    for(i = 1; i <= adjacency_list->vexnum; i++){
        visited[i] = 0;
    }
    printf("DFS:\n");
    for(i = 1; i < adjacency_list->vexnum; i++){
        if(!visited[i]){
            DFS(adjacency_list, i);
        }
    }
    printf("\n");
    /*for(i = 1; i <= adjacency_list->vexnum; i++){
        visited[i] = 0;
    }
    printf("BFS:\n");
    for(i = 1; i <= adjacency_list->vexnum; i++){
        if(!visited[i]){
            BFS(adjacency_list, i);
        }
    }
    printf("\n");*/
}

int main(void)
{
    AdjList * adjacency_list;
    adjacency_list = (AdjList *)malloc(sizeof(AdjList));
    CreateGraph(adjacency_list);
    TraverseGraph(adjacency_list);
    return 0;
}
