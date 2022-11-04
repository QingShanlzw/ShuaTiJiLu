/*
4 50 
10 60  6
20 100  5
30 120   4
15 45   3
60 + 100 +  80
*/
/*
坑点：
注意物体的性价比要有double，
还有就是res是小数点后两位： printf("%.2f",res);
*/
#include<bits/stdc++.h>
using namespace std;
const int N = 150;
int n,t;
double res;
struct node{
	int weight;
	int value;
	double k;
} coin[N];

bool myfun(node x,node y){
	return x.k>y.k;
}
int main(){
	cin>>n>>t;
	for(int i =0;i<n;i++){
		cin>>coin[i].weight>>coin[i].value;
		coin[i].k  =(double)coin[i].value/coin[i].weight;
	}
	sort(coin,coin+n,myfun);
	for(int i =0;i<n;i++){
		if(t>=coin[i].weight){
			t-=coin[i].weight;
			res+=(coin[i].value);
		}
		else {
			res+=(t*coin[i].k);
			break;
		}
	}
	 printf("%.2f",res);
	return 0;
}

