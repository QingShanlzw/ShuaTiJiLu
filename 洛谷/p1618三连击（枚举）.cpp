/*
思路：
1、给定一个倍数 abc直接 用 abc 的倍数去看是不是满足123456789就好了
而不是 把123456789按照dfs的方法一点一点去递归。
当然也可以把所有数字全排列开来，这里可以使用c++的提供的一个函数：
next_permutation这个函数有通用的模板：https://blog.csdn.net/qq_43488547/article/details/100032724
 do  
    {  
        cout<<num[0]<<" "<<num[1]<<" "<<num[2]<<endl;  
    }while(next_permutation(num,num+3));  
2、题目给的abc 可能不是最简， 比如   123  给的是 10 20 30 等等，
需要先求一下三个数的一个最简比例。 
*/
#include<bits/stdc++.h>
using namespace std;
int A ,B ,C, res;
int gcd(int a,int b){
	int c;
	while(a%b){
		c = a%b;
		a = b;
		b =c;
	}
	return b;
}
int but[10];
int f;
void ff(int x){
	while(x){
		but[x%10]++;
		x/=10;
	}
}
int main(){	
	cin>>A>>B>>C;
	int k = gcd(gcd(A,B),gcd(B,C));
	A = A/k;
	B =B/k;
	C = C/k;
	for(int i  =1;i<1000;i++){
		int a = A*i;
		int b = B*i;
		int c = C*i;
		f = 0;
		memset(but,0,sizeof but);
		if(c>=1000)break;
		ff(a);
		ff(b);
		ff(c);
		for(int i = 1;i<=9;i++){
			if(but[i]!=1){
				f =1;
			}
		}
		if(f!=99){
			cout<<a<<' '<<b<<' '<<c<<endl;
			res++;
			f = 0;
		}else f = 0;
	}
	if(!res)cout<<"NO!!!";
	return 0;
}
