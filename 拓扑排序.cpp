/*
那个树的重心题目就是dfs
*/
//拓扑排序

#include<bits/stdc++.h>
using namespace std;

const int N  = 1e6+7,M = N*2;
int h[N],e[M],ne[M],idx;
int q[N];//queue;
int hh =0,tt=-1;//对头和队尾
int d[N];//每个点的入度
int n,m;
void add(int a,int b){
    e[idx] = b;
    ne[idx] =h[a];
    h[a] = idx++;
}
//bool 说明可以判断一下是否可以形成拓扑序列，即无环图
bool topsort(){
    for(int i = 1;i<=n;i++)
        if(!d[i]) q[++tt] = i;
    while(hh<=tt){
        int k = q[h++];
        for(int i = h[k];i!= -1;i =ne[i] ){
            int j = e[i];
            d[j]--;
            if(!d[j])q[++tt] = j;
        }
    } 
    return tt == n-1;
        
}
int main(){
    cin>>n>>m;
    memset(h,-1,sizeof h);
    for(int i = 0;i<m;i++){
        int a,b;
        cin>>a>>b;
        add(a,b);
        d[b]++;
    }
    if(topsort()){
        //打印队列即为 拓扑排序
    }
    else{
        //有环
    }
    
}

