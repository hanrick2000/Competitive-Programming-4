#include <bits/stdc++.h>
using namespace std;
int main() {
    // ios_base::sync_with_stdio(false);
    int n; cin >> n;
    int len = 1; while (len < n) len <<= 1;
    cout << len << ' ';
    if (len == n) {
        cout << 0 << '\n';
        return 0;
    }
    int cnt = 0, ans = 0;
    while (len) {
        ans += ((len & n) != 0) * cnt;
        cnt++; len >>= 1;
    }
    cout << 32 - __builtin_clz(n) - __builtin_ctz(n) << '\n';
}
