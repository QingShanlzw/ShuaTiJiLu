#include <bits/stdc++.h>
 
using namespace std;
 
stack<int> num;
 
char ch;
int sum, x, y;
 
int main(){
    while((ch = getchar()) != '@'){
        switch(ch){
            case '+':{
				x = num.top();
				num.pop();
				y = num.top();
				num.pop();
				num.push(x + y);
				break;
			}
            case '-':{
				y = num.top();
				num.pop();
				x = num.top();
				num.pop();
				num.push(x - y);
				break;
			}
            case '*':{
				x = num.top();
				num.pop();
				y = num.top();
				num.pop();
				num.push(x * y);
				break;
			}
            case '/':{
				y = num.top();
				num.pop();
				x = num.top();
				num.pop();
				num.push(x / y);
				break;
			}
            case '.':{
				num.push(sum);
				sum = 0;
				break;
			}
            default:{
				sum = sum * 10 + ch - '0';
				break;
			}
        }
    }
    printf("%d", num.top());
    return 0;
}
