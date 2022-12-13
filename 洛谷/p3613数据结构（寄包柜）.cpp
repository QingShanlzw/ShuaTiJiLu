#include<bits/stdc++.h>
using namespace std;

const int N = 1e5  + 10;

//与下面语句效果一样map<int, map<int ,int>> a
map<int, int> a[N];
int n, m;

int main()
{
    cin >> n >> m;

    int x, i, j, k;
    while(m -- )
    {
        cin >> x;
        if(x == 1)
        {
            cin >> i >> j >> k;
            a[i][j] = k;
        }
        else if(x == 2)
        {
            cin >> i >> j;
            cout << a[i][j] << endl;
        }
    }
    return 0;
}

