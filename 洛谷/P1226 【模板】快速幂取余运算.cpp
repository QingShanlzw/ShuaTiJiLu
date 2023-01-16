#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a,b,p;

int main(){
	cin>>a>>b>>p;
	ll a1 =a,b1 =b;
	ll ans=1;
	while(b){
		if(b&1) ans  = (ans*a)%p;
		a = a*a%p;
		b/=2;
	}
	cout<<a1<<"^"<<b1<<" mod "<<p<<"="<<ans<<endl;
	return 0;
}
