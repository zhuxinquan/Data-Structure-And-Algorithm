/*************************************************************************
	> File Name: prime.c
	> Author: zhuxinquan
	> Mail: zhuxinquan61@gmail.com
	> Created Time: 2015年12月09日 星期三 14时48分58秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include"fstdin.h"

typedef char Vextype;

#define MAXVEX 20
#define INFINITY 32768

typedef struct{
    int arcs[MAXVEX][MAXVEX];
    Vextype vex[MAXVEX];
    int vexnum;
    int arcnum;
}AdjMatrix;

int getVexNo(AdjMatrix * G, char ch)
{
    int i;
    for(i = 1; i <= G->vexnum; i++){
        if(G->vex[i] == ch){
            return i;
        }
    }
    return -1;
}

void Create(AdjMatrix * G)
{
    int i, j, k, weight, vex1, vex2;
    //printf("please input undirection networks vexnum and arcnum:\n");
    printf("please input direction networks vexnum and arcnum:\n");
    scanf("%d %d", &G->vexnum, &G->arcnum);
    for(i = 1; i <= G->vexnum; i++){        //initAdjacencyMatrix
        for(j = 1; j <= G->vexnum; j++){
            G->arcs[i][j] = INFINITY;
        }
    }
    printf("input undirection networks %d vertex:\n", G->vexnum);
    for(i = 1; i <= G->vexnum; i++){
        printf("No.%d vertex:", i);
        //fstdin();
        scanf(" %c", &G->vex[i]);
    }
    printf("input undirection networks %d arcs:\n", G->arcnum);
    for(k = 0; k < G->arcnum; k++){
        char ch1, ch2;
        printf("\nNo.%d arc(eg:A B is A-->B):", k+1);
        //fstdin();           //wipe input cache
        scanf(" %c %c", &ch1, &ch2);
        vex1 = getVexNo(G, ch1);
        vex2 = getVexNo(G, ch2);
        if(vex1 == -1 || vex2 == -1){
            printf("input vertex error!\n");
            exit(1);
        }
        printf("\tinput %c<-->%c weight:", G->vex[vex1], G->vex[vex2]);
        //fstdin();
        scanf("%d", &weight);
        G->arcs[vex1][vex2] = weight;
        //G->arcs[vex2][vex1] = weight;         //if Graph is direction networks
    }
    printf("\nAdjMatrix:\n");
    printf("    ");
    for(i = 1; i <= G->vexnum; i++){
        printf("%4c", G->vex[i]);
    }
    printf("\n");
    for(i = 1; i <= G->vexnum; i++){
        printf("%4c", G->vex[i]);
        for(j = 1; j <= G->vexnum; j++){
            if(G->arcs[i][j] == INFINITY){
                printf("  --");
            }else{
                printf("%4d", G->arcs[i][j]);
            }
        }
        printf("\n");
    }
}

void prim(AdjMatrix * G, int start)
{
    struct{
        int adjvex;         //adjacency weight min vertex order
        int lowcost;        //min weight
    }closedge[MAXVEX];
    struct{
        Vextype vex1;
        Vextype vex2;
        int weight;
    }primeTree[MAXVEX];
    int i, e, k, m, min;
    closedge[start].lowcost = 0;
    for(i = 1; i <= G->vexnum; i++){        //initClosedge
        if(i != start){
            closedge[i].adjvex = start;
            closedge[i].lowcost = G->arcs[start][i];
        }
    }
    for(e = 1; e <= G->vexnum - 1; e++){
        min = INFINITY;                     //select min weight
        for(k = 1; k <= G->vexnum; k++){
            if(closedge[k].lowcost != 0 && closedge[k].lowcost < min){
                m = k;
                min = closedge[k].lowcost;
            }
        }
        primeTree[e].vex1 = G->vex[closedge[m].adjvex];
        primeTree[e].vex2 = G->vex[m];
        primeTree[e].weight = min;
        closedge[m].lowcost = 0;
        for(i = 1; i <= G->vexnum; i++){
            if(i != m && G->arcs[m][i] < closedge[i].lowcost)
            {
                closedge[i].lowcost = G->arcs[m][i];
                closedge[i].adjvex = m;
            }
        }
    }
    printf("primeTree:\n");
    for(i = 1; i <= G->vexnum - 1; i++){
        printf("%c---%c  %d\n", primeTree[i].vex1, primeTree[i].vex2, primeTree[i].weight);
    }
}

/*dist array record source to all vertex min distance
 * path array record source to all vextex min distance path through vertex
 */
void Dijkstra(AdjMatrix * G, int start, int dist[], int path[][MAXVEX]) 
{
    int mindist, i, j, k, t = 1;
    for(i = 1; i <= G->vexnum; i++){    //Init dist[]
        dist[i] = G->arcs[start][i];
        if(G->arcs[start][i] != INFINITY){
            path[i][1] = start;
        }
    }
    path[start][0] = 1;
    
    //find all min path
    for(i = 2; i <= G->vexnum; i++){        
        mindist = INFINITY;
        
        //select min weight path
        for(j = 1; j <= G->vexnum; j++){
            if(!path[j][0] && dist[j] < mindist)
            {
                k = j;
                mindist = dist[j];
            }
        }
        if(mindist == INFINITY){
            return ;
        }
        path[k][0] = 1;
        for(j = 1; j <= G->vexnum; j++){
            if(!path[j][0] && G->arcs[k][j] < INFINITY && dist[k] + G->arcs[k][j] < dist[j]){
                dist[j] = dist[k] + G->arcs[k][j];
                t = 1;
                while(path[k][t] != 0){
                    path[j][t] = path[k][t];
                    t++;
                }
                path[j][t] = k;
                path[j][t+1] = 0;
            }
        }
        
    }

}

int main(void)
{
    int start, end, i;
    int dist[MAXVEX], path[MAXVEX][MAXVEX] = {0};
    char ch;
    AdjMatrix * G;
    G = (AdjMatrix *)malloc(sizeof(AdjMatrix));
    Create(G);
    printf("Prime input start vertex:");
    scanf(" %c", &ch);
    start = getVexNo(G, ch);
    prim(G, start);
    printf("Dijkstra input start vertex:");
    scanf(" %c", &ch);
    start = getVexNo(G, ch);
    Dijkstra(G, start, dist, path);
    printf("\ninput end vertex:");
    scanf(" %c", &ch);
    end = getVexNo(G, ch);
    printf("%c--->%c path:", G->vex[start], G->vex[end]);
    i = 1;
    while(path[end][i]){
        printf("%3c", G->vex[path[end][i]]);
        i++;
    }
    printf("%3c\n", G->vex[end]);
}
