#include<stdio.h>

void swap(int * a, int r, int l){
    int t;
    t = a[r];
    a[r] = a[l];
    a[l] = t;
}

int main()
{
    int i, r, l, mid, a[6];
    for (i=0;i<6;i++)
    {
        scanf("%d",&a[i]);
    }
    l = 0;
    r = 5;
    mid = (l + r)/2;
    r = mid;
    while(l <= r){
        swap(a, l, r);
        swap(a, l + mid + 1, r + mid + 1);
        l++;
        r--;
    }
    for(i = 0; i < 6; i++){
        printf("%5d", a[i]);
    }
}

