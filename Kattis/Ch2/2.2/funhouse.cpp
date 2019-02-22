#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
int main() {
    int n, m, kase = 0; while (cin >> m >> n && n) {
        cout << "HOUSE " << ++kase << '\n';
        vector<vector<char> > G(n, vector<char>(m));
        pair<int, int> s;
        for (int i = 0 ; i < n ; i++) {
            for (int j = 0 ; j < m ; j++) {
                cin >> G[i][j];
                if (G[i][j] == '*')
                    s.F = i, s.S = j;
            }
        }
        int dir_x = -1, dir_y = -1;
        if (s.S == 0)
            dir_x = 0, dir_y = 1;
        if (s.F == 0)
            dir_x = 1, dir_y = 0;
        if (s.S == m - 1)
            dir_x = 0, dir_y = -1;
        if (s.F == n - 1)
            dir_x = -1, dir_y = 0;
        do {
            if (G[s.F][s.S] == '/')
                swap(dir_x, dir_y), dir_x *= -1, dir_y *= -1;
            if (G[s.F][s.S] == '\\')
                swap(dir_x, dir_y);
            s.F += dir_x;
            s.S += dir_y;
        } while (G[s.F][s.S] != 'x');
        G[s.F][s.S] = '&';
        for (auto &vv : G) {
            for (auto &v : vv)
                cout << v;
            cout << '\n';
        }
    }
}
