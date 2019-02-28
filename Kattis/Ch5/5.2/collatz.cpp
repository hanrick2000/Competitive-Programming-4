#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
vector<LL> solve(LL x) {
    vector<LL> ret;
    while (x != 1) {
        ret.push_back(x);
        if (x % 2)
            x = 3 * x + 1;
        else
            x /= 2;
    }
    ret.push_back(1);
    return ret;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    LL a, b; while (cin >> a >> b && a) {
        vector<LL> A = solve(a);
        vector<LL> B = solve(b);
        LL ans = 0;
        while (A.size() && B.size() && A.back() == B.back())
            ans = A.back(), A.pop_back(), B.pop_back();
        cout << a << " needs " << A.size() << " steps, ";
        cout << b << " needs " << B.size() << " steps, ";
        cout << "they meet at " << ans << '\n';
    }
}
