#include <bits/stdc++.h>

using namespace std;

struct interact {
    pair<int, int> query(vector<int> &v) {
        cout << "? ";
        for (auto x: v)cout << x << " ";
        cout << endl;
        pair<int, int> ret;
        cin >> ret.first >> ret.second;
        return ret;
    }

    void write(int result) {
        cout << "! " << result << endl;
    }
} it;

void solve() {
    int n, k;
    cin >> n >> k;
    map<int, int> mp;
    for (int i = 1; i <= k + 1; i++) {
        vector<int> qr;
        for (int j = 1; j <= k + 1; j++) {
            if (j == i)continue;
            qr.push_back(j);
        }
        auto tp = it.query(qr);
        mp[tp.second]++;
    }
    it.write(mp.rbegin()->second);
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
//    cin >> t;

    while (t--)
        solve();
    return 0;
}