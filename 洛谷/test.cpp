#include<bits/stdc++.h>
using namespace std;


int main(){
	vector<int>a(5,0);
	cout<<a.size();
	a.push_back(10);
	cout<<a.size(); 
	a.clear();
	cout<<a.size(); 
	a.push_back(1);
	cout<<a.size(); 
	return 0;
}
