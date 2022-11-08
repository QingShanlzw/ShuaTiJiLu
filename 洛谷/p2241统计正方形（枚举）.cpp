/*
公式推导
求包含的四边形数：（sumi）*（sumj）
包含的正方形数：https://blog.csdn.net/bbyjh/article/details/113758065 
*/ 

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m;
ll s,a,x,y;
int main(){
	cin>>n>>m;
	for(int i =1;i<=n;i++)x+=i;
	for(int i =1;i<=m;i++)y+=i;
	s=  (x*y);
	x = y =0;
	int temp = n<m?n:m;
	while(temp>=1){
		a+=(n*m);
		n--;
		m--;
		temp--;
	}
	cout<<a<<' '<<s-a;
	return 0;
}
