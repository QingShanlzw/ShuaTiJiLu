#include<bits/stdc++.h>
using namespace std;
const int N  =507;
int n;
int dp[N][N],f[N][N];
int main(){
	cin>>n;
	for(int i =1;i<=n;i++)
		for(int j =  1;j<=i;j++)
			cin>>f[i][j];
	for(int i =0;i<n;i++)dp[n][i] = f[n][i];
	for(int i = n;i>=0;i--)
		for(int j = 0;j<=n;j++)
			dp[i][j] = max(dp[i+1][j],dp[i+1][j+1])+f[i][j];
	cout<<dp[1][1];				
	return 0;
}
