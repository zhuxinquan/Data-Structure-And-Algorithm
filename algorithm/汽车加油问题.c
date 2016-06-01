/*************************************************************************
> File Name: 汽车加油问题.c
> Author: zhuxinquan
> Mail: zhuxinquan61@xiyoulinux.org
> Created Time: 2016年06月01日 星期三 17时43分46秒
************************************************************************/

#include<stdio.h>
void greedy(int d[],int n,int k) {     
    int num = 0;     
    for(int i = 0;i <= k;i++) {     
        if(d[i] > n) {     
            printf("no solution\n");     
            return;     
        }     
    }     
    for(int i = 0,s = 0;i <= k;i++) {     
        s += d[i];     
        if(s > n) {     
            num++;     
            s = d[i];     
        }     
    }     
    printf("%d\n",num);     
}     


int main() {     
    int i,n,k;     
    int d[1000];     
    scanf("%d %d",&n,&k);     
    for(i = 0;i <= k;i++)     
    scanf("%d",&d[i]);     
    greedy(d,n,k);     
} 
