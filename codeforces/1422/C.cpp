#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 100010
const int MOD = 1000000007;


int invnine;
int power(int a, int b, int m = MOD) {
    if (b == 0)
        return 1;
    if (b & 1)return a * power(a, b - 1) % m;
    return power(a * a % m, b / 2);
}
int inverse(int a) {
    return power(a, MOD - 2);
}

int pw[maxn];
void preprocess() {
    pw[0] = 1;
    for (int i = 1; i <= maxn - 10; i++)
        pw[i] = pw[i - 1] * 10 % MOD;
    invnine = inverse(9);
}
int sum(int l) {
    int ret = (pw[l] - 1 + MOD) % MOD;
    ret *= invnine;
    ret %= MOD;
    return ret;
}

void solve() {
    string s;
    cin >> s;

    vector<int> pre(s.size() + 1), suf(s.size() + 2);
    for (int i = 0; i < s.size(); i++) {
        pre[i + 1] = pre[i] * 10 + s[i] - '0';
        pre[i + 1] %= MOD;
    }
    for (int i = s.size(); i >= 1; i--) {
        suf[i] = pw[s.size() - i] * (s[i - 1] - '0') + suf[i + 1];
        suf[i] %= MOD;
    }
    for (int i = s.size(); i >= 1; i--) {
        suf[i] += suf[i + 1];
        if (suf[i] >= MOD)suf[i] -= MOD;
    }
    int ans = 0;
    for (int i = 1; i <= s.size(); i++) {
        ans += pre[i - 1] * sum(s.size() - i + 1) % MOD + suf[i + 1];
        ans %= MOD;
    }
    cout << ans << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    preprocess();
    int t = 1;
//    cin >> t;

    while (t--)
        solve();
    return 0;
}