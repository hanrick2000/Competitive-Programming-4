#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
long long fpow(long long a, long long n) {
    if (n == 0) return 1;
    long long k = fpow(a, n / 2);
    long long ret = k * k % MOD;
    if (n % 2)
        ret = ret * a % MOD;
    return ret;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t; cin >> t; while (t--) {
        long long d; cin >> d;
        cout << fpow(9, d - 1) * 8 % MOD << '\n';
    }
}
