#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5+7;
ll n,m,g[N],god[N][3];
stack<ll>q;

int main(){
	cin>>n>>m;
	if(m==1){
		cout<<0;return 0;
	}
	ll k;cin>>k;q.push(k);
	for(int i =0;i<m-1;i++){
		cin>>k;
		ll maxn = max(k,q.top());
		ll minn = min(k,q.top());
		q.push(k);
		g[minn]++,g[maxn]--;
	}
	for(int i = 1;i<=n;i++)g[i]+=g[i-1];
	for(int i =1;i<n;i++){
		ll a,b,c;
		cin>>a>>b>>c;
		god[i][0] =a,god[i][1] =b,god[i][2] =c;
	}
	ll res =0;
	for(int i =1;i<=n;i++){
		if(g[i]){
			res+= (ll)min((ll)(god[i][0]*g[i]),(ll)(god[i][1]*g[i])+god[i][2]);
		}
	}
	cout<<res;
	return 0;
}
