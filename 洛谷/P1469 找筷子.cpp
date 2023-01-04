#include <iostream>
using namespace std;

int n;

int main() {
    scanf("%d", &n);
    int res = 0;
    for (int i = 1; i <= n; i++) {
        int x;
        scanf("%d", &x);
        res ^= x;
    }

    cout << res << endl;
    return 0;
}

