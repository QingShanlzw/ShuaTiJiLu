/*
dfs�汾���򵥵��������� �Ƚϴ󣬻ᳬʱ�� 
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


//dp�棬Ϊʲôdp����ԣ�����Ϊֻ�������ң������ߣ�����ij����ұߺ��ϱ��Ǳ�������
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int bx,by,mx,my;
    cin>>bx>>by>>mx>>my;
    //��2�������Ӱ��
    bx+=2; by+=2;
    mx+=2; my+=2;
    //����һ���ǵ���long long��Ҫ��Ȼ��WA�ģ�
    long long area[30][30]={0};
    bool ma[30][30]={0};
    int x[]={0,-2,-1,1,2,-2,-1,1,2};
    int y[]={0,1,2,2,1,-1,-2,-2,-1};
    //�������ߵ�λ����Ϊ1�����������ж�
    for(int i=0;i<9;i++)
    {
        ma[mx+x[i]][my+y[i]] = 1;
    }

    area[2][2] = 1;
    //��ʼdp
    for(int i=2;i<=bx;i++)
    {
        for(int j=2;j<=by;j++)
        {
            if(ma[i][j]) continue;
            //״̬ת�Ʒ���
            else area[i][j] = max(area[i][j-1] + area[i-1][j],area[i][j]);
        }
    }
    //������
    cout<<area[bx][by];
    return 0;
} 
