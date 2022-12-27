#include<bits/stdc++.h>
using namespace std;
unordered_set<string>s;
int n;
int res;
int main(){
	cin>>n;
	while(n--){
		string temp;
		cin>>temp;
		if(!s.count(temp)){
			res++;
			s.insert(temp);
		}
	}
	cout<<res<<endl;
	return 0;
}
