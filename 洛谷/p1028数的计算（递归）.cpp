#include<iostream>
using namespace std;
int n;
//int dfs(int n){
//	if(n<=1)return 1;
//	int x = n/2;
//	int temp =1;
//	for(int i =1;i<=x;i++)
//		temp+=dfs(i);
//	return temp;	
//}	

typedef long long ll;
const int  N = 1007;
ll dp[N];
int main(){
	cin>>n;
	dp[1]=1;
	for(int i =2;i<=n;i++){
		int k = i/2;
		for(int j =1;j<=k;j++)
			dp[i]+=dp[j];
		dp[i]+=1;	
	}
	cout<<dp[n];
	return 0;
}
