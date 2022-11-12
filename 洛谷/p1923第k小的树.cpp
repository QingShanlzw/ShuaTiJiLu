/*
int mid =  a[ l + r >> 1];
1、为什么不可以使用  a[k]==mid来判断？
因为如果数组中多个一样的元素，会有问题。
比如：[0,0,1,2,4,2,2,3,1,4]
 2、yxc的板子 
 问题在于双指针的右指针不能确定是在mid位置还是mid的左侧。
 下面这个板子保证一定j在mid的左侧。 
*/
//
//#include<bits/stdc++.h>
//#define ll long long
//using namespace std;
//int m,k;
//int a[5000005];
//void qsort(int l,int r)
//{
//	int i=l,j=r,mid=a[(l+r)/2];//注意mid的写法 
//	while(i<=j)
//	{
//		while(a[i]<mid)
//		i++;
//		while(a[j]>mid)
//		j--;
//		if(i<=j)//原来写成a[i]  a[j]的关系了 
//		{
//			swap(a[i],a[j]);
//			i++;
//			j--;
//		}
//	}
//	if(k<=j)
//	qsort(l,j);
//	else if(k>=i)
//	qsort(i,r);
//	else
//	{
//		printf("%d",a[j+1]);
//		exit(0);
//	}
//	
//}
//int main()
//{
//	cin>>m>>k;
//	for(int i=0;i<m;i++)
//	{
//		scanf("%d",&a[i]);
//	}
//	qsort(0,m-1);
//	return 0;
//}


//后续：y总模板：


#include<iostream>
using namespace std;
const int N = 1e6+7;
int a[N];
int n,k;
 int qsort(int l,int r,int k){
 	if(l>=r)return a[l];
 	int i = l-1;
 	int j  = r+1;
 	int mid  = a[l + r >> 1];
 	while(i<j){
 		do i++;while(a[i]<mid);
 		do j--;while(a[j]>mid);
 		if(i<j)swap(a[i],a[j]);
	 }
	 int len = j-l+1;
	 if()
 }
int main(){
	cin>>n>>k;
	for(int i =0;i<n;i++)cin>>a[i];
	return 0;
} 
