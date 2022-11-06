#include<bits/stdc++.h>
using namespace std;
int n,k;
const int N = 5e6+7;
int a[N];
int res;

void quickSort(int i,int j){
	if(i>=j)return;
	int l = i-1;
	int r = j+1;
	int mid =  a[ l + r >> 1];
	while(l<r){
		do l++;while(a[l]<mid);
		do r--;while(a[r]>mid);
		if(l<r)swap(a[l],a[r]);
	}
	if(a[k]==mid){
		res = a[k];
		return;
	}
	else if (r<k){
		quickSort(r+1,j);
	}
	else quickSort(i,r);
}
int main(){
	cin>>n>>k;
	for(int i =0;i<n;i++)cin>>a[i];
	quickSort(0,n-1);
	cout<<res;
	return 0;
}
