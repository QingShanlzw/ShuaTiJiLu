/*
˼·��
1������һ������ abcֱ�� �� abc �ı���ȥ���ǲ�������123456789�ͺ���
������ ��123456789����dfs�ķ���һ��һ��ȥ�ݹ顣
��ȻҲ���԰���������ȫ���п������������ʹ��c++���ṩ��һ��������
next_permutation���������ͨ�õ�ģ�壺https://blog.csdn.net/qq_43488547/article/details/100032724
 do  
    {  
        cout<<num[0]<<" "<<num[1]<<" "<<num[2]<<endl;  
    }while(next_permutation(num,num+3));  
2����Ŀ����abc ���ܲ������ ����   123  ������ 10 20 30 �ȵȣ�
��Ҫ����һ����������һ���������� 
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
