#include<bits/stdc++.h>
using namespace std;
double a,b,c,d;
double l ,r,yl,yr;
int cnt;
double f(double x){
	return a*x*x*x+b*x*x+c*x+d;
}
int main(){
	cin>>a>>b>>c>>d;
	for(double  i = -100;i<=100&&cnt<3;i++){
		yl = f(i),yr = f(i+1);
		if(yl==0){
			printf("%.2f ",i);
			cnt++;
		}
		else if(yl*yr<0){
			l = i,r = i+1;
			while(r-l>=0.001){
				double mid = l + (r-l)/2;
				if(f(l)*f(mid)<0)r= mid;
				else l =mid;
			}
			printf("%.2f ",l);cnt++;
		}
	}
	return 0;
}
