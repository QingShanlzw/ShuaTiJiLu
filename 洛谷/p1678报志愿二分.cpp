#include<bits/stdc++.h>
using namespace std;
int m,n;
typedef long long  ll;
const int N = 1e6+7;
int a[N],b[N];
ll res;
int main(){
	cin>>m>>n;
	for(int i =0;i<m;i++)cin>>a[i];
	for(int i =0;i<n;i++)cin>>b[i];
	sort(a,a+m);
	sort(b,b+n);
	int i =0,j =0;
	while(j<n){
		if(i>m-1)res+=(abs(b[j++]-a[m-1]));
		else{
			while(i<=m-1&&a[i]<b[j])i++;
			if(!i){res+=(abs(b[j++]-a[i]));}
			else {
				res+=min(abs(b[j]-a[i]),abs(b[j]-a[i-1]));
				j++;
			}
		}
		//cout<<res<<endl;
	}
	cout<<res;
	return 0;
}
