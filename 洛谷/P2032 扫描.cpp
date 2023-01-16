#include<bits/stdc++.h>
using namespace std;
int n,k;
const int N =2e6+7;
int stk[N],tt=-1,hh,a[N];
int main(){
	cin>>n>>k;
	for(int i =0;i<n;i++){
		cin>>a[i];
		if(tt ==-1) stk[++tt] =i;
		else{
			while(tt>=hh && a[stk[tt]]<a[i])tt--;
			stk[++tt] =i;
		}
		if(stk[hh]<i-k+1)hh++;
		if(i>=k-1)cout<<a[stk[hh]]<<endl;
	}
	return 0;
}
// 8 6 4  7
