#include <cstdio>
 
const int N = 100000;
const int M = 10007;
int n, m;
int sum[N + 1][2], nt[N + 1][2];
int color[N + 1], number[N + 1];
long long ans = 0;
 
int main()
{
    scanf(" %d %d", &n, &m);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &number[i]);
        number[i] %= M;
    }
    for(int i = 1; i <= n; i++) {
        scanf("%d", &color[i]);
        int c = color[i];
        int g = i % 2;
        nt[c][g]++;
        sum[c][g] += number[i];
        sum[c][g] %= M;
    }
    for(int i = 1; i <= n; i++) {
        int c = color[i];
        int g = i % 2;
        ans += i % M * ((sum[c][g] + (nt[c][g] - 2) % M * number[i] + M) % M);
        ans %= M;
    }
    printf("%lld", ans);
    return 0;
}
