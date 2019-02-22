#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    multiset<int> app;
    for (int i = 0 ; i < n ; i++) {
        int v; cin >> v;
        if (app.count(v))
            app.erase(app.find(v)); 
        app.insert(v - 1);
    }
    cout << app.size() << '\n';
}

