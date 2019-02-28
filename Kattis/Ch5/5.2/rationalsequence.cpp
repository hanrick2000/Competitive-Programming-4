#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t; cin >> t; while (t--) {
        int idx; cin >> idx; cout << idx << ' ';
        LL p, q; char tmp; cin >> p >> tmp >> q;
        if (p < q) {
            cout << q << '/' << q - p << '\n';
        } else {
            if (q == 1) {
                cout << q <<  '/' << p + 1 << '\n';
            } else {
                LL level = p / q;
                p %= q;
                LL new_p = q, new_q = q - p;
                p = new_p, q = new_q;
                q += level * p;
                cout << p << '/' << q << '\n';
            }
        }
    }
}
