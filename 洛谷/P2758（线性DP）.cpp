#include<bits/stdc++.h>
using namespace std;
 string a,b;
 const int N = 2010;
 int dp[N][N];
 
int main(){
	memset(dp,0x3f,sizeof(dp));
	cin>>a>>b;
	a = '0' + a;
	b = '0' +b;
	for(int i =0;i<a.length();i++)dp[i][0] =i;
	for(int i =0;i<b.length();i++)dp[0][i] =i;
	int n = a.length();
	int m = b.length();
	//cout<<n<<' '<<m<<endl;
	//cout<<dp[1][1]<<endl;
	//cout<<a<<' '<<b<<endl;
	for(int i =1;i<a.length();i++)
		for(int j = 1;j<b.length();j++){
			dp[i][j] = min(dp[i-1][j]+1,dp[i][j-1]+1);
			if(a[i]==b[j])
				dp[i][j] =min(dp[i][j],dp[i-1][j-1]);
			else dp[i][j] = min(dp[i][j],dp[i-1][j-1]+1);	
		}
	cout<<dp[n-1][m-1];	
	return 0;
}
