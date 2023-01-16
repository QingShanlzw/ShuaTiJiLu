#include<bits/stdc++.h>
using namespace std;
const int Mod = 1e8-3;
const int N =1e5+7;
//bittree
int a[N],c[N],n;
int lowbit(int x){
	return x& -x;
}
void update(int i,int x){
	while(i<=n){
		c[i]+=x;
		i+=lowbit(i);
	}
}
int getsum(int i){
	int res =0;
	while(i){
		res+=c[i];
		i+=lowbit(i);
	}
	return res;
}

int main(){
	cout<<lowbit(5);
	return 0;
}
