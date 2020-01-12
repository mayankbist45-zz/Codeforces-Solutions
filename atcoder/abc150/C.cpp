#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define MOD 1000000007
#define maxn 100010

void solve() {
    int n;
    cin >> n;


    vector<int> v(n), b(n);

    int ct = 0;
    bool ans = false;
    for (int i = 0; i < n; i++)
        cin >> v[i];
    for (int i = 0; i < n; i++) {
        cin >> b[i];
        if (v[i] > b[i] and ct == 0)
            ans = true, ct++;
        else if (v[i] < b[i] and ct == 0)
            ans = false, ct++;
    }

    if (v == b) {
        cout << 0;
        return;
    }

    if (ans)
        swap(v, b);
    ct = 0;
    while (next_permutation(v.begin(), v.end())) {
        if (b != v)
            ct++;
        else
            break;
    }
    cout << ct + 1 << endl;
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