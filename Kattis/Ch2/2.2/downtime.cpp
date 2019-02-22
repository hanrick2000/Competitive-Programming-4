#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    map<int, int> cnt;
    int n, k; cin >> n >> k;
    for (int i = 0 ; i < n ; i++) {
        int v; cin >> v;
        cnt[v]++; cnt[v + 1000]--;
    }
    int maxV = 0, sum = 0;
    for (auto &p : cnt) {
        sum += p.second;
        maxV = max(maxV, sum);
    }
    cout << maxV / k + (maxV % k != 0) << '\n';
}
