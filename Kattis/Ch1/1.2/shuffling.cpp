#include <bits/stdc++.h>
using namespace std;
void shuffles(vector<int> &data, bool isIn) {
    int len = data.size();
    int half = len >> 1;
    vector<int> ret;
    if (isIn) {
        vector<int> f(data.begin(), data.begin() + half);
        vector<int> b(data.begin() + half, data.end());
        for (int i = 0 ; i < (int)f.size() ; i++)
            ret.push_back(b[i]), ret.push_back(f[i]);
        if (b.size() != f.size())
            ret.push_back(b.back());
    } else {
        if (len % 2) half++;
        vector<int> f(data.begin(), data.begin() + half);
        vector<int> b(data.begin() + half, data.end());
        for (int i = 0 ; i < (int)b.size() ; i++)
            ret.push_back(f[i]), ret.push_back(b[i]);
        if (b.size() != f.size())
            ret.push_back(f.back());
    }
    data = ret;
}
bool check(vector<int> &data) {
    for (int i = 0 ; i < (int)data.size() ; i++)
        if (data[i] != i + 1)
            return true;
    return false;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; string op; cin >> n >> op;
    vector<int> data;
    for (int i = 1 ; i <= n ; i++)
        data.push_back(i);
    int ans = 0;
    do {
        shuffles(data, op[0] == 'i');
        ans++;
    } while (check(data));
    cout << ans << '\n';
}
