#include <bits/stdc++.h>
using namespace std;
struct P {
    vector<string> data;
};
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    string attrs, tmp, input;
    getline(cin, attrs);
    map<string, int> ID;
    stringstream ss; ss << attrs;
    while (ss >> tmp) { 
        int sz = ID.size();
        ID[tmp] = sz;
    }
    int n; cin >> n; getline(cin, input);
    vector<P> raw(n);
    for (int i = 0 ; i < n ; i++) {
        getline(cin, input);
        ss.clear(); ss << input;
        while (ss >> tmp)
            raw[i].data.push_back(tmp);
    }
    int q; cin >> q; bool first = true; while (q--) {
        if (first) first = false; else cout << '\n';
        cout << attrs << '\n';
        string target; cin >> target;
        int tar = ID[target];
        stable_sort(raw.begin(), raw.end(), [tar](P a, P b){ return a.data[tar] < b.data[tar]; });
        for (auto &p : raw)
            for (int i = 0 ; i < (int)p.data.size() ; i++)
                cout << p.data[i] << " \n"[i == (int)p.data.size() - 1];
    }
    
}
