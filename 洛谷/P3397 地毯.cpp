//²î·ÖÊý×é 
#include<bits/stdc++.h>
using namespace std ;
const int N =1007;
int g[N][N],n,m;
int main(){
	cin>>n>>m;
	for(int i =1;i<=m;i++){
		int a,b,c,d;
		cin>>a>>b>>c>>d;
		for(int j = a;j<=n&&j<=c;j++)
			g[j][b]++,g[j][d+1]--;
	}
	for(int i =1;i<=n;i++){
		for(int j = 1;j<=n;j++){
			g[i][j]+=g[i][j-1];
			cout<<g[i][j]<<' ';
		}
		cout<<endl;	
	}
	return 0;
}
