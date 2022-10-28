#include<bits/stdc++.h>
using namespace std;
const int N  = 1e5*5+7;
const int Mod = 80112002;
int n,m;
int h[N],e[N],ne[N],idx;
queue<int>q;
int in[N],out[N],sum[N];
int res;
void add(int x,int y){
	e[idx] = y;
	ne[idx] = h[x];
	h[x] =idx++;
}
void topo(){
	for(int i =1;i<=n;i++){
		if(!in[i]){
			q.push(i);
			sum[i]=1;
		}
	}
	while(!q.empty()){
		int k  =q.front();
		q.pop();
		for(int i =h[k];i!=-1;i = ne[i]){
			int j = e[i];
			sum[j] = (sum[k]+sum[j])%Mod;
			if(!(--in[j]))q.push(j);
		}
	}
}
 int main(){
 	memset(h,-1,sizeof h);
 	cin>>n>>m;
 	for(int i =0;i<m;i++){
 		int a,b;
 		cin>>a>>b;
 		add(a,b);
 		in[b]++;
 		out[a]++;
	 }
	 topo();
	 for(int i =1;i<=n;i++)if(!out[i])res  =  (res+sum[i])%Mod;
	 cout<<res;
 	return 0;
 }
