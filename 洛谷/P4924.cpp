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
void init() {//初始化
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
一. 记住图像旋转坐标变换公式就好了，如下（具体推导可以自己搜一下）：
	1.点(x,y)绕原点逆时针旋转α得到(x',y')的公式
		x'=xcosα-ysinα
		y'=xsinα+ycosα
	2.顺时针旋转α,即逆时针旋转 -α, 用-α代替上面的α, 并根据公式cos(-α)=cosα,sin(-α)=-sinα得
		x'=xcosα+ysinα
		y'=-xsinα+ycosα
	3.旋转中心为(a,b),在利用上面的公式时,需要把(a,b)沿向量(-a,-b)移动到原点,此时(x,y)变成(x-a,y-b),(x',y')变成(x'-a,y'-b),最后得
		//逆时针情况下
		x'=(x-a)cosα-(y-b)sinα+a
		y'=(x-a)sinα+(y-b)cosα+b
		// 顺时针情况下
		x'=(x-a)cosα+(y-b)sinα+a
		y'=-(x-a)sinα+(y-b)cosα+b
二.需要用到一个辅助数组，暂存一下旋转后的结果，然后再存回原数组即可。

*/
