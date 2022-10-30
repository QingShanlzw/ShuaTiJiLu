#include <iostream>
#include <vector>
using namespace std;

const int N = 1e4 + 10;
int n, k;
vector<int> v[N];
int f[N];

int main() {
	cin>>n>>k;
	for(int i =1;i<=k;i++){
		int a,b;
		cin>>a>>b;
		v[a].push_back(b);
	}
	for(int i =n;i>=1;i--)
		if(v[i].size())
			for(int j =0;j<v[i].size();j++)
				f[i] =max(f[i],f[i+v[i][j]]);
		else f[i] =f[i+1]+1;
	cout<<f[1];			
	return 0;
}

