#include <bits/stdc++.h>
using namespace std;
int main() {
    long long n, q; cin >> n >> q;
    vector<long long> data(n);
    for (auto &c : data) cin >> c;
    sort(data.begin(), data.end());
    long long ans = 0;
    while (q--) {
        int p; cin >> p;
        ans += *lower_bound(data.begin(), data.end(), p) - p;
    }
    cout << ans << '\n';
}
