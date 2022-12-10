#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
int n;
vector<int>path;
void dfs(int x){
	if(!x){
		if(path.size()==1)return;
		for(int i =0;i<path.size();i++){
			cout<<path[i];
			if(i!=path.size()-1)cout<<"+";
		}
		cout<<endl;
		return;
	}
	for(int i =1;i<=x;i++){
		 if(!path.size()||i>=path[path.size()-1]){
			path.push_back(i);
			dfs(x-i);
			path.pop_back();
		}
	}
}
int main(){
	cin>>n;
	dfs(n);
	return 0;
}
