#include<bits/stdc++.h>
using namespace std;
const int N = 1007;
int v[N];
int n,m;
int main(){
	cin>>n>>m;
	for(int i =0;i<m;i++){
		int x;
		cin>>x;
		v[x]++;
	}
	sort(v,v+m);
	for(int i =0;i<n;i++)cout<<v[i]<<' ';
	return 0;
}

