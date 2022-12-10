//dfs
#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;
int res;
int a[5];
int arr[5][25];
int l,r,tempans=9999;
void dfs(int x,int y){
	if(y>=a[x])tempans =min(tempans,max(l,r));
	else{
		l+=arr[x][y];
		dfs(x,y+1);
		l-=arr[x][y];
		r+=arr[x][y];
		dfs(x,y+1);
		r-=arr[x][y];
	}
}
int main(){
	cin>>a[1]>>a[2]>>a[3]>>a[4];
	for(int i =1;i<=4;i++){
		for(int j =0;j<a[i];j++)
			cin>>arr[i][j];	
		dfs(i,0);
		res+=tempans;
		tempans =9999;
		l =r =0;		
	}
	cout<<res;
	return 0;
}
