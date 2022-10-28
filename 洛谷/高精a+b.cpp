/*
https://www.cnblogs.com/New-ljx/p/10480192.html
*/

#include<bits/stdc++.h>
using namespace std;
typedef int  itn;
typedef int  nti;
typedef long long LL;
string a,b;
int  k  =0;
const int N = 507;
int t[N],tt[N],res[N];
int lena,lenb;
int main(){
	cin>>a>>b;
	lena = a.length();
	lenb = b.length();
	for(int i  = 0;i<lena;i++)
		t[i] = a[lena-1-i]-'0';
	for(int i = 0;i<lenb;i++)
		tt[i]  =b[lenb-1-i]-'0';
	int m = max(lena,lenb);
	int f = 0;
	for(itn i = 0;i<m;i++){
		res[i] = (t[i]+tt[i]+f)%10;
		f = (t[i]+tt[i]+f)/10;
	}
	if(f){
		res[(++m)-1] = 1;
	}	
	for(int i = 0;i<m;i++)cout<<res[m-1-i];
	return 0;
}
