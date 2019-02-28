#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; while (cin >> n && n) {
        vector<int> data(32, -1);
        while (n--) {
            string op; cin >> op;
            if (op[0] == 'S') {
                int x; cin >> x;
                data[x] = 1;
            } else if (op[0] == 'C') {
                int x; cin >> x;
                data[x] = 0;
            } else if (op[0] == 'O') {
                int x, y; cin >> x >> y;
                if (data[x] == 1 || data[y] == 1)
                    data[x] = 1;
                else if (data[x] == 0 && data[y] == 0)
                    data[x] = 0;
                else data[x] = -1;
            } else {
                int x, y; cin >> x >> y;
                if (data[x] == 0 || data[y] == 0)
                    data[x] = 0;
                else if (data[x] == 1 && data[y] == 1)
                    data[x] = 1;
                else
                    data[x] = -1;
            }
        }
        for (int i = 31 ; ~i ; i--) {
            if (data[i] == -1)
                cout << "?";
            else 
                cout << data[i];
        }
        cout << '\n';
    }
}
