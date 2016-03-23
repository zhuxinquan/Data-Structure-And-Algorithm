#include <stdio.h>

int d[10]; /* 用来存放分解结果 */

void decompose(int m, int n, int k); /* 将m分解为不大于n的组成数，k>=0是项号 */

int main()
{
    int n;

    printf("input n (1 <= n <= 10):");
    scanf("%d", &n);
    if (n>=1 && n<=10) {
        decompose(n, n, 0);

    }
    return 0;

}

void decompose(int m, int n,int k)
{
    int i;

    if (m == 0) { /* 当m为0时，得到一个划分，将分解结果输出 */
                 printf("%d", d[0]);
                 for (i=1; i<k; i++)
                 printf("+%d", d[i]);
                 for (i=1; i< k; i++) /* for + if 处理输出格式 */
                 if (d[i] != 1)
                 break;
                 if (i == k) {
                     printf("\n");

                 }
                 else
                 printf(", ");
                 return;
                }
    for (i=(m<n?m:n); i>0; i--) { /* 一次分解的几种可能分法 */
                                 if (i < n)
                                 d[k] = i;
                                 else
                                 d[k] = n;
                                 decompose(m-d[k], d[k], k+1); /* 递归调用使分解继续下去，直到得到一个划分 */
                                }

}
