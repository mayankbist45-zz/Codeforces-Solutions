#include <bits/stdc++.h>

using namespace std;

#define int long long
//#define endl '\n'
#define maxn 200010
const int MOD = 1000000007;

int a[maxn], b[maxn];
vector<pair<int, int>> one, two;
int n, m, k, s;
int id1 = -1, id2 = -1;

bool check(int mid) {
    int dollars = LLONG_MAX, pounds = LLONG_MAX;
    for (int i = 0; i < mid; i++) {
        dollars = min(dollars, a[i]);
        pounds = min(pounds, b[i]);
    }
    int money = LLONG_MAX;
    for (int i = 0; i <= one.size() and i <= k; i++) {
        int need = k - i;
        if (two.size() < need)continue;
        int cur = 0;
        if (i)cur = one[i - 1].first * dollars;
        if (need)
            cur += two[need - 1].first * pounds;
        if (money > cur) {
            money = cur;
            id1 = i;
            id2 = need;
        }
    }
    return money <= s;
}

void solve() {
    cin >> n >> m >> k >> s;
    for (int i = 0; i < n; i++)cin >> a[i];
    for (int i = 0; i < n; i++)cin >> b[i];

    for (int i = 0; i < m; i++) {
        int t, c;
        cin >> t >> c;
        if (t == 1)one.push_back({c, i + 1});
        else two.push_back({c, i + 1});
    }
    sort(one.begin(), one.end());
    sort(two.begin(), two.end());

    for (int i = 1; i < one.size(); i++)one[i].first += one[i - 1].first;
    for (int i = 1; i < two.size(); i++)two[i].first += two[i - 1].first;

    int lo = 1, hi = n, mid, ans = -1;
    int n1 = -1, n2 = -1;
    while (lo <= hi) {
        mid = lo + hi >> 1;
        if (check(mid)) {
            ans = mid;
            n1 = id1;
            n2 = id2;
            hi = mid - 1;
        } else lo = mid + 1;
    }
    cout << ans << endl;
    if (ans != -1) {
        int d1 = -1, d2 = -1, mx1 = LLONG_MAX, mx2 = LLONG_MAX;
        for (int i = 0; i < ans; i++) {
            if (mx1 > a[i]) {
                mx1 = a[i];
                d1 = i + 1;
            }
            if (mx2 > b[i]) {
                mx2 = b[i];
                d2 = i + 1;
            }
        }
        for (int i = 0; i < n1; i++)cout << one[i].second << " " << d1 << endl;
        for (int i = 0; i < n2; i++)cout << two[i].second << " " << d2 << endl;
    }
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