#include<string>
#include<iostream>
#include <algorithm>
using namespace std;
string x,y;
//n��mΪ���������l��rΪ�������
void HX(int n,int m,int l,int r){
    if(n>m||l>r){
    return;}
    else{
       int i=y.find(x[n]);//�ҵ����ڵ�����֮��
       HX(n+1,n+i-l,l,i-1);//�ҵ����ڵ㣬�ݹ����������
       HX(n+i-l+1,m,i+1,r);//�ݹ�������
       cout<<x[n];
    }
}
int main(){
    cin>>y>>x;//������
    int len=y.length()-1;//���㿪ʼΪ0
    HX(0,len,0,len);
}
