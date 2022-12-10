#include<iostream>
#include<string>
#include<algorithm>
#include<queue>
using namespace std;
int n,a,b;
const int N = 207;
int m[N];
bool f[N];
queue<int>q;
int res =-1;
int cnt;
int main(){
	cin>>n>>a>>b;
	a-=1,b-=1;
	if(a==b){
		cout<<0;
		return 0;
	}
	for(int i=0;i<n;i++)cin>>m[i];
	q.push(a);
	f[a]= 1;
	while(!q.empty()){
		cnt++;
		int len  =q.size();
		for(int i =0;i<len;i++){
			int k =q.front();
			q.pop();
			if(m[k]+k<n&&!f[k+m[k]]){
				if(k+m[k]==b){
					cout<<cnt;
					return 0;
				}
				f[k+m[k]] =1;
				q.push(k+m[k]);
			}
			if(k-m[k]>=0&&!f[k-m[k]]){
				if(k-m[k]==b){
					cout<<cnt;
					return 0;
				}
				f[k-m[k]] =1;
				q.push(k-m[k]);
			}
		}
	}
	cout<<res;
	return 0;
}
