// https://www.luogu.com.cn/problem/P5250

#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

int n;
set<int> S;

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i ++ ) {
        int a, b;
        scanf("%d%d", &a, &b);
        if (a == 1) {
            if (S.find(b) != S.end()) printf("Already Exist\n");
            else S.insert(b);
        }
        else if (S.empty()) printf("Empty\n");
        else {
            set<int>::iterator k = S.lower_bound(b);        // k 在此可能等于 S.end()，不能删除 S.end()，即不能直接删除 k，得转化为 u
            set<int>::iterator u = k;
            if (u != S.begin()) u -- ;                      // u 一定不为 S.end()，因为在此集合不为空，至少有一个值，当为 begin() 的时候其等于 k
            if (k != S.end() && *k - b < b - *u) u = k;     // 在此不能写为 *k - b > b - *u) k = u; 因为一开始可能 k==S.end() 最后直接 erase 的时候出错
            printf("%d\n", *u);
            S.erase(u);
        } 
    }
    return 0;
}

