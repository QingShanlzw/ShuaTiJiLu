//寻找局部最优解，局部最优解就是全局最优解 
#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+5;
typedef long long ll;
ll res;
int n,x;
int a[N];
int main(){
	cin>>n>>x;
	for(int i =0;i<n;i++)cin>>a[i];
	if(a[0]>x){
		int k = a[0]-x;
		a[0]=x;
		res+= k;
	}
	for(int i =1;i<n;i++)
		if(a[i]+a[i-1]>x){
			int k =(a[i]+a[i-1])-x;
			res+=k;
			a[i]-=k;
		}
		//for(int i =0;i<n;i++)cout<<a[i]<< ' ';
		//cout<<endl;
	cout<<res;		
	return 0; 
}
