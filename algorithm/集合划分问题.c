/*************************************************************************
> File Name: 集合划分问题.c
> Author: zhuxinquan
> Mail: zhuxinquan61@xiyoulinux.org
> Created Time: 2016年05月24日 星期二 22时31分04秒
************************************************************************/

#include<stdio.h>
int  main()   
{   
    int f[20][20],n,m,i,t;  
    int j, k;

    printf("input n and m(split by space):");
    scanf("%d %d", &j, &k);

    for(i=1;i<=j;i++){
        for(m=1;m<=i;m++)  
        {
            if(m==1||i==m||i<=2)  
            f[i][m]=1;  
            else  
            f[i][m]=f[i-1][m-1]+m*f[i-1][m];  
        }
    }  
    printf("%d\n", f[j][k]);
    return 0;  
} 
