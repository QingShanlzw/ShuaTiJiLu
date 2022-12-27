#include<bits/stdc++.h>
using namespace std;
queue<pair<int,int >>q;
int n;
int main(){
	cin>>n;
	n= pow(2,n);
	for(int i =1;i<=n;i++){
		int k;cin>>k;
		q.push(pair<int ,int >(k,i));
	}
	while(q.size()>2){
		int a1 =q.front().first;
		int a2 =q.front().second;
		q.pop();
		int b1 = q.front().first;
		int b2 = q.front().second;
		q.pop();
		if(a1>b1){
			q.push(pair<int,int >(a1,a2));
		}
		else q.push(pair<int,int>(b1,b2));
		
	}
	pair<int,int >a = q.front();
	q.pop();
	if(a.first<q.front().first){
		cout<<a.second;
	}
	else cout<<q.front().second;
	return 0;
}
