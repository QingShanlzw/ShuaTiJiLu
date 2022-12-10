//easy:https://www.acwing.com/problem/content/4725/
//4722. 数列元素
#include<bits/stdc++.h>
using namespace std;
int n;
int main(){
    cin>>n;
    int i =0,temp=0;
    while(n>temp){
        temp+=(++i);
        //cout<<temp;
        if(n==temp){cout<<"YES";return 0;}
        if(temp>n) {cout<<"NO";return 0;}
    }
    return 0;
}


//mid:https://www.acwing.com/problem/content/4726/
//4723. 队列
#include<bits/stdc++.h>
using namespace std;
int n;
char s[6];
int main(){
    s[1] ='a',s[2]='b',s[3]='c',s[4]='d',s[5]='e',
    cin>>n;
    int t =1,cnt=5;
    while(n>cnt){
        t++;
        n-=cnt;
        cnt*=2;
    }
    t =  pow(2,t-1);
    int res =1;
    while(1){
        if(n<=t)break;
        n-=t;
        res++;
    }
    cout<<s[res];
    return 0;
}

//hard:https://www.acwing.com/problem/content/4727/
//4724. 靓号
