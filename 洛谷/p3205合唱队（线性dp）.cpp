/*
#include<bits/stdc++.h>
using namespace std;
const int N = 1e3+7;
const int mod = 19650827;
int n;
int a[N];
int dp[N][N];
int main(){
	cin>>n;
	for(int i =1;i<=n;i++)cin>>a[i],dp[i][i] =1;
	for(int len = 2;len<=n;len++)
		for(int i = 1;i+len-1<=n;i++){
			int l =i,r = i+len-1;
			dp[l][r]= ((dp[l+1][r]+dp[l][r-1])%mod);
		}
	cout<<dp[1][n]%mod;	
	return 0;
}
以上作法的问题所在：只考虑到就是i到j的数目由 i-1到j和 i到j-1加和组成，
但是没有考虑到就是会比如a[i]和i+1到j的大小的情况，即只有比前一个数字小才可以
加入到。 
解决：就是比如：考虑a[i]加入之前，他要比a[i+1]小或者比a[j]小。
用dp[i][j][0]表示最后一次是从左边加入的次数。 
还有就是边界当i= =j时，把他们认为是从左侧加入就ok了。 
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef int itn;
const int N =  1e3+7;
const int mod  =19650827;
int n;
int a[N];
int dp[N][N][2];

int main(){
	cin>>n;
	for(int i =1;i<=n;i++){
		cin>>a[i];
		dp[i][i][0]  =1;
	}
	for(int len  =2;len<=n;len++)
		for(itn i  = 1;i+len-1<=n;i++){
			itn j = i+len-1;
			if(a[i]<a[i+1])dp[i][j][0]+=dp[i+1][j][0];
			if(a[i]<a[j])dp[i][j][0]+=dp[i+1][j][1];
			if(a[j]>a[i])dp[i][j][1]+=dp[i][j-1][0];
			if(a[j]>a[j-1])dp[i][j][1]+=dp[i][j-1][1];
			dp[i][j][0]%=mod;
			dp[i][j][1]%=mod;
		}
	cout<<(dp[1][n][0]+dp[1][n][1])%mod;	
	return 0;
}


