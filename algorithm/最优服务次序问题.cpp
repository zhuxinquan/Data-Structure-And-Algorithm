/*************************************************************************
	> File Name: 最优服务次序问题.c
	> Author: zhuxinquan
	> Mail: zhuxinquan61@xiyoulinux.org
	> Created Time: 2016年06月01日 星期三 17时30分49秒
 ************************************************************************/

#include<iostream>   
#include <vector>   
#include<algorithm>    
using namespace std;   
using std::vector;   
  
double greedy(vector<int>x,int s)   
{   
    vector<int>st(s+1,0);  
    vector<int>su(s+1,0);    
    int n=x.size();    
    sort(x.begin(),x.end());    
    int i=0,j=0;    
      
    while(i<n){  
        st[j]+=x[i];     
        su[j]+=st[j];     
        i++;  
        j++;     
        if(j==s)j=0;   
    }   
  
    double t=0;  
  
    for(i=0;i<s;i++)   
        t+=su[i];   
    t/=n;   
    return t;  
}    
  
int main()  
{  
    int n;//等待服务的顾客人数    
    int s;//服务点的个数    
    int i;    
    int a;     
    int t;//平均服务时间    
    vector<int>x;     
    cout<<"please input the num of the customer:"<<endl;    
    cin>>n;     
    cout<<"please input the num of the server:"<<endl;    
    cin>>s;     
    cout<<"please input the need service time of each customer:"<<endl;    
  
    for(i=1;i<=n;i++)  
    {  
        cout<<"No."<<i<<endl;   cin>>a;   x.push_back(a);   
   }   
   t=greedy(x, s);   
   cout<<"the least average waiting time is:"<<t<<endl;   
    return 0;
}
