#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 100010
const int MOD = 1000000007;

void solve() {
    int n, q;
    cin >> n >> q;

    vector<pair<int, pair<int, int>>> events;
    for (int i = 0; i < n; i++) {
        int s, t, x;
        cin >> s >> t >> x;

        events.push_back({s - x, {1, x}});
        events.push_back({t - x, {-1, x}});
    }
    sort(events.begin(), events.end());

    multiset<int> st;
    int id = 0;
    for (int i = 0; i < q; i++) {
        int d;
        cin >> d;
        while (events.size() > id and events[id].first <= d) {
            if (events[id].second.first == 1)
                st.insert(events[id].second.second);
            else st.erase(st.find(events[id].second.second));
            id++;
        }
        if (st.empty())cout << -1 << endl;
        else cout << *st.begin() << endl;
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