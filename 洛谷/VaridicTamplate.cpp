#include<bits/stdc++.h>
using namespace std;
void printX(){
}
template<typename T,typename... Types>
void printX(const T& FirstArg,const Types&... args){
	cout<<FirstArg<<endl;
	printX(args...);
}
int main(){
	printX(1,"nihao",66);
	return 0;
} 

