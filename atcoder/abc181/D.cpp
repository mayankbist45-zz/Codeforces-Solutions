#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 100010
const int MOD = 1000000007;

bool check(vector<int> &v) {
    sort(v.begin(), v.end());
    do {
        int sum = 0;
        for (auto x: v)sum = sum * 10 + x;
        if (sum % 8 == 0) {
            return true;
        }
    } while (next_permutation(v.begin(), v.end()));
    return false;
}

void done() {
    cout << "Yes";
    exit(0);
}
void solve() {
    string s;
    cin >> s;
    if (s.size() <= 2) {
        if (stoi(s) % 8 == 0)done();
        reverse(s.begin(), s.end());
        if (stoi(s) % 8 == 0)done();
        cout << "No";
        return;
    }
    map<int, int> mp;
    for (auto x: s)mp[x - '0']++;
    for (auto x: mp) {
        if (x.second >= 3) {
            vector<int> v = {x.first, x.first, x.first};
            if (check(v))done();
        }
    }
    for (int j = 1; j <= 9; j++) {
        for (int i = 1; i <= 9; i++) {
            if (i == j)continue;
            vector<int> v = {j, j, i};
            if (mp[j] >= 2 and mp[i] >= 1 and check(v)) done();
        }
    }
    for (int i = 1; i <= 9; i++) {
        for (int j = 1; j <= 9; ++j) {
            for (int k = 1; k <= 9; ++k) {
                if (i == j or j == k or k == i)continue;
                vector<int> v = {i, j, k};
                if (mp[i] > 0 and mp[j] > 0 and mp[k] > 0 and check(v))done();
            }
        }
    }
    cout << "No" << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}