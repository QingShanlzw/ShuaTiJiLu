#include<bits/stdc++.h>
using namespace std;
const int N=35;
int f[N][N];
int s[N][N];//��¼ÿ���������ѵķָ��
int w[N];
int n;
void dfs(int l,int r)//���ǰ�����
{
    if(l>r) return;//����
    cout<<s[l][r]<<" ";
    dfs(l,s[l][r]-1);
    dfs(s[l][r]+1,r);
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++) cin>>w[i];
    for(int len=1;len<=n;len++)//���䳤�ȴ�1->n
    for(int i=1;i+len-1<=n;i++)//i����ʼ�ĵ�
    {
        int j=i+len-1;//����ĩ
        if(len==1) f[i][j]=w[i],s[i][j]=i;
        else{
            for(int k=i;k<=j;k++)
            {
                int left = k== i ? 1 : f[i][k-1];
                int right=k==j ? 1: f[k+1][j];
                int score=left*right+w[k];
                if(score>f[i][j]) f[i][j]=score,s[i][j]=k;//����
            }
        }
    }
    cout<<f[1][n]<<endl;
    dfs(1,n);
    
    

}

