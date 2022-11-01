#include<bits/stdc++.h>
using namespace std;
const int N = 207;
int sum[N];
int n;
int dpmax[N][N],dpmin[N][N];
int main(){
	cin>>n;
	for(int i =1;i<=n;i++){
		cin>>sum[i];
		sum[i+n] =sum[i];
	}
	for(int i =1;i<=n*2;i++)sum[i]+=sum[i-1];
	for(int len =2;len<=n;len++)
		for(int i =1;i+len-1<=2*n;i++){
			int l = i,r =i+len-1;
			dpmax[l][r] = -1;
			dpmin[l][r] = 1e7;
			for(int k = l;k<r;k++){
				dpmax[l][r] = max(dpmax[l][r],dpmax[l][k]+dpmax[k+1][r]+sum[r]-sum[l-1]);
				dpmin[l][r] = min(dpmin[l][r],dpmin[l][k]+dpmin[k+1][r]+sum[r]-sum[l-1]);
			}
		}
	int res1 =1e7;
	int res2 =  -1;
	for(int i =1;i+n-1<=n*2;i++){
		res1 = min(res1,dpmin[i][i+n-1]);
		res2 = max(res2,dpmax[i][i+n-1]);
	}	
	cout<<res1<<endl<<res2;
	return 0;
}
