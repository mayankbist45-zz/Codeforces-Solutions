#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 200010
const int MOD = 1000000007;

vector<int> getDivisors(int val) {
    vector<int> ret;
    for (int i = 1; i * i <= val; i++) {
        if (val % i)continue;
        if (i != 1)
            ret.push_back(i);
        if (val / i == i)continue;
        ret.push_back(val / i);
    }
    return ret;
}

void solve() {
    int n;
    cin >> n;

    vector<int> v(n + 2);
    for (int i = 1; i <= n; ++i) cin >> v[i];

    vector<int> div = getDivisors(accumulate(v.begin(), v.end(), 0ll));

    int mn = LLONG_MAX;
    vector<int> sum, pre, suf;
    sum = pre = suf = v;
    for (int i = 1; i <= n; i++) {
        pre[i] = i * pre[i];
        sum[i] += sum[i - 1];
        pre[i] += pre[i - 1];
    }
    for (int i = n; i >= 1; i--) {
        suf[i] *= (n - i + 1);
        if (i + 1 <= n)suf[i] += suf[i + 1];
    }

    auto queryLeft = [&](int l, int r) -> int {
        if (l > r)return 0;
        return suf[l] - suf[r + 1] - (sum[r] - sum[l - 1]) * (n - r);
    };

    auto queryRight = [&](int l, int r) -> int {
        if (l > r)return 0;
        return pre[r] - pre[l - 1] - (sum[r] - sum[l - 1]) * (l - 1);
    };

    auto solve = [&](int id, int k) -> pair<int, int> {
        int steps = LLONG_MAX, sum = v[id], j = id;
        while (sum % k != 0) {
            id++;
            sum += v[id];
        }
        // given some array find the element
        // in which we shift all the elements
        // and that shifts are minimu

        for (int now = j; now <= id; now++) {
            steps = min(steps, queryLeft(j, now - 1) + queryRight(now + 1, id));
        }
        return {steps, id};
    };
    for (auto x: div) {
        int steps = 0;
        for (int i = 1; i <= n; i++) {
            auto result = solve(i, x);
            steps += result.first;
            i = result.second;
        }
        mn = min(mn, steps);
    }
    if(mn == LLONG_MAX)mn = -1;
    cout << mn << endl;
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