#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef int itn;
const int N = 30;
int n,k,res;
int a[N];
bool su(int ans){
	if(ans<=1)return false;
	int temp = sqrt(ans)+1;
	for(int i =2;i<=temp;i++)
		if(!(ans%i))return false;
	return true;
}
void dfs(int d,int f,int ans){
	if(d>=k)
		if(su(ans)){
			res++;
			return;
		}
		else return;
	for(int i = f;i<n;i++)
		dfs(d+1,i+1,ans+a[i]);
} 
int main(){
	cin>>n>>k;
	for(int i =0;i<n;i++)cin>>a[i];
	sort(a,a+n);
	dfs(0,0,0);
	cout<<res;
	return 0;
}




