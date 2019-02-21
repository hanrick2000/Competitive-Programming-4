#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
struct Edge { int v; LL w; };
const LL INF = 0x3f3f3f3f3f3f3f3fLL;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m, Q, s; while (cin >> n >> m >> Q >> s && n) {
        vector<vector<Edge> > G(n);
        while (m--) {
            int u, v; LL w;
            cin >> u >> v >> w;
            G[u].push_back({v, w});
        }
        deque<int> q; q.push_back(s);
        vector<LL> d(n, INF); d[s] = 0;
        vector<int> updateTime(n, 0);
        vector<bool> inq(n, false); inq[s] = true;
        while (q.size()) {
            int u;
            if (d[q.front()] < d[q.back()])
                u = q.front(), q.pop_front();
            else
                u = q.back(), q.pop_back();
            inq[u] = false;
            if (updateTime[u] >= n)
                d[u] = -INF;
            for (auto &e : G[u]) {
                if (d[e.v] == -INF)
                    continue;
                if (d[u] == -INF)
                    d[e.v] = -INF, q.push_back(e.v);
                else if (d[u] + e.w < d[e.v]) {
                    d[e.v] = d[u] + e.w;
                    updateTime[e.v]++;
                    if (inq[e.v])
                        continue;
                    q.push_back(e.v);
                    inq[e.v] = true;
                }
            }
        }
        while (Q--) {
            int u; cin >> u;
            if (d[u] == -INF)
                cout << "-Infinity\n";
            else if (d[u] == INF)
                cout << "Impossible\n";
            else
                cout << d[u] << '\n';
        }
        cout << '\n';
    }
}
