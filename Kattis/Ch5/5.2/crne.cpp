#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    long long n; cin >> n;
    if (n % 2) {
        cout << (n / 2 + 1) * (n / 2 + 2) << '\n';
    } else {
        cout << (n / 2 + 1) * (n / 2 + 1) << '\n';
    }
}
