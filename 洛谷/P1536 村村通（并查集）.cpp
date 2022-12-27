#include<bits/stdc++.h>
using namespace std;
const int N =1007;
int a[N];
unordered_set<int>s;
int n,m;
int find(int x){
	if(x!=a[x])a[x] =find(a[x]);
	return a[x];
}

int main(){
	int n,m;
	while(1){
		cin>>n;
		s.clear();
		for(int i =1;i<=n;i++){
			a[i] =i;
			s.insert(i);
		}
		if(n){
			cin>>m;
			while(m--){
				int x,y;
				cin>>x>>y;
				int aa =find(x);
				int bb =find(y);
				if(aa!=bb){
					s.erase(aa);
					a[aa] = bb;
				}
			}
			cout<<s.size()-1<<endl;
		}
		else break;
	}
	return 0;
}
