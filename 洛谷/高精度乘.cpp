#include<bits/stdc++.h>
using namespace std;
const int N  = 2010;
string t1,t2;
int a[N],b[N],res[N*2];
int main(){
	cin>>t1>>t2;
	if(t1=="0"||t2=="0"){
		cout<<0;
		return 0  ;
	}
	int lena = t1.length();
	int lenb = t2.length();
	//cout<<lena<<lenb<<endl;
	for(int i = 0;i<lena;i++){
		a[i] = t1[lena-1-i]  - '0';
	}
	for(int i = 0;i<lenb;i++){
		b[i] = t2[lenb - 1 -i] - '0';
	}

	for(int i = 0;i< lena;i++ ){
		int k  = 0;//½øÎ» 
		for(int j =0;j<lenb;j++){
			res[i+j] = (a[i]*b[j] + k + res[i+j]);
			k = (res[i+j])/10;
			res[i+j] %=10;
		}
		res[i+lenb]+= k;
	}
	int lenc = lena + lenb;
	//cout<<lenc<<endl;
	for(int i = lenc-1;i>=0;i--)
		if(!res[i])
			lenc--;
		else break;
	//cout<<lenc<<endl;	
	for(int i = lenc-1;i>=0;i--)cout<<res[i];		
	return 0;
}
