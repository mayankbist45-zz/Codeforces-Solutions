#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define maxn 300010
const int MOD = 1000000007;

vector<int> endhere[maxn];
int lef[maxn];

int n, q;
int bit[maxn], an[maxn];

void add(int idx, int val) {
    for (; idx < maxn; idx += idx & (-idx))
        bit[idx] += val;
}

int pref(int idx) {
    int ans = 0;
    for (; idx > 0; idx -= idx & (-idx))
        ans += bit[idx];
    return ans;
}

int sum(int a, int b) {
    return pref(b) - pref(a - 1);
}

void solve() {
    cin >> n >> q;
    vector<int> v(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> v[i];
        v[i] = i - v[i];
    }
    for (int i = 0; i < q; i++) {
        int a, b;
        cin >> a >> b;
        lef[i] = 1 + a;
        endhere[n - b].push_back(i);
    }
    int init = 0;
    for (int r = 1; r <= n; r++) {
        int target = v[r];
        if (target >= 0) {
            int lo = 1, hi = r, mid, ans = 0;
            while (lo <= hi) {
                mid = lo + hi >> 1;
                if (pref(mid) >= target) {
                    ans = mid;
                    lo = mid + 1;
                } else hi = mid - 1;
            }
            add(1, 1);
            add(ans + 1, -1);
//            cout << "pos : " << r << " " << ans << endl;
        }
        for (auto x: endhere[r])an[x] = pref(lef[x]);
    }
    for (int i = 0; i < q; i++)cout << an[i] << endl;
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