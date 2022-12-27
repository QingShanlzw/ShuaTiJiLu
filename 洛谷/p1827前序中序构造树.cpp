#include<string>
#include<iostream>
#include <algorithm>
using namespace std;
string x,y;
//n到m为先序遍历，l，r为中序遍历
void HX(int n,int m,int l,int r){
    if(n>m||l>r){
    return;}
    else{
       int i=y.find(x[n]);//找到根节点所在之处
       HX(n+1,n+i-l,l,i-1);//找到根节点，递归遍历左子树
       HX(n+i-l+1,m,i+1,r);//递归右子树
       cout<<x[n];
    }
}
int main(){
    cin>>y>>x;//先输入
    int len=y.length()-1;//左结点开始为0
    HX(0,len,0,len);
}
