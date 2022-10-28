//#define LOCAL
#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
#include <cctype>
#include <sstream>
#define inf 0x3f3f3f3f
#define eps 1e-6
using namespace std;
#define clr(x) memset(x,0,sizeof((x)))
const int maxn = 10000;
#define MAX(a,b,c) ((a)>(b)?((a)>(c)?(a):(c)):((b)>(c)?(b):(c)))
#define _max(a,b) ((a) > (b) ? (a) : (b))
#define _min(a,b) ((a) < (b) ? (a) : (b))
#define _for(a,b,c) for(int a = b;a<c;a++)
typedef int itn;
int matrix[501][501],ans[501][501];
int n,m;
void init() {//��ʼ��
	int cnt = 1;
	for(int i = 1;i<=n;i++) {
		for(int j = 1;j<=n;j++) {
			matrix[i][j] = cnt++;
			ans[i][j] = matrix[i][j];
		}
	}
}
void magic(int x,int y,int r,int z) {
	int t = 2*r+1;
	int mov = t/2;
	if(z==1) {
		for(int i = x-mov;i<x-mov+t;i++) {
			for(int j=y-mov;j<y-mov+t;j++) {
				ans[-j+y+x][i-x+y] = matrix[i][j];
			}
		}
		for(int i = x-mov;i<x-mov+t;i++) {
			for(int j=y-mov;j<y-mov+t;j++) {
				matrix[i][j] = ans[i][j];
			}
		}


	}
	else {
		for(int i = x-mov;i<x-mov+t;i++) {
			for(int j=y-mov;j<y-mov+t;j++) {
				ans[j-y+x][x-i+y] = matrix[i][j];
			}
		}
		for(int i = x-mov;i<x-mov+t;i++) {
			for(int j=y-mov;j<y-mov+t;j++) {
				matrix[i][j] = ans[i][j];
			}
		}
	}
	

}

int main()
{
#ifdef LOCAL 
	freopen("data.in","r",stdin);
	freopen("data.out","w",stdout);
#endif
	cin>>n>>m;
	int x,y,r,z;
	init();
	for(int i = 0;i<m;i++) {
		cin>>x>>y>>r>>z;
		magic(x,y,r,z);
	}

	for(int i = 1;i<=n;i++) {
		for(int j = 1;j<=n;j++) {
			cout<<ans[i][j]<<" ";
		}
		cout<<endl;
	}
    return 0;
}


/*
һ. ��סͼ����ת����任��ʽ�ͺ��ˣ����£������Ƶ������Լ���һ�£���
	1.��(x,y)��ԭ����ʱ����ת���õ�(x',y')�Ĺ�ʽ
		x'=xcos��-ysin��
		y'=xsin��+ycos��
	2.˳ʱ����ת��,����ʱ����ת -��, ��-����������Ħ�, �����ݹ�ʽcos(-��)=cos��,sin(-��)=-sin����
		x'=xcos��+ysin��
		y'=-xsin��+ycos��
	3.��ת����Ϊ(a,b),����������Ĺ�ʽʱ,��Ҫ��(a,b)������(-a,-b)�ƶ���ԭ��,��ʱ(x,y)���(x-a,y-b),(x',y')���(x'-a,y'-b),����
		//��ʱ�������
		x'=(x-a)cos��-(y-b)sin��+a
		y'=(x-a)sin��+(y-b)cos��+b
		// ˳ʱ�������
		x'=(x-a)cos��+(y-b)sin��+a
		y'=-(x-a)sin��+(y-b)cos��+b
��.��Ҫ�õ�һ���������飬�ݴ�һ����ת��Ľ����Ȼ���ٴ��ԭ���鼴�ɡ�

*/
