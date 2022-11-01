/*
爆难题：
思路： https://blog.csdn.net/AC__dream 
对于 i-j区间，不可能存在i，j已经关了，中间还有灯没关的。 
难点： 
1、在耗费功率的表示上：（总的功率-已经灭掉的功率）*当前动态转移所需时间
	使用 前缀和表示灯的功率。
2、初始化上：这个只能表示就是 f[pos][pos][0]=f[pos][pos][1]=0;
	因为题目中说了就是第一件事是关掉自己位置的灯，然后去关其他的，
	这说明了：当len为2时，有结果的一定是从pos过来的，其他不包括pos的是不算的，因为
	老头一定是先关自己位置的灯。 
*/


#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=53;
ll f[N][N][2];//f[i][j][0/1]表示i~j的灯已关闭且当前位置在i/j的时候最少的功耗
ll a[N],sum[N];//sum[i]表示前i个灯1s的功耗 
int main()
{
	int n,pos;
	cin>>n>>pos;
	memset(f,0x3f,sizeof f);
	f[pos][pos][0]=f[pos][pos][1]=0;
	for(int i=1;i<=n;i++)
		scanf("%lld%lld",&a[i],&sum[i]),sum[i]+=sum[i-1];
	for(int len=2;len<=n;len++)
	for(int i=1;i+len-1<=n;i++)
	{
		int j=i+len-1;
		for(int k=i;k<=j;k++)
		{
			f[i][j][0]=min(f[i][j][0],f[k][j][0]+(a[k]-a[i])*(sum[n]-(sum[j]-sum[k-1])));//当前位置在k且向i走
			f[i][j][0]=min(f[i][j][0],f[k][j][1]+(a[j]-a[i])*(sum[n]-(sum[j]-sum[k-1])));//当前位置在j且向i走
			f[i][j][1]=min(f[i][j][1],f[i][k][0]+(a[j]-a[i])*(sum[n]-(sum[k]-sum[i-1])));//当前位置在i且向j走
			f[i][j][1]=min(f[i][j][1],f[i][k][1]+(a[j]-a[k])*(sum[n]-(sum[k]-sum[i-1])));//当前位置在k且向j走
		}
	}
		for(int i =1;i<=n;i++){
		cout<<f[i][i][0]<<f[i][i][1]<<endl;
	} 
	printf("%lld",min(f[1][n][0],f[1][n][1])); 
	return 0;
}
