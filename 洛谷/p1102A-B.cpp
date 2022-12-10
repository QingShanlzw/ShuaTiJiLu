#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int N =2e5+5;
ll n,c;
ll a[N];
int main(){
	cin>>n>>c;
	for(int i =0;i<n;i++)cin>>a[i];
	sort(a,a+n);
	ll res = 0;
	for(int i =0;i<n;i++)
		res+=(*(upper_bound(a,a+n,a[i]+c))==*(lower_bound(a,a+n,a[i]+c))?0:1);
	cout<<res;	
	return 0;
}
