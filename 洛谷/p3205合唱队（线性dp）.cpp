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
�����������������ڣ�ֻ���ǵ�����i��j����Ŀ�� i-1��j�� i��j-1�Ӻ���ɣ�
����û�п��ǵ����ǻ����a[i]��i+1��j�Ĵ�С���������ֻ�б�ǰһ������С�ſ���
���뵽�� 
��������Ǳ��磺����a[i]����֮ǰ����Ҫ��a[i+1]С���߱�a[j]С��
��dp[i][j][0]��ʾ���һ���Ǵ���߼���Ĵ����� 
���о��Ǳ߽統i= =jʱ����������Ϊ�Ǵ��������ok�ˡ� 
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


