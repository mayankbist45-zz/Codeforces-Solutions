#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 100010
const int MOD = 1000000007;

void solve() {
    int n, k;
    cin >> n >> k;

    string a, b;
    cin >> a >> b;

    map<char, int> mp, cp;
    for (auto x: b)mp[x]++;
    for (auto x: a)cp[x]++;

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    char id = 'a';
    for (int i = 0; i < 26; i++) {
        for (char ch = 'a'; ch < i + 'a'; ch++)cp[ch + 1] += (cp[ch] / k) * k, cp[ch] = 0;
        int howmany = mp[i + 'a'], j = i;
        if (howmany > cp[i + 'a']) {
            cout << "nO" << endl;
            return;
        }
        mp[i + 'a'] -= howmany;
        cp[i + 'a'] -= howmany;
    }
    for (auto x: mp)
        if (x.second) {
            cout << "nO" << endl;
            return;
        }
    cout << "yEs" << endl;
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