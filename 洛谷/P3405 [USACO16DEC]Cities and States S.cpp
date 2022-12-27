#include <bits/stdc++.h>

using namespace std;
int n;
string a, b;
int ans; //极限值是20000*20000=400000000,是不会爆int的
unordered_map<string, int> _map;

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a >> b;
        //如果反过来掉过去都一样，就不用计算
        string a1 = a.substr(0, 2), b1 = b.substr(0, 2);
        if (a1 != b1) {
            _map[a1 + b1]++;
            ans += _map[b1 + a1];
        }
    }
    //输出结果
    cout << ans << endl;
    return 0;
}

