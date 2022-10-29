#include<bits/stdc++.h>
using namespace std;
const int N =1e5+7;
int a[N],dp[N],f[N];
int res1;
set<int> s;
int main(){
	int k = 0;
	int n=0;
	while(scanf("&d",&a[k])!=EOF){
		k++;
	}
	k+=1;
	cout<<k<<endl;
	//while (scanf("%d", &h[n]) != EOF) n ++;
	memset(a,1,sizeof a);
	memset(f,-1,sizeof f);
	for(int i = 1;i<k;i++){
		f[i] =i;
		for(int j = 0;j<i;j++){
			if(a[i]<=a[j]){
				if(dp[i]<(dp[j]+1)){
					f[i] = f[j];
					dp[i] = dp[j]+1;
				}
			}
		}
		res1 = max(res1,dp[i]);
	}
	cout<<res1;
	for(int i =0;i<k;i++){
		if(!s.count(f[i]))s.insert(f[i]);
	}
	//cout<<endl<<s.size();
	return 0;
}
