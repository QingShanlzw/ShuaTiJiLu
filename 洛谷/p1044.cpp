/*
����������
https://blog.csdn.net/chenlong_cxy/article/details/113613203
 
 ���⣺https://blog.csdn.net/qq_46371399/article/details/125108272
 dp�Ϳ������������ԡ� 
*/

#include<bits/stdc++.h>
using namespace std;
const int N =25;
typedef long long ll;
ll res[N];
int n;
int main(){
	cin>>n;
	res[0] =res[1] =1;
	for(int i =2;i<=n;i++)
		for(int j =0;j<i;j++)
			res[i]+=(res[j]*res[i-1-j]);
	cout<<res[n];		
	return 0;
}

//dfs������
/*
ģ��f[i,j](��ʾջ����j�����ȴ����л�ʣi���ķ�����)��
�ؼ����ڣ�fijֻ����fi-1j+1��+f0j-1�������еķ�����������i==0ʱfox==1ת�����ġ�
#include<cstdio>
#define MAX_N 20
#define ll long long
using namespace std;
int n;
ll f[MAX_N][MAX_N];
ll dfs(int i,int j)
{
//   if f[i][j]>0
	if(f[i][j]) return f[i][j]; 
	if(i==0)return 1; //�߽� 
	if(j>0) f[i][j]+=dfs(i,j-1);
	f[i][j]+=dfs(i-1,j+1);
	return f[i][j];
}
int main()
{
	scanf("%d",&n);
	printf("%lld",dfs(n,0));
	return 0;
}

*/

 //dp:
















