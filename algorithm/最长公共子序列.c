/*************************************************************************
	> File Name: 最长公共子序列.c
	> Author: zhuxinquan
	> Mail: zhuxinquan61@xiyoulinux.org
	> Created Time: 2016年06月13日 星期一 22时15分25秒
 ************************************************************************/

#include<stdio.h>
#include<string.h>


//m, n代表两个序列的长度，x, y为两个序列, 二维数组c存储子序列的长度
//二维数组b存储是子序列长度是由哪一个子问题得到的
void LCSLength(int m, int n, char * x, char * y, int ** c, int ** b){
    int i, j;
    for(i = 1; i <= m; i++) {
        c[i][0] = 0;
    }

    for(j = 1; j <= n; i++) {
        c[0][j] = 0;
    }

    for(i = 1; i <= m; i++){
        for(j = 1; j <= n; j++){
            if(x[i] == y[i]){
                c[i][j] = c[i - 1][j - 1] + 1;
                
            }
        }
    }
}

int main(void){

    char x[] = {'a', 'b', 'c', 'b', 'd', 'a', 'b'};
    char y[] = {'b', 'd', 'c', 'a', 'b', 'a'};

    int m = (int)sizeof(x)/sizeof(int);
    int n = (int)sizeof(y)/sizeof(int);
    int c[10][10];
    int b[10][10];

    memset(c, 0, sizeof(c));
    memset(b, 0, sizeof(b));


    LCSLength(m, n, x, y, c, b);
    return 0;
}
