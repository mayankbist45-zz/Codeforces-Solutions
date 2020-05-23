//#include <bits/stdc++.h>
//
//using namespace std;
//
//#define int long long
//#define endl '\n'
//#define maxn 100010
//const int MOD = 1000000007;
//
//vector<int> r[maxn];
//
//void solve() {
//    int n, m, k, q;
//    cin >> n >> m >> k >> q;
//
//    for (int i = 0; i < k; i++) {
//        int a, b;
//        cin >> a >> b;
//
//        r[a].push_back(b);
//    }
//    vector<int> nice;
//    for (int i = 0; i < q; i++) {
//        int tp;
//        cin >> tp;
//        nice.push_back(tp);
//    }
//    int ct = 0, ans = 0;
//    for (auto &row:r)sort(row.begin(), row.end());
//    for (int row = 1; row <= n; row++) {
//        if (ct == k)break;
//        if (row == 1) {
//            if (r[row].empty()) {
//                ans++;
//            } else ans += r[row].back(), ct += r[row].size();
//            continue;
//        }
//
//    }
//    cout << ans - 1 << endl;
//}
//
//int32_t main() {
//    ios_base::sync_with_stdio(false);
//    cin.tie(nullptr);
//
//    int t = 1;
////    cin >> t;
//
//    while (t--)
//        solve();
//    return 0;
//}

#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 100010
const int MOD = 1000000007;

void solve() {
    int n, s1 = 0, s2 = 0;
    cin >> n;

    vector<int> v(3 * n);
    for (int i = 0; i < 3 * n; ++i) cin >> v[i];
    priority_queue<int, vector<int>, greater<int>> pq1;
    priority_queue<int> pq2;
    for (int i = 0; i < n; i++)pq1.push(v[i]), s1 += v[i];
    for (int i = 0; i < n; i++)pq2.push(v[2 * n + i]), s2 += v[2 * n + i];
    vector<int> pre(n + 1), suff(n + 1);
    pre[0] = s1, suff[n] = s2;
    for (int i = 0; i < n; i++) {
        int idx = n + i;
        if (v[idx] > pq1.top())
            s1 += v[idx] - pq1.top(), pq1.pop(), pq1.push(v[idx]);
        pre[i + 1] = s1;
    }
    for (int i = 0; i < n; i++) {
        int idx = 2 * n - i - 1;
        if (v[idx] < pq2.top())
            s2 += v[idx] - pq2.top(), pq2.pop(), pq2.push(v[idx]);
        suff[n - i - 1] = s2;
    }
    int ans = LLONG_MIN;
    for (int i = 0; i <= n; i++)ans = max(ans, pre[i] - suff[i]);
    cout << ans << endl;
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
