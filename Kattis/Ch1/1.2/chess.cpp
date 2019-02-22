#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef pair<int, int> pii;
const int INF = 0x3f3f3f3f;
int dx[] = {1, 1, -1, -1};
int dy[] = {1, -1, 1, -1};
void printPath(pii u, vector<vector<pii> > &pa) {
    if (u == make_pair(-1, -1))
        return ;
    printPath(pa[u.F][u.S], pa);
    cout << ' ' << char(u.F + 'A') << ' ' << u.S + 1;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T; while (T--) {
        vector<vector<int> > d(8, vector<int>(8, INF));
        vector<vector<pii> > pa(8, vector<pii>(8, make_pair(-1, -1)));
        pii s, t;
        char a; int b; 
        cin >> a >> b;
        s.F = a - 'A'; s.S = b - 1;
        cin >> a >> b;
        t.F = a - 'A'; t.S = b - 1;
        queue<pii> q; q.push(s);
        d[s.F][s.S] = 0;
        while (q.size()) {
            pii u = q.front(); q.pop();
            for (int _d = 0 ; _d < 4 ; _d++) {
                int cnt = 0; while (1) { cnt++;
                    pii v = make_pair(u.F + cnt * dx[_d], u.S + cnt * dy[_d]);
                    if (v.F < 0 || v.F >= 8 || v.S < 0 || v.S >= 8)
                        break;
                    if (d[v.F][v.S] != INF)
                        continue;
                    d[v.F][v.S] = d[u.F][u.S] + 1;
                    pa[v.F][v.S] = u;
                    q.push(v);
                }
            }
        }
        if (d[t.F][t.S] > 4) {
            cout << "Impossible\n";
        } else {
            cout << d[t.F][t.S];
            printPath(t, pa);
            cout << '\n';
        }
    }
}
