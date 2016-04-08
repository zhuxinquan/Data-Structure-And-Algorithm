/*************************************************************************
	> File Name: BinarySearch.c
	> Author: zhuxinquan
	> Mail: zhuxinquan61@xiyoulinux.org
	> Created Time: 2016年04月08日 星期五 21时05分39秒
 ************************************************************************/

#include<stdio.h>

int BinarySearch(int num[], int x, int n) {
    int left = 0;
    int right = n - 1;
    while (left <= right) {
        int middle = (left + right) / 2;
        if( x == num[middle] ) {
            return middle;
        }
        if( x > num[middle] ) {
            left = middle + 1;
        }else {
            right = middle - 1;
        }
    }
    return -1;
}

int main(int argc, char * argcgv[]) {
    int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int num = BinarySearch(a, 5, 10);
    printf("%d\n", num);
}
