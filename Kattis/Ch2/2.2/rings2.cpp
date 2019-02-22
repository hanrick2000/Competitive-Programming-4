#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef pair<int, int> pii;
const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m; cin >> n >> m;
    vector<vector<char> > G(n + 2, vector<char>(m + 2, '.'));
    vector<vector<int> > d(n + 2, vector<int>(m + 2, 0));
    for (int i = 1 ; i <= n ; i++) {
        for (int j = 1 ; j <= m ; j++) {
            cin >> G[i][j];
            if (G[i][j] == 'T')
                d[i][j] = -1;
        }
    }
    int cnt = 0;
    while (1) {
        bool ok = true; cnt++;
        vector<vector<bool> > vis(n + 2, vector<bool>(m + 2, false));
        for (int i = 0 ; i < n + 2 ; i++) {
            for (int j = 0 ; j < m + 2 ; j++) {
                if (vis[i][j] || G[i][j] != '.') continue;
                vis[i][j] = true;
                queue<pii> q; q.push({i, j});
                while (q.size()) {
                    pii u = q.front(); q.pop();
                    for (int x = 0 ; x < 4 ; x++) {
                        pii v = {u.F + dx[x], u.S + dy[x]};
                        if (v.F < 0 || v.F >= n + 2 || v.S < 0 || v.S >= m + 2)
                            continue;
                        if (vis[v.F][v.S])
                            continue;
                        vis[v.F][v.S] = true;
                        if (d[v.F][v.S] == -1) {
                            d[v.F][v.S] = cnt;
                            ok = false;
                        } else q.push(v);
                    }
                }
            }
        }
        if (ok) break;
    }
    for (int i = 1 ; i <= n ; i++) {
        for (int j = 1 ; j <= m ; j++)
            if (d[i][j] == 0)
                cout << setw(cnt < 10 ? 2 : 3) << setfill('.') << '.';
            else
                cout << setw(cnt < 10 ? 2 : 3) << setfill('.') << d[i][j];
        cout << '\n';
    }
}
