//����dp�ľ�����forѭ����len��С����Ϊ������
//�Ȱ�С����ģ���꣬��ȥ�Ҵ����䡣 
#include<bits/stdc++.h>
using namespace std;
const int N  =307;
int s[N];
int f[N][N];
int n; 
int main(){
	cin>>n;
	for(int i = 1;i<=n;i++){
		cin>>s[i];
		s[i]+=s[i-1];
	}
	
	for(int len =2;len<=n;len++)
		for(int i =1;i+len-1<=n;i++){
			int l = i,r = i+len-1;
			f[l][r] =1e7;
			for(int k  = i;k<r;k++){
				f[l][r] = min(f[l][r],f[l][k]+f[k+1][r]+s[r]-s[l]);
			}
		}
	cout<<f[1][n];	
	return 0;
}
