//文章一可能被其他的引用，所以要标记一下文章一。 
#include<bits/stdc++.h>
using namespace std ;
const int N =1e6+7;
vector<int>g[N];
int n,m; 
bool ff[N];
queue<int>q;
void dfs(int k){
	cout<<k<<' ';
	ff[k]=1;
	for(int i =0;i<g[k].size();i++)
		if(!ff[g[k][i]]){
			ff[g[k][i]] =1;
			dfs(g[k][i]);
		}	
}
void bfs(){
	q.push(1);
	ff[1] =1;
	while(!q.empty()){
		int len =q.size();
		for(int i =0;i<len;i++){
			int k =q.front();
			cout<<k<<' ';
			q.pop();
			for(int j =0;j<g[k].size();j++)if(!ff[g[k][j]]){
				ff[g[k][j]] =1;
				q.push(g[k][j]);
			}
		}
	}
}
int main(){
	cin>>n>>m;
	if(n==0||m==0)return 0;
	for(int i =0;i<m;i++){
		int a,b;
		cin>>a>>b;
		g[a].push_back(b);
	}
	for(int i =1;i<N;i++)sort(g[i].begin(),g[i].end());
	dfs(1);cout<<endl;
	for(int i =1;i<N;i++)ff[i] =0;
	bfs();
	return 0;
}
