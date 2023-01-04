#include<bits/stdc++.h>
using namespace std ;
const int N = 10007;
int n,m,k,tim[N],rd[N],dp[N],res;
vector<int>g[N];
queue<int>q;
void bfs(){
	while(!q.empty()){
		int len  =q.size();
		for(int i =0;i<len;i++){
			int k =q.front();
			q.pop();
			for(int j = 0;j<g[k].size();j++){
				int temp =g[k][j];
				dp[temp] =max(dp[temp],dp[k]+tim[temp]);
				if(!--rd[temp])q.push(temp);
			}
		}
	}
}
int main(){
	cin>>n;
	int tt =n;
	while(tt--){
		cin>>m;
		cin>>tim[m];
		while(cin>>k&&k){
			g[k].push_back(m);
			rd[m]++;
		}
	}
	for(int i =1;i<=n;i++)if(!rd[i]){
		q.push(i);
		dp[i] =tim[i];
	}
	bfs();
	for(int i =1;i<=n;i++)res=max(res,dp[i]);
	cout<<res;
	return 0;
}
