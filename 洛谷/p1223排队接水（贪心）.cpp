#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N  = 1e3+7;
int n;
struct p{
	int val;
	int idx;
}a[N];
double res;
bool tmp(p a, p b){
	return  a.val<b.val;
}
int main(){
	cin>>n;
	for(int i = 1;i<=n;i++){
		cin>>a[i].val;
		a[i].idx = i;	
	}
	sort(a+1,a+n+1,tmp);
	for(int i =1;i<=n;i++){
		res+=(double)(a[i].val*(n-i));
		cout<<a[i].idx<<' ';			
	}
	res  = (double)res / n;
	cout<<endl;
	printf("%.2f",res);
	return 0;
}
