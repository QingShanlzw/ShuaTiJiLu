#include<bits/stdc++.h>
using namespace std;
vector<string>t;
vector<int>f;
int n,m;
int a,b;
int k;
int d;
int main(){
	cin>>n>>m;
	for(int i =0;i<n;i++){
		int tt;
		string aa;
		cin>>tt>>aa;
		t.push_back(aa);
		f.push_back(tt);
	}
	while(m--){
		cin>>a>>b;
		if(a==0){
			f[k] ? (k+=b) :(k=(k-b));			
		}
		else{
			f[k] ?(k=(k-b)):(k+=b);		
		}
		if(k<0)k+=n;
		k = k%n;
		//cout<<k<<endl;
	}
	cout<<t[k];
	return 0;
}
