/*************************************************************************
	> File Name: QuickSort.c
	> Author: zhuxinquan
	> Mail: zhuxinquan61@xiyoulinux.org
	> Created Time: 2016年06月12日 星期日 23时28分09秒
 ************************************************************************/

#include<stdio.h>

void QuickSort(int * a, int left, int right){
    int key, i, j;
    if(left >= right){
        return ;
    }
    i = left;
    j = right;
    key = a[left];
    while(i < j){
        while(i < j && key <= a[j]){
            j--;
        }
        a[i] = a[j];
        while(i < j && key >= a[i]){
            i++;
        }
        a[j] = a[i];
    }
    a[i] = key;
    QuickSort(a, left, i - 1);
    QuickSort(a, i + 1, right);
}

int main(void){
    int i;
    int a[] = {4, 2, 7, 9, 6, 1, 5, 3};
    int len = (int)sizeof(a)/sizeof(int);
    QuickSort(a, 0, len - 1);
    for(i = 0; i < len; i++){
        printf("%5d", a[i]);
    }
    printf("\n");
    return 0;
}
