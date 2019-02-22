#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL INF = 0x3f3f3f3f3f3f3f3fLL;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t; cin >> t; while (t--) {
        int n, m; cin >> n >> m;
        vector<vector<LL> > data(n);
        vector<LL> P;
        for (int i = 0 ; i < n ; i++) {
            LL k; cin >> k;
            while (k--) {
                LL v; cin >> v; v--;
                data[i].push_back(v);
            }
            LL v; cin >> v;
            P.push_back(v);
        }
        vector<LL> sti(m);
        for (auto &v : sti)
            cin >> v;
        LL ans = 0;
        for (int i = 0 ; i < n ; i++) {
            LL minV = INF;
            for (auto &v : data[i])
                minV = min(minV, sti[v]);
            ans += minV * P[i];
        }
        cout << ans << '\n';
    }
}
