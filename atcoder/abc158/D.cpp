#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 100010
const int MOD = 1000000007;

void solve() {
    string s;
    cin >> s;

    int q;
    cin >> q;

    deque<char> dq;

    int start = 0;
    for (auto x: s)dq.push_back(x);
    for (int i = 0; i < q; i++) {
        int t;
        cin >> t;

        if (t == 1)start ^= 1;
        else {
            int f;
            cin >> f;

            char ch;
            cin >> ch;

            if (f == 1) {
                if (start == 1)dq.push_back(ch);
                else dq.push_front(ch);
            } else {
                if (start != 1)dq.push_back(ch);
                else dq.push_front(ch);
            }
        }
    }
    if (start == 1) {
        for (int i = dq.size() - 1; i >= 0; i--)cout << dq[i];
    }
    else for(auto x: dq)cout << x;
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