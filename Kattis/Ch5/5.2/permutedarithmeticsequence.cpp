#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t; cin >> t; while (t--) {
        int n; cin >> n;
        vector<int> data(n);
        for (auto &v : data)
            cin >> v;
        bool ok = true;
        for (int i = 1 ; i < (int)data.size() - 1 ; i++) {
            if (data[i] - data[i - 1] != data[i + 1] - data[i]) {
                ok = false; break;
            }
        }
        if (ok) {
            cout << "arithmetic\n";
            continue;
        }
        sort(data.begin(), data.end());
        ok = true;
        for (int i = 1 ; i < (int)data.size() - 1 ; i++) {
            if (data[i] - data[i - 1] != data[i + 1] - data[i]) {
                ok = false; break;
            }
        }
        if (ok) {
            cout << "permuted arithmetic\n";
        } else {
            cout << "non-arithmetic\n";
        }

    }
}
