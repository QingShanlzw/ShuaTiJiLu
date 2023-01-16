// n<=120，可以用n^4的暴力法
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 125;
int n; //边长
int mp[maxn][maxn]; //记录矩形的二维前缀和
 
signed main(){
    cin >> n;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin >> mp[i][j];
            mp[i][j] += (mp[i-1][j]+mp[i][j-1]-mp[i-1][j-1]); //计算二维前缀和
        }
    }
 
    int ans = -(1<<30);
 
    //枚举左上角和右下角坐标
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            for(int x=i; x<=n; x++){
                for(int y=j; y<=n; y++){
                    ans = max(ans, mp[x][y]-mp[i-1][y]-mp[x][j-1]+mp[i-1][j-1]);
                }
            }
        }
    }
    cout << ans << '\n';
}
