// n<=120��������n^4�ı�����
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 125;
int n; //�߳�
int mp[maxn][maxn]; //��¼���εĶ�άǰ׺��
 
signed main(){
    cin >> n;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin >> mp[i][j];
            mp[i][j] += (mp[i-1][j]+mp[i][j-1]-mp[i-1][j-1]); //�����άǰ׺��
        }
    }
 
    int ans = -(1<<30);
 
    //ö�����ϽǺ����½�����
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
