/*
�����⣺
˼·�� https://blog.csdn.net/AC__dream 
���� i-j���䣬�����ܴ���i��j�Ѿ����ˣ��м仹�е�û�صġ� 
�ѵ㣺 
1���ںķѹ��ʵı�ʾ�ϣ����ܵĹ���-�Ѿ�����Ĺ��ʣ�*��ǰ��̬ת������ʱ��
	ʹ�� ǰ׺�ͱ�ʾ�ƵĹ��ʡ�
2����ʼ���ϣ����ֻ�ܱ�ʾ���� f[pos][pos][0]=f[pos][pos][1]=0;
	��Ϊ��Ŀ��˵�˾��ǵ�һ�����ǹص��Լ�λ�õĵƣ�Ȼ��ȥ�������ģ�
	��˵���ˣ���lenΪ2ʱ���н����һ���Ǵ�pos�����ģ�����������pos���ǲ���ģ���Ϊ
	��ͷһ�����ȹ��Լ�λ�õĵơ� 
*/


#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=53;
ll f[N][N][2];//f[i][j][0/1]��ʾi~j�ĵ��ѹر��ҵ�ǰλ����i/j��ʱ�����ٵĹ���
ll a[N],sum[N];//sum[i]��ʾǰi����1s�Ĺ��� 
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
			f[i][j][0]=min(f[i][j][0],f[k][j][0]+(a[k]-a[i])*(sum[n]-(sum[j]-sum[k-1])));//��ǰλ����k����i��
			f[i][j][0]=min(f[i][j][0],f[k][j][1]+(a[j]-a[i])*(sum[n]-(sum[j]-sum[k-1])));//��ǰλ����j����i��
			f[i][j][1]=min(f[i][j][1],f[i][k][0]+(a[j]-a[i])*(sum[n]-(sum[k]-sum[i-1])));//��ǰλ����i����j��
			f[i][j][1]=min(f[i][j][1],f[i][k][1]+(a[j]-a[k])*(sum[n]-(sum[k]-sum[i-1])));//��ǰλ����k����j��
		}
	}
		for(int i =1;i<=n;i++){
		cout<<f[i][i][0]<<f[i][i][1]<<endl;
	} 
	printf("%lld",min(f[1][n][0],f[1][n][1])); 
	return 0;
}
