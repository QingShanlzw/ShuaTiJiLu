/*
二分也可以找有很多一样的数字，只要条件改一下就ok。 
*/

#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+4;
int a[N];
int n,m;
int main(){
	cin>>n>>m;
	for(int i =1;i<=n;i++)cin>>a[i];
	while(m--){
		int t;
		cin>>t;
		int l = 1,r = n;
		while(l<r){
			int mid = l + r >> 1;
			if(a[mid]>=t)r= mid;
			else l = mid+1;
		}
		if(a[l]!=t)cout<<-1<<' ';
		else cout<<l<<' ';
	}
	return 0;
}
