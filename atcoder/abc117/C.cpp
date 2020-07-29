#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 100010
const int MOD = 1000000007;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> v(m);

    priority_queue<int> pq;
    int sum = 0;
    for (int i = 0; i < m; i++)
        cin >> v[i];
    sort(v.begin(), v.end());
    for (int i = 0; i < m; i++) {
        if (i)
            pq.push(v[i] - v[i - 1]), sum += v[i] - v[i - 1];
    }
    for (int i = 0; i < n - 1 and !pq.empty(); i++)
        sum -= pq.top(), pq.pop();
    cout << sum << endl;
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