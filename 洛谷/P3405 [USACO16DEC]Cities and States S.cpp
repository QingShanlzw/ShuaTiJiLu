#include <bits/stdc++.h>

using namespace std;
int n;
string a, b;
int ans; //����ֵ��20000*20000=400000000,�ǲ��ᱬint��
unordered_map<string, int> _map;

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a >> b;
        //�������������ȥ��һ�����Ͳ��ü���
        string a1 = a.substr(0, 2), b1 = b.substr(0, 2);
        if (a1 != b1) {
            _map[a1 + b1]++;
            ans += _map[b1 + a1];
        }
    }
    //������
    cout << ans << endl;
    return 0;
}

