#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1);
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    double r, m, c; while (cin >> r >> m >> c && r) {
        cout << fixed << setprecision(10) << r * r * PI << ' ' << 4 * r * r * c / m << '\n';
    }
}
