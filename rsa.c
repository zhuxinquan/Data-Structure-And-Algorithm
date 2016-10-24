/*************************************************************************
	> File Name: rsa.c
	> Author: zhuxinquan
	> Mail: zhuxinquan61@xiyoulinux.org
	> Created Time: 2016年10月18日 星期二 16时36分48秒
 ************************************************************************/

#include<stdio.h>
#include<math.h>

//最大公约数
int rgcd(int v1,int v2)
{
    if(v2!=0){
        return rgcd(v2,v1%v2);
    }
    return v1;
}

void getE(int * e, int In){
    int i;
    for(i = 2; i < In; i++){
        //判断是否互素，最大公约数为1
        if(rgcd(i, In) == 1){
            *e = i;
            return ;
        }
    }
}

void getD(int * d, int e, int In){
    int i;
    for(i = 1; i < In; i++){
        if(i * e % In == 1 ){
            *d = i;
            return ;
        }
    }
}

int main(int argc, char * argv[])
{
    int p, q;
    int n, In;
    int e;
    int d;
    int M, C;
    int temp = 1;
    int i;
    p = 17;
    q = 11;
    n = p * q;
    In = (p - 1)*(q - 1);
    getE(&e, In);
    getD(&d, e, In);
    printf("p = %d, q = %d, d = %d, e = %d, n = %d, In = %d\n", p, q, d, e, n, In);
    printf("公钥：{%d, %d}, 私钥:{%d, %d}\n", e, n, d, n);
    printf("输入明文M :");
    scanf("%d", &M);
    //加密
    for(i = 0; i < e; i++){
        temp = temp * M;
        if(temp > n){
            temp = temp % n;
        }
    }
    printf("加密后：%d\n", temp);
    C = temp;
    temp = 1;
    //解密
    for(i = 0; i < d; i++){
        temp = temp * C;
        if(temp > n){
            temp = temp % n;
        }
    }
    printf("解密后：%d\n", temp);
}
