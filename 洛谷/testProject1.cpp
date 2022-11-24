#include<bits/stdc++.h>
using namespace std;
class persion
{
    int age;
    unsigned char name [16];
};
int main(){
	persion a;
	persion * a1 =new persion();
	char *c = new char[50];
	char c1[50];
	cout<<sizeof(a)<<' '<<sizeof(a1)<< ' ' << sizeof(persion)<<' '<<endl;
	cout<<sizeof(c)<<' '<<sizeof(c1)<< ' ' << sizeof(char)<< ' ';
}
