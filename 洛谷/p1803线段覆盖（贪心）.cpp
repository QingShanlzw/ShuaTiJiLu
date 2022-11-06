#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+7; 
struct gy{
	int begin;
	int end;
}g[N];
bool cmp(gy a , gy b){
	return a.end<b.end;
}
int n;
int res =1;
int main(){
	cin>>n;
	for(int i =0;i<n;i++)
		cin>>g[i].begin>>g[i].end;
	sort(g,g+n,cmp);
	int temp = g[0].end;
	for(int i =0;i<n;i++){
		if(g[i].begin<temp)continue;
		else {
			res++;
			temp= g[i].end;
		}
	}		
	cout<<res;
	return 0;
}
