/*
��ͳ������������У�LIS��������������У�LCS��������dp��N2��
���ǿ����Ż���
LIS�� https://blog.csdn.net/a1097304791/article/details/82286906
LCS�����԰�����ת��ΪLIS���⡣https://blog.csdn.net/m0_57221330/article/details/120185917 
nLOgn.
*/
#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+7;
map<int,int>m;
int b[N];
int dp[N];
int n;

int main(){
	cin>>n;
	for(int i= 1;i<=n;i++){
		int a;cin>>a;
		m[a] =i;
	}
	for(int i = 1;i<=n;i++){
		int a;cin>>a;
		b[i] = m[a];
	}
	int res =1;
	dp[1]=b[1];
	for(int i = 2;i<=n;i++){
		int pos = upper_bound(dp+1,dp+1+res,b[i])-dp;
		dp[pos] = b[i];
		res =max(res,pos);
	}
	cout<<res;
	return 0;
}	 		


