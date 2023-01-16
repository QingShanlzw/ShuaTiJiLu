#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll ans;
const int N =5e5+7;
int a[N],n,tmp[N];

void dfs(int l,int r){
	if(l>=r)return;
	int mid = l + r >> 1;
	dfs(l,mid);
	dfs(mid+1,r);
	int i =l, j =mid+1,ff =l;
	while(i<=mid && j<=r){
		if(a[i]<=a[j]) tmp[ff++] =a[i++];
		else tmp[ff++] =a[j++],ans+= (ll)(mid-i+1);
	}
	while(i<=mid)tmp[ff++] = a[i++];
	while(j<=r) tmp[ff++] =a[j++];
	for(int ii = l;ii<=r;ii++)a[ii] =tmp[ii];
}
int main(){
	cin>>n;
	for(int i =1;i<=n;i++)
		scanf("%d",&a[i]);
	dfs(1,n);	
	printf("%lld",ans);	
	return 0;
}
