#include<bits/stdc++.h>
using namespace std;
const int N = 107;
int a[N][N],dp[N][N];
bool f[N][N];
int res;
int n,m;
void dfs(int i,int j){
	if(i<0||i>=n||j<0||j>=m||f[i][j])return;
	f[i][j] =true;
	if((i-1>=0)&&a[i][j]>=a[i-1][j]){
		if(!f[i-1][j]) dfs(i-1,j);		
		dp[i][j] = min(dp[i][j],dp[i-1][j]);
	}
	if((j-1>=0)&&a[i][j]>=a[i][j-1]){
		if(!f[i][j-1])dfs(i,j-1);
		dp[i][j] = min(dp[i][j],dp[i][j-1]);
	}
	if((i+1<n)&&a[i][j]>=a[i+1][j]){
		if(!f[i+1][j])dfs(i+1,j);
		dp[i][j] = min(dp[i][j],dp[i+1][j]);
	}

	if((j+1<m)&&a[i][j]>=a[i][j+1])
	{
		if(!f[i][j+1])dfs(i,j+1);
		dp[i][j] = min(dp[i][j],dp[i][j+1]);
	}

	res = max(res,a[i][j]-dp[i][j]);
	
}
int main(){
	cin>>n>>m;
	for(int i = 0;i<n;i++)
		for(int j = 0;j<m;j++)
			{
				cin>>a[i][j];
				a[i][j]==1?(dp[i][j]=0):(dp[i][j]=a[i][j]) ;
			}
	for(int i =  0;i<n;i++)
		for(int j  = 0;j<m;j++)
			if(a[i][j]==1||a[i][j]==0){
				dp[i][j] =0;
				f[i][j] =true;
				res =max(res,a[i][j]);
			}
			 else  dfs(i,j);					 
	cout<<res;		 		
	return 0;
}
/*
5 5
1 2 3 4 5
16 17 18 19 6
15 24 25 20 7
14 23 22 21 8
13 12 11 10 9
*/
