#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 100010
const int MOD = 1000000007;

void solve() {
    int n;
    cin >> n;

    vector<int> v(n);
    priority_queue<double, vector<double> , greater<>> pq;
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
        pq.push(v[i]);
    }
    while (pq.size() >= 2) {
        double a = pq.top();
        pq.pop();

        double b = pq.top();
        pq.pop();

        pq.push((a + b) / 2.0);
    }

    cout << setprecision(6) << fixed << pq.top() << endl;
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