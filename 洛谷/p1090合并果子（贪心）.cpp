//���ȼ����� 
//priority_queue<int,vector<int>,greater<int>>q��ʾ��С����
//priority_queue<int> Ĭ��Ϊ�Ӵ�С 
//��ʯ�Ӻϲ���һ�����ǣ�
//ʯ�Ӻϲ�������dp���ϲ��겻���Զ�
//���⣺���ȼ����У��ϲ�����Զ��� 
#include<bits/stdc++.h>
using namespace std;
int n;
int res;
int x;
priority_queue<int,vector<int>,greater<int>>q;
int main(){
	cin>>n;
	while(n--)cin>>x,q.push(x);
	while(q.size()>1){
		int a = q.top();q.pop();
		int b = q.top();q.pop();
		res+= (a+b);
		q.push(a+b);
	}
	cout<<res;
	return 0;
}
