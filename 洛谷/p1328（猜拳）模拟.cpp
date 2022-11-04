#include<bits/stdc++.h>
using namespace std;
int n , a , b , arr[205] , brr[205] , x , y;
int main(){
	scanf("%d %d %d" , &n , &a , &b);
	for(int i = 0 ; i < a ; i++) cin >> arr[i];
	for(int i = 0 ; i < b ; i++) cin >> brr[i];
	for(int i = 0 ; i < n ; i++){
		if(arr[i % a] == 0 && brr[i % b] == 2 ||
		   arr[i % a] == 0 && brr[i % b] == 3 ||
		   arr[i % a] == 1 && brr[i % b] == 0 ||
		   arr[i % a] == 1 && brr[i % b] == 3 ||
		   arr[i % a] == 2 && brr[i % b] == 1 ||
		   arr[i % a] == 2 && brr[i % b] == 4 ||
		   arr[i % a] == 3 && brr[i % b] == 2 ||
		   arr[i % a] == 3 && brr[i % b] == 4 ||
		   arr[i % a] == 4 && brr[i % b] == 0 ||
		   arr[i % a] == 4 && brr[i % b] == 1)
		   x++;
		else if(arr[i % a] == brr[i % b]) continue;
		else y++; 
	} 
	cout << x << " " << y;
	return 0;
} 
