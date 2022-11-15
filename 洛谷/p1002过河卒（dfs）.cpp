/*
dfs版本：简单但是数据量 比较大，会超时。 
#include<bits/stdc++.h>
using namespace std;
const int N = 30;
int m,n,x,y;
int a[N][N],b[N][N];
int sum;
void dfs(int i,int j){
	if(i>m||j>n||b[i][j])return;
	if(i==m&&j==n){
		sum++;
		return;
	}
	dfs(i+1,j);
	dfs(i,j+1);
}
int main(){
	cin>>m>>n>>x>>y;
	m+=2,n+=2,x+=2,y+=2;
	b[x][y] = 1, b[x + 1][y + 2] = 1, b[x + 2][y + 1] = 1, b[x + 2][y - 1] = 1, b[x + 1][y - 2] = 1, b[x - 1][y - 2] = 1, b[x - 2][y - 1] = 1, b[x - 2][y + 1] = 1,
	b[x - 1][y + 2] = 1;
	dfs(2,2);
	cout<<sum;
	return 0;
}
*/


//dp版，为什么dp版可以：是因为只可以往右，往下走，所以ij点的右边和上边是遍历过的
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int bx,by,mx,my;
    cin>>bx>>by>>mx>>my;
    //加2避免马的影响
    bx+=2; by+=2;
    mx+=2; my+=2;
    //这里一定记得是long long，要不然会WA的！
    long long area[30][30]={0};
    bool ma[30][30]={0};
    int x[]={0,-2,-1,1,2,-2,-1,1,2};
    int y[]={0,1,2,2,1,-1,-2,-2,-1};
    //把马能走的位置设为1，后续方便判断
    for(int i=0;i<9;i++)
    {
        ma[mx+x[i]][my+y[i]] = 1;
    }

    area[2][2] = 1;
    //开始dp
    for(int i=2;i<=bx;i++)
    {
        for(int j=2;j<=by;j++)
        {
            if(ma[i][j]) continue;
            //状态转移方程
            else area[i][j] = max(area[i][j-1] + area[i-1][j],area[i][j]);
        }
    }
    //输出结果
    cout<<area[bx][by];
    return 0;
} 
