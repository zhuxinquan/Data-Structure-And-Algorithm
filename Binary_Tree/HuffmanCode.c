/*************************************************************************
	> File Name: HuffmanCode.c
	> Author: zhuxinquan
	> Mail: zhuxinquan61@gmail.com
	> Created Time: 2015年11月23日 星期一 09时32分11秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define N 30
#define M 2*N-1

typedef struct{
    int Weight;
    int Parent, Lchild, Rchild;
}HTNode, HuffmanTree[M + 1];

typedef char*  HuffmanCode[N];

void Select(HuffmanTree, int, int *, int *);

void CreateHuffmanTree(HuffmanTree ht, int* w, int n){
    int m, i;
    m = 2*n - 1;
    for(i = 1; i <= n; i++){
        ht[i].Weight = w[i];
        ht[i].Parent = 0;
        ht[i].Lchild = 0;
        ht[i].Rchild = 0;
    }
    for(i = n + 1; i <= m; i++){
        ht[i].Weight = 0;
        ht[i].Parent = 0;
        ht[i].Lchild = 0;
        ht[i].Rchild = 0;
    }
    for(i = n + 1; i <= m; i++){
        int s1, s2;
        Select(ht, i-1, &s1, &s2);
        ht[i].Weight = ht[s1].Weight+ht[s2].Weight;
        ht[i].Lchild = s1;
        ht[i].Rchild = s2;
        ht[s1].Parent = i;
        ht[s2].Parent = i;
    }
    for(i = 1; i <= m; i++){
        printf("No.%d: Weight:%d  Parent:%d  Lchild:%d  Rchild%d\n", i, ht[i].Weight, ht[i].Parent, ht[i].Lchild, ht[i].Rchild);
    }
}

void Select(HuffmanTree ht, int n, int * s1, int * s2)
{
    int i, min, smin;
    for(i = 1; i <= n; i++){
        if(ht[i].Parent == 0)
        {
            min = ht[i].Weight;
            *s1 = i;
            break;
        }
    }
    for(i = 1; i <= n; i++){
        if(min > ht[i].Weight && ht[i].Parent == 0){
            min = ht[i].Weight;
            *s1 = i;
        }
    }
    for(i = 1; i <= n; i++){
        if(ht[i].Parent == 0 && i != *s1){
            smin = ht[i].Weight;
            *s2 = i;
            break;
        }
    }
    for(i = 1; i <= n; i++){
        if(ht[i].Parent == 0 && i != *s1){
            if(smin > ht[i].Weight){
                smin = ht[i].Weight;
                *s2 = i;
            }
        }
    }
    //printf("min:%d %d, smin%d %d\n", min, *s1,  smin, *s2);
    //exit(0);
}

void CreateHuffmanCode(HuffmanTree ht, HuffmanCode hc, int n){
    char * cd;
    int start, i, c, p;
    cd = (char *)malloc(n * sizeof(char));
    cd [n - 1] = '\0';
    for(i = 1; i <= n; i++){
        start = n - 1;
        c = i;
        p = ht[i].Parent;
        while(p != 0){
            --start;
            if(ht[p].Lchild == c){
                cd[start] = '0';
            }else{
                cd[start] = '1';
            }
            c = p;
            p = ht[p].Parent;
        }
        hc[i] = (char *)malloc((n - start)*sizeof(char));
        strcpy(hc[i], &cd[start]);
    }
    free(cd);
    for(i = 1; i <= n; i++){
        printf("%d: %s\n", ht[i].Weight, hc[i]);
    }
}

int main(void)
{
    int w[N];
    int i, n;
    char code[N];
    HuffmanTree ht;
    HuffmanCode hc;
    printf("input weight(end 0):");
    for(i = 1; i < N; i++){
        scanf("%d", w+i);
        if(w[i] == 0){
            n = --i;
            break;
        }
    }
    CreateHuffmanTree(ht, w, n);
    CreateHuffmanCode(ht, hc, n);
    printf("input code:");
    scanf("%s", code);
    for(i = 0; i <= n; i++){
        if(!strcmp(code, hc[i]))
        {
            printf("transcode: %d\n", ht[i].Weight);
            break;
        }
    }
    return 0;
}