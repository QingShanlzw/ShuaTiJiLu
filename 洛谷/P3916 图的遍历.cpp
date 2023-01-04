//
////问题所在：看：
///*
//3 3
//2 9
//9 2
//2 10
//*/ 
//#include<bits/stdc++.h>
//using namespace std;
//const int N = 1e5+7;
//vector<int>g[N];
//int A[N];
//int n,m;
//set<int>s;
//int  dfs(int x){
//	if(A[x]!=0) return A[x];
//	A[x] =x;
//	for(int i =0;i<g[x].size();i++){
//		A[x] =max(A[x],dfs(g[x][i]));
//		if(x==2)cout<<g[x][i]<<' '<<dfs(g[x][i])<<endl;
//	}	
//	return A[x];
//}
//int main(){
//	cin>>n>>m;
//	for(int i =0;i<m;i++){
//		int a,b;
//		cin>>a>>b;
//		if(a==b)continue;
//		g[a].push_back(b);
//		s.insert(a);
//		s.insert(b);
//	}
//	cout<<"=========================="<<endl;
//	for(auto i:s)cout<<i<<' '<< dfs(i)<<;
//	return 0;
//}

#include<bits/stdc++.h>
using namespace std;
const int N =1e6+7;
int n,m;
vector<int>g[N];
int a[N];
void dfs(int x,int k){
	if(a[x])return;
	a[x] = k;
	for(int i =0;i<g[x].size();i++){
		dfs(g[x][i],k);
	}
}
int main(){
	cin>>n>>m;
	for(int i =0;i<m;i++){
		int x,y;
		cin>>x>>y;
		g[y].push_back(x);
	}
	for(int i =n;i>=0;i--)dfs(i,i);
	for(int i =1;i<=n;i++)cout<<a[i]<<' ';
	return 0;
}







