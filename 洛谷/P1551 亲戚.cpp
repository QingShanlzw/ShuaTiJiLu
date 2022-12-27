#include<bits/stdc++.h>
using namespace std;

const int N =5007;

int n,m,p;

//²¢²é¼¯
int a[N];
int find(int x){
	if(a[x]!=x)a[x]=find(a[x]);
	return a[x];
} 

int main(){
	cin>>n>>m>>p;
	for(int i =1;i<=n;i++)a[i]=i;
	for(int i =1;i<=m;i++){
		int x,y;
		cin>>x>>y;
		a[find(x)] = find(y);
	}
	for(int i =0;i<p;i++){
		int x,y;
		cin>>x>>y;
		if(find(x)==find(y))cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
	return 0; 
}
