//优先级队列 
//priority_queue<int,vector<int>,greater<int>>q表示从小到大；
//priority_queue<int> 默认为从大到小 
//和石子合并不一样的是：
//石子合并：区间dp，合并完不可以动
//本题：优先级队列，合并完可以动， 
#include<bits/stdc++.h>
using namespace std;
int n;
int res;
int x;
priority_queue<int,vector<int>,greater<int>>q;
int main(){
	cin>>n;
	while(n--)cin>>x,q.push(x);
	while(q.size()>1){
		int a = q.top();q.pop();
		int b = q.top();q.pop();
		res+= (a+b);
		q.push(a+b);
	}
	cout<<res;
	return 0;
}
