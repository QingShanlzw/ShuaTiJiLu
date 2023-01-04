#include<bits/stdc++.h>
using namespace std;
int n;
int a[35];
typedef long long ll;
int main(){
	cin>>n;
	
	string s ="";
	while(n){
		s+= (n%2+'0');
		n/=2;
	}	
	s = string(s.rbegin(),s.rend());
	int len = 32-s.length();
	string temp="";
	while(len--)temp+='0';
	s =temp+ s;
	//cout<<s<<endl;
	for(int i =0;i<32;i++)a[i] =s[i]-'0';
	for(int i =0;i<=15;i++)swap(a[i],a[i+16]);
	//for(auto i:a)cout<<i;
	//cout<<endl;
	ll res =0;
	for(int i =0;i<32;i++){
		res = res*2 + a[i];
		//cout<<"res=="<<res<<endl;
	}
	cout<<res;
	return 0;
}
