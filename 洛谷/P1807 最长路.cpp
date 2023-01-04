//最短路：dijkstra，blemford，flord
//最长路 ： 拓扑（bfs）+dp 

#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

const int N = 1510, M = 5e4 + 10;
int n, m;
int h[N], e[M], ne[M], w[M], idx;
int dist[N], ind[N];
queue<int> q;

void add(int a, int b, int c) {
    e[idx] = b, ne[idx] = h[a], w[idx] = c, h[a] = idx++;
}

void bfs() {
    for (int i = 1; i <= n; i++)
        if (!ind[i]) q.push(i);

    memset(dist, -1, sizeof dist);
    dist[1] = 0;
    while (q.size()) {
        auto v = q.front(); q.pop();
        for (int i = h[v]; ~i; i = ne[i]) {
            int j = e[i];
            if (~dist[v]) dist[j] = max(dist[j], dist[v] + w[i]);
            ind[j]--;
            if (!ind[j]) q.push(j);
        }
    }
}

int main() {
    scanf("%d%d", &n, &m);
    memset(h, -1, sizeof h);
    while (m--) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        add(a, b, c);
        ind[b]++;
    }

    bfs();
    printf("%d\n", dist[n]);

    return 0;
}

