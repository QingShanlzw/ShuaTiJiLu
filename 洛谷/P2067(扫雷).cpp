#include<bits/stdc++.h>
using namespace std;
const int N  =107;
char a[N][N];
int res[N][N];
 int n,m; 
 bool tt(int i,int j){
 	if(i<0||i>=n||j<0||j>=m||a[i][j]!='*')
 	return false;
 	else return true;
 }
 void change(int i ,int j){
 	if(a[i][j]=='*')res[i][j]= -100;
 	else{
 		if(tt(i-1,j))res[i][j]++;
 		if(tt(i-1,j+1))res[i][j]++;
 		if(tt(i,j+1))res[i][j]++;
 		if(tt(i+1,j+1))res[i][j]++;
 		if(tt(i+1,j))res[i][j]++;
 		if(tt(i+1,j-1))res[i][j]++;
 		if(tt(i,j-1))res[i][j]++;
 		if(tt(i-1,j-1))res[i][j]++;		
	 }
 }
int main(){
	cin>>n>>m;
	for(int i=0;i<n;i++)
		for(int j  = 0;j<m;j++)
			cin>>a[i][j];
	for(int i = 0;i<n;i++)
		for(int j = 0;j<m;j++)
			change(i,j);
	for(int i  =0;i<n;i++){
		for(int j  =0;j<m;j++)
			if(res[i][j]==-100)
				cout<<'*';
			else cout<<res[i][j];
		cout<<endl;
	}
						
	return 0;
}


