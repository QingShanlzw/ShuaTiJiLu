#include<bits/stdc++.h>
using namespace std;
int n,r;
vector<int>temp;
void dfs(int d,int k){
	if(d>r){
		for(int i =0;i<r;i++)cout<<setw(3)<<temp[i];
		cout<<endl;
		return;
	}
	for(int i =k;i<=n-r+d;i++){
		temp.push_back(i);
		dfs(d+1,i+1);
		temp.pop_back();
	}
}
int main(){
	cin>>n>>r;
	dfs(1,1);
	return 0;
}
