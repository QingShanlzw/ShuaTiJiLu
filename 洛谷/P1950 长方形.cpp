#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<queue>
#include<set>
#include<map>
#include<vector>
#include<iomanip>
#include<ctime>
#include<stack>
using namespace std;
const int maxn=1005;
int n,m,a[maxn],ans[maxn];
long long anss;
int main()
{
    ios::sync_with_stdio(false);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
    	stack<int> s;
    	for(int j=1;j<=m;j++){
    		char c;
    		cin>>c;
    		if(c=='*') a[j]=i;
    		while(!s.empty()&&a[s.top()]<=a[j]) s.pop();
    		if(!s.empty()) ans[j]=ans[s.top()]+(i-a[j])*(j-s.top());
    		else ans[j]=(i-a[j])*j;
    		s.push(j);
    		anss+=ans[j];
		}
	}
	cout<<anss;
    return 0;
}

