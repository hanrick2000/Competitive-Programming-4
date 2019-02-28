#include <bits/stdc++.h>
using namespace std;
int x, y;
void solve(string &s, int idx) {
    if ((int)s.size() == idx) return ;
    x *= 2, y *= 2;
    if (s[idx] == '2' || s[idx] == '3')
        y++;
    if (s[idx] == '1' || s[idx] == '3')
        x++;
    solve(s, idx + 1);
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    string s; cin >> s;
    x = y = 0;
    solve(s, 0);
    cout << s.size() << ' ' << x << ' ' << y << '\n';
}
