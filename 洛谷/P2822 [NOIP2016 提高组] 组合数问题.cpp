#include<bits/stdc++.h>
using namespace std ;
int n,m,t,k;
const int N =2007;
int a[N][N];
int ans[N][N];
int main(){
	cin>>t>>k;
	a[1][1]=1;
	for(int i =0;i<=2000;i++)a[i][0] =1;
	for(int i =2;i<=2000;i++){
		for(int j =1;j<=i;j++){
			a[i][j] = (a[i-1][j]+a[i-1][j-1])%k;
			ans[i][j] = ans[i-1][j]+ans[i][j-1]- ans[i-1][j-1];
			if(!a[i][j])ans[i][j]++;
		}
		ans[i][i+1] =ans[i][i];
	}
	while(t--){
		cin>>n>>m;
		m = m>n?n:m;
		cout<<ans[n][m]<<endl;
	}
	return 0;			
}
