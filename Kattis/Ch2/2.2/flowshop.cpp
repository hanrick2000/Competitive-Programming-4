#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m; cin >> n >> m;
    vector<vector<int> > data(n, vector<int>(m));
    for (auto &vv : data)
        for (auto &v : vv)
            cin >> v;
    for (int i = 1 ; i < n ; i++)
        data[i][0] += data[i - 1][0];
    for (int j = 1 ; j < m ; j++)
        data[0][j] += data[0][j - 1];
    for (int i = 1 ; i < n ; i++)
        for (int j = 1 ; j < m ; j++)
            data[i][j] += max(data[i - 1][j], data[i][j - 1]);
    for (int i = 0 ; i < n ; i++)
        cout << data[i][m - 1] << " \n"[i == n - 1];
}
