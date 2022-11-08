/*
类似：https://blog.csdn.net/Baifeili/article/details/121170916完全背包
P1025 数的划分。 
*/

//这道题可以使用dfs来做，因为数据小，也可以直接10层forloop
//dfs从1到10就ok。
/*
开始思路错误：
被题目中的字典序迷惑
在想数字划分如何分。 
*/ 
#include<bits/stdc++.h>
using namespace std;
int n;
const int N =50000;
int res[N][11],ans;
int a[11]; 
void dfs(int sum,int k){
	if(!sum&&!k){
		ans++;
		for(int i =1;i<=10;i++){
			res[ans][i] =a[i];
		}
		return;
	}
	if(!sum||!k)return;
	for(int i= 1;i<=3;i++){
		a[10-k+1] = i;
		dfs(sum-i,k-1);
	}
	return;
}
int main(){
	cin>>n;
	if(n>30){
		cout<<0;
		return 0;
	}
	dfs(n,10);
	cout<<ans<<endl;
	for(int i=1;i<=ans;i++){
		for(int j=1;j<=10;j++)
		{
			cout<<res[i][j]<<' ';
		}
		cout<<endl;
	}
	return 0;
}
 
 
 
 
 
 
 
 
 
 
