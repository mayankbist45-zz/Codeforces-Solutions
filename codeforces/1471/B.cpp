#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 200010
const int MOD = 1000000007;

void solve() {
    int n, x;
    cin >> n >> x;

    queue<int> q;
    for (int i = 0, tp; i < n; ++i) {
        cin >> tp;
        q.push(tp);
        q.push(1);
    }
    int sum = 0;
    while (!q.empty()) {
        int top = q.front();
        q.pop();
        int val = q.front();
        q.pop();

        sum += top * val;
        if (top % x)break;
        int put = top / x;
        int times = x * val;

        q.push(put);
        q.push(times);
    }
    while (!q.empty()) {
        int top = q.front();
        q.pop();
        int val = q.front();
        q.pop();
        sum += top * val;
    }
    cout << sum << endl;
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