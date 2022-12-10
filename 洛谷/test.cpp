#include<iostream>
using namespace std;

class A{
public:
	A(int m){
		x = m;
		y =m;
	}
	int x;
	int y;
		
};

int main(){
	A aa(5);
	cout<<aa.x;
	return 0;
}
