#include<stdio.h>

int num[100] = {0};

void dfs(int n, int k, int plies){	//n代表当前要进行划分的数，k代表当前划分不能超过的数，plies代表当前划分的层次
	int start, i;
	if(n == 0)
	{
		for(i=0; i<plies; i++)
			printf("%d ", num[i]);
		printf("\n");
		return;
	}
	if(k>n)
		start = n;
	else
		start= k;
	while(start>0)
	{
		num[plies] = start;
		dfs(n-start, start, plies+1);
		start--;
	}
}

void main(void){
	int n, plies = 0; //plies层数，代表当前划分包含多少个数据（多少层）
	scanf("%d", &n);
	dfs(n, n, 0);		//以6开始划分，划分为不超过6的结果，当前是第0层，即第1个数
}