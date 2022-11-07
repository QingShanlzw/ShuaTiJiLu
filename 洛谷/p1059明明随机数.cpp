#include<bits/stdc++.h>
using namespace std;
const int N  =107;
set<int>s;
vector<int>v;
int res,n;
int main(){
	cin>>n;
	for(int i =0;i<n;i++){
		int k;
		cin>>k;
		if(!s.count(k)){
			v.push_back(k);
			s.insert(k);
		}
	}
	sort(v.begin(),v.end());
	cout<<v.size()<<endl;
	for(auto i:v)cout<<i<<' ';
	return 0;
}
