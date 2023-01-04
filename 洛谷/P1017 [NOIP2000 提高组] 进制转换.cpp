#include<bits/stdc++.h>
using namespace std ;
int n,R;
int main(){
	cin>>n>>R;
	cout<<n<<"=";
	string res="";
	while(n){
		int t = n%R;
		
		if(t<0){
			t-=R;
			n+=R;
		}
		if(t>=10){
			res+= 'A'+(t-10);
		}
		else res+= t+'0';
		n/=R;
	}
	cout<<string(res.rbegin(),res.rend())<<"(base"<<R<<')';
	return 0;
}
