#include <bits/stdc++.h>
using namespace std;
int main() {
    int x, y; cin >> x >> y;
    if (x > 0) {
        if (y > 0)
            cout << 1 << '\n';
        else
            cout << 4 << '\n';
    } else {
        if (y < 0)
            cout << 3 << '\n';
        else
            cout << 2 << '\n';
    }
}
