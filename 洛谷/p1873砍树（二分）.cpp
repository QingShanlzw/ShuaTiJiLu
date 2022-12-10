//直接排个序顺序找就ok了。 
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef int itn;
ll n,m;
const int N =1e6+7;
 ll a[N];
 ll res;
 bool fun(int a,int b) {
 	return a>b;
 }
int main(){
	cin>>n>>m;
	for(int i = 0;i<n;i++)cin>>a[i];
	sort(a,a+n,fun);
	//for(int i = 0;i<n;i++)cout<<a[i]<<' ';
	if(n==1){
		cout<<a[0]-m;
		return 0;
	}
//	if((a[0]-a[1])>=m){
//		cout<<a[0]-m;
//		return 0;
//	}
//	res+=(a[1]-a[0]);
	for(int i =1;i<n;i++){
		if((res+ (a[i-1]-a[i])*i)>=m){
			int k = m - res;
			for(int j = a[i-1];j>=a[i];j--)
				if(i*(a[i-1]-j)>=k){
					cout<<j;return 0;
				}
		}
		else res+=(a[i-1]-a[i])*i;
	}
	return 0;
}
