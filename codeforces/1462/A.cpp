#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 100010
const int MOD = 1000000007;

void solve() {
    int n;
    cin >> n;

    deque<int> v;
    for (int i = 0, tp; i < n; ++i) {
        cin >> tp;
        v.push_back(tp);
    }
    while (v.size() >= 2) {
        cout << v.front() << " " << v.back() << " ";
        v.pop_back();
        v.pop_front();
    }
    if (v.size())cout << v.front() << " ";
    cout << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;

    while (t--)
        solve();
    return 0;
}