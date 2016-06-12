/*************************************************************************
	> File Name: MergeSort.c
	> Author: zhuxinquan
	> Mail: zhuxinquan61@xiyoulinux.org
	> Created Time: 2016年06月12日 星期日 21时27分03秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

//把排好序的数组b复制回数组a当中
void copy(int * a, int *b, int len) {
    int i;
    for(i = 0; i < len; i++){
        a[i] = b[i];
    }
}

//合并两个已排好序的数组
void merge(int * aLeft, int leftLength, int * aRight, int rightLength, int * b){
    int i, j, k;
    i = j = k = 0;
    while(i < leftLength && j < rightLength){
        if(aLeft[i] < aRight[j]){
            b[k++] = aLeft[i++];
        }else {
            b[k++] = aRight[j++];
        }
    }
    while(i < leftLength){
        b[k++] = aLeft[i++];
    }
    while(j < rightLength){
        b[k++] = aRight[j++];
    }
}

//合并排序算法
void MergeSort(int * a, int len){
    int mid = len / 2;
    if(mid > 1){
        MergeSort(a, mid);
        MergeSort(a + mid, len - mid);
    }
    int * b = (int *)malloc(len * sizeof(int));
    merge(a, mid, a + mid, len - mid, b);
    copy(a, b, len);
    free(b);
}

int main(void){

    int i;
    int a[] = {2, 4, 6, 1, 3, 9, 5};

    int len = (int)sizeof(a)/sizeof(int);
    MergeSort(a, len);

    for(i = 0; i < len; i++){
        printf("%5d", a[i]);
    }

    printf("\n");
    return 0;
}
