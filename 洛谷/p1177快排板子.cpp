#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+7;
int a[N];
int n;

void quickSort(int i,int j){
	if(i>=j)return;
	int l = i-1;
	int r = j+1;
	int mid = a[(l+r)>>1];
	while(l<r){
		do l++;while(a[l]<mid);
		do r--;while(a[r]>mid);
		if(l<r)swap(a[l],a[r]);
	}
	quickSort(i,r);
	quickSort(r+1,j);
}
int main(){
	cin>>n;
	for(int i =0;i<n;i++)cin>>a[i];
	quickSort(0,n-1);
	for(int i =0;i<n;i++)cout<<a[i]<<' ';
	return 0;
}
