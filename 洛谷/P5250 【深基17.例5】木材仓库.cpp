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
            set<int>::iterator k = S.lower_bound(b);        // k �ڴ˿��ܵ��� S.end()������ɾ�� S.end()��������ֱ��ɾ�� k����ת��Ϊ u
            set<int>::iterator u = k;
            if (u != S.begin()) u -- ;                      // u һ����Ϊ S.end()����Ϊ�ڴ˼��ϲ�Ϊ�գ�������һ��ֵ����Ϊ begin() ��ʱ������� k
            if (k != S.end() && *k - b < b - *u) u = k;     // �ڴ˲���дΪ *k - b > b - *u) k = u; ��Ϊһ��ʼ���� k==S.end() ���ֱ�� erase ��ʱ�����
            printf("%d\n", *u);
            S.erase(u);
        } 
    }
    return 0;
}

