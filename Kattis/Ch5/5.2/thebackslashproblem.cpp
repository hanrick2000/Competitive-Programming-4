#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; while (cin >> n) {
        string s; getline(cin, s);
        getline(cin, s);
        string add(pow(2, n) - 1, '\\');
        string ans;
        for (auto &c : s) {
            if (('!' <= c && c <= '*') || ('[' <= c && c <= ']'))
                ans += add;
            ans += c;
        }
        cout << ans << '\n';
    }
}
