/*************************************************************************
	> File Name: test1.c
	> Author: zhuxinquan
	> Mail: zhuxinquan61@xiyoulinux.org
	> Created Time: 2016年04月21日 星期四 21时05分07秒
 ************************************************************************/

#include<stdio.h>
#include<string.h>

int main(void){
    int i, num[256] = {0};
    char a[100];
    scanf("%s", a);
    for(i = 0; i < strlen(a); i++){
        num[(int)a[i]]++;
    }
    for(i = 0; i < 256; i++){
        if(num[i] != 0){
            printf("%c----%d\n", i, num[i]);
        }
    }
    getchar();
}
