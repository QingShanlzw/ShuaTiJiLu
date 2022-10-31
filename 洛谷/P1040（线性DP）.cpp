#include<bits/stdc++.h>
using namespace std;
const int N=35;
int f[N][N];
int s[N][N];//记录每个区间的最佳的分割点
int w[N];
int n;
void dfs(int l,int r)//输出前序遍历
{
    if(l>r) return;//树空
    cout<<s[l][r]<<" ";
    dfs(l,s[l][r]-1);
    dfs(s[l][r]+1,r);
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++) cin>>w[i];
    for(int len=1;len<=n;len++)//区间长度从1->n
    for(int i=1;i+len-1<=n;i++)//i是起始的点
    {
        int j=i+len-1;//区间末
        if(len==1) f[i][j]=w[i],s[i][j]=i;
        else{
            for(int k=i;k<=j;k++)
            {
                int left = k== i ? 1 : f[i][k-1];
                int right=k==j ? 1: f[k+1][j];
                int score=left*right+w[k];
                if(score>f[i][j]) f[i][j]=score,s[i][j]=k;//更新
            }
        }
    }
    cout<<f[1][n]<<endl;
    dfs(1,n);
    
    

}

