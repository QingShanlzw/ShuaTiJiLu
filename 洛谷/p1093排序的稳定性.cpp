/*
�����Ƕ��ȶ�����Ͷ���������
���ķ����ǵ��Ű���������������
����ķ����ǿ���ʹ��sort+�Զ�������� 
*/
#include<bits/stdc++.h>
using namespace std;
const int  N  =307;
struct ss{
	int a;
	int allin;
	int num;
}s[N];
int n;

bool cmp(ss a,ss b){
	if(a.allin!=b.allin)return a.allin>b.allin;
	else 
		if(a.a!=b.a)return a.a>b.a;
		else return a.num<b.num;
} 
int main(){
	cin>>n;
	for(int i =1;i<=n;i++){
		int a,b,c;
		cin>>a>>b>>c;
		s[i].a =a;
		s[i].allin = (a+b+c);
		s[i].num = i;
	}
	sort(s+1,s+1+n,cmp);
	for(int i =1;i<=5;i++)cout<<s[i].num<<' '<<s[i].allin<<endl;
	return 0;
}
