#include<bits/stdc++.h>
using namespace std;
int n;
int m;
unordered_set<int > s;
vector<int>res;
int main(){
	cin>>n;
	while(n--){
		cin>>m;
		for(int i =0;i<m;i++){
			int k;cin>>k;
			if(!s.count(k)){
				res.push_back(k);
				s.insert(k);
			}
		}
		for(int i =0;i<res.size();i++)
			cout<< res[i]<<' ';
		cout<<endl;	
		res.clear();
		s.clear();
	}
	
	return 0;
}
