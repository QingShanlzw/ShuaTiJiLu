#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod  = 1000000007;
int n; 
int main(){
	cin>>n;
	int a[n];
	for(int i =0;i<n;i++)cin>>a[i];
	sort(a,a+n);
	ll  ans =1;
//	for(int i =0;i<n;i++)cout<<a[i];
	for(int i =0;i<n;i++){
		if(a[i]-i){
			ans *= (a[i]-i);
			ans %=  mod;
		}
		else{
			cout<<0;
			return 0;
		}
	}
	cout<<ans;
	return 0;
}
