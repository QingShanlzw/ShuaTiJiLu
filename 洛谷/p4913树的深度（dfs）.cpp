#include<bits/stdc++.h>
using namespace std;
const int N =1e6+7;
struct node{
	int l,r;
}tree[N];
int n;
int dfs(int k){
	if(!tree[k].l&&!tree[k].r)return 0;
	return max(dfs(tree[k].l),dfs(tree[k].r))+1;
}
int main(){
	cin>>n;
	for(int i =1;i<n;i++){
		cin>>tree[i].l>>tree[i].r; 
	}
	cout<<dfs(1)+1;
	return 0;
}
