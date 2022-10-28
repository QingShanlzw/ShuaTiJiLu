#include<bits/stdc++.h>
using namespace std;
 
const int maxn = 50005;
int ans[maxn], tmp[maxn];
 
void multiply(int j){                        //Çó½×³Ë
	for (int i=1; i<=j; i++) {
		int tmpa = 0;
		for (int k=0; k<maxn; k++) {
			tmp[k] = tmp[k]*i + tmpa;
			tmpa = tmp[k] / 10;
			tmp[k] = tmp[k] % 10;
		}
	}
}
 
void add(){                                //ÇóºÍ
	int tmpb=0;
	for (int i=0; i<maxn; i++) {
		tmpb += ans[i] + tmp[i];
		int cur = tmpb % 10;
		tmpb = tmpb / 10;
		ans[i] = cur;
	}
}
 
int main()
{
	int n, m;
	scanf ("%d", &n);
	memset(ans, 0, sizeof(ans));
	for (int i=1; i<=n; i++) {
		memset(tmp, 0, sizeof(tmp));
		tmp[0] = 1;
		multiply(i);
		add();
	}
	for (int i=maxn-1; i>=0; i--) {
		if (ans[i]) {
			m = i;
			break;
		}
	}
	for (int i=m; i>=0; i--) {
		printf ("%d", ans[i]);
	}
    return 0;
}

