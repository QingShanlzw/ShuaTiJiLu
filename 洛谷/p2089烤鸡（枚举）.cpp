/*
���ƣ�https://blog.csdn.net/Baifeili/article/details/121170916��ȫ����
P1025 ���Ļ��֡� 
*/

//��������ʹ��dfs��������Ϊ����С��Ҳ����ֱ��10��forloop
//dfs��1��10��ok��
/*
��ʼ˼·����
����Ŀ�е��ֵ����Ի�
�������ֻ�����η֡� 
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
 
 
 
 
 
 
 
 
 
 
