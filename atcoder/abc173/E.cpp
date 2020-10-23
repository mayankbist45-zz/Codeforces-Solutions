#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 100010
const int MOD = 1000000007;

void solve() {
    int n, k;
    cin >> n >> k;

    vector<int> v(n);
    vector<int> pos, neg;
    vector<long double> l1, l2;
    int ct = 0;
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
        if (v[i] > 0)pos.push_back(v[i]);
        else if (v[i] < 0)neg.push_back(-1 * v[i]);
        else ct++;
    }
    sort(pos.rbegin(), pos.rend());
    sort(neg.rbegin(), neg.rend());
    for (auto x: pos)l1.push_back(log(x));
    for (auto x: neg)l2.push_back(log(x));

    partial_sum(l1.begin(), l1.end(), l1.begin());
    partial_sum(l2.begin(), l2.end(), l2.begin());

    long double mx = 0;
    int id = -1;
    for (int ne = 0; ne <= k; ne += 2) {
        if(ne > neg.size())break;
        long double cur = 0;
        if (ne > 0) {
            cur += l2[ne - 1];
        }
        int need = k - ne;
        if (need > pos.size())continue;
        if (need > 0) {
            cur += l1[need - 1];
        }
        if (cur > mx) {
            mx = cur;
            id = ne;
        }
    }
//    cout << id << endl;
    if (id != -1) {
        int cur = 1;
        for (int i = 0; i < id; i++)(cur *= neg[i]) %= MOD;
        for (int i = 0; i < k - id; i++)(cur *= pos[i]) %= MOD;
        cout << cur << endl;
        return;
    } else {
        if (ct)cout << 0 << endl;
        else {
            l1.clear();
            l2.clear();
            reverse(pos.begin(), pos.end());
            reverse(neg.begin(), neg.end());
            for (auto x: pos)l1.push_back(log(x));
            for (auto x: neg)l2.push_back(log(x));

            partial_sum(l1.begin(), l1.end(), l1.begin());
            partial_sum(l2.begin(), l2.end(), l2.begin());

            mx = LDBL_MAX, id = -1;
            for (int ne = 0; ne <= k; ne++) {
                if(ne > neg.size())break;
                long double cur = 0;
                if (ne > 0) {
                    cur += l2[ne - 1];
                }
                int need = k - ne;
                if (need > pos.size())continue;
                if (need > 0) {
                    cur += l1[need - 1];
                }
                if (cur < mx) {
                    mx = cur;
                    id = ne;
                }
            }
            int cur = 1;
            for (int i = 0; i < id; i++)(cur *= -neg[i]) %= MOD;
            for (int i = 0; i < k - id; i++)(cur *= pos[i]) %= MOD;
            if(cur < 0)cur += MOD;
            cout << cur << endl;
        }
    }
    //make it neg
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