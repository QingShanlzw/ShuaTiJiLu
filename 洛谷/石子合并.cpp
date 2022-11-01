//区间dp的精髓在for循环以len从小到大为基础，
//先把小区间模拟完，在去找大区间。 
#include<bits/stdc++.h>
using namespace std;
const int N  =307;
int s[N];
int f[N][N];
int ff[N][N];
int n; 
int main(){
	cin>>n;
	for(int i = 1;i<=n;i++){
		cin>>s[i];
		s[i]+=s[i-1];
	}
	
	for(int len =2;len<=n;len++)
		for(int i =1;i+len-1<=n;i++){
			int l = i,r = i+len-1;
			f[l][r] =1e7;
			ff[l][r] = -1;
			for(int k  = i;k<r;k++){
				f[l][r] = min(f[l][r],f[l][k]+f[k+1][r]+s[r]-s[l-1]);
				ff[l][r] =  max(ff[l][r],f[l][k]+f[k+1][r]+s[r]-s[l-1]);
			}
		}
	cout<<f[1][n];
	cout<<endl<<ff[1][n];	
	return 0;
}
