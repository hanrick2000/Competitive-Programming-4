#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    string s; cin >> s;
    string ans;
    for (int i = 0 ; i < (int)s.size() ; i++) {
        if (i + 2 < (int)s.size() && s[i] != s[i + 1] && s[i + 1] != s[i + 2] && s[i] != s[i + 2])
            ans += 'C', i += 2;
        else if (s[i] == 'R')
            ans += 'S';
        else if (s[i] == 'B')
            ans += 'K';
        else if (s[i] == 'L')
            ans += 'H';
    }
    cout << ans << '\n';
}
