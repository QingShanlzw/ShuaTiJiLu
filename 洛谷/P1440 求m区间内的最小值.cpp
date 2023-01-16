#include <iostream>
#include <algorithm>
#include <queue>
#include <cstdio>
using namespace std;

const int maxn = 2e6 + 10;
int id[maxn];
int data[maxn];
int a[maxn];
int head, tail;
int n, m;

int main() {
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++)	scanf("%d", &a[i]);
	for(int i = 1; i <= n; i++) {
		while(head < tail && id[head] < i - m)	head++;
		//head == tail ? cout << 0 << endl : cout << data[head] << endl;
		printf("%d\n", data[head]);
		while(head < tail && data[tail - 1] > a[i])	tail--;
		data[tail] = a[i];
		id[tail] = i;
		tail++;
	}
	return 0;
}

