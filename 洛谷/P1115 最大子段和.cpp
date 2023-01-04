#include<bits/stdc++.h>
using namespace std;
const int N =2e5+7;
typedef long long ll;
ll a[N];
ll n,res;
int main(){
	cin>>n;
	cin>>a[0];
	for(int i =1;i<n;i++){
		int k;cin>>k;
		a[i] =a[i-1]+k;
	}
	res= a[0];
	ll Min =0;
	for(int i =1;i<n;i++){
		res = max(res,a[i]-Min);
		if(a[i]<0){
			Min =min(Min,a[i]);
		}
	}
	cout<<res;
	return 0;
} 
