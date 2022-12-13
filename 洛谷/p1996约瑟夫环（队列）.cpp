#include<bits/stdc++.h>
using namespace std;
queue<int>q;
int n,m;
int main(){
	cin>>n>>m;
	for(int i =1;i<=n;i++){
		q.push(i);
	} 
	while(!q.empty()){
		for(int i =1;i<=m;i++){
			int t = q.front();
			q.pop();
			if(i==m)cout<<t<<' '; 
			else q.push(t);
		}
	}
	return 0;
}
