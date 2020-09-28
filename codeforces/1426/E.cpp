#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 100010
const int MOD = 1000000007;

int whowin(int a, int b) {
/*
 * 1 - rock
 * 2 - scissors
 * 3 - papers
 */
    if (a == 1 and b == 3)return 1;
    if (a == 1 and b == 2)return -1;
    if (a == 2 and b == 1)return 1;
    if (a == 2 and b == 3)return -1;
    if (a == 3 and b == 1)return -1;
    if (a == 3 and b == 2)return 1;
    return 0;
}

void solve() {
    int n;
    cin >> n;
    vector<pair<int, int>> ta(3), tb(3), a(3), b(3);
    cin >> ta[0].first >> ta[1].first >> ta[2].first;
    cin >> tb[0].first >> tb[1].first >> tb[2].first;

    for (int i = 0; i < 3; i++)ta[i].second = tb[i].second = i + 1;

    int mx = 0, mn = INT_MAX;
    sort(ta.begin(), ta.end());
    do {
        sort(tb.begin(), tb.end());
        do {
            a = ta, b = tb;
            int alice = 0, bobs = 0, id = 0;
            for (int i = 0; i < 3; i++) {
                auto x = b[i].second;
                while (b[i].first > 0) {
                    int pre = a[id].second;
                    int zp = whowin(pre, b[i].second);
                    if (zp < 0)alice += min(a[id].first, b[i].first);
                    else if (zp > 0)bobs += min(a[id].first, b[i].first);

                    if (a[id].first == b[i].first) {
                        id++;
                        break;
                    } else if (a[id].first > b[i].first) {
                        a[id].first -= b[i].first;
                        break;
                    } else {
                        b[i].first -= a[id].first;
                        id++;
                    }
                }
            }
            mx = max(mx, alice);
            mn = min(mn, alice);
        } while (next_permutation(tb.begin(), tb.end()));
    } while (next_permutation(ta.begin(), ta.end()));
    cout << mn << " " << mx << endl;
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