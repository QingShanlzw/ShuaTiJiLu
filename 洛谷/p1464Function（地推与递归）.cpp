#include<bits/stdc++.h>
using namespace std;
long long int n[1000005];
int ans;
long long f[25][25][25]={0};
int w(int a,int b,int c)
{
if(a<=0||b<=0||c<=0)
{
    return 1;
}
 
else if(a>20||b>20||c>20)
{
	return w(20,20,20);
}
else if(f[a][b][c]!=0)
{
	return f[a][b][c];
}
else if(a<b&&b<c)
{
	return f[a][b][c]=w(a,b,c-1)+w(a,b-1,c-1)-w(a,b-1,c);
}
else
{
	return f[a][b][c]=w(a-1,b,c)+w(a-1,b-1,c)+w(a-1,b,c-1)-w(a-1,b-1,c-1);
}
}
int main()
{
	int i,j;
	for(i=1;;i++)
	{
		cin>>n[i];
		if(n[i]==n[i-1]&&n[i]==n[i-2]&&n[i]==-1)
		break;
	}
	for(j=1;j<=i-3;j+=3)
	{
		ans=w(n[j],n[j+1],n[j+2]);
		printf("w(%d, %d, %d) = %d\n" ,n[j],n[j+1],n[j+2],ans);
	}
	
	
}
