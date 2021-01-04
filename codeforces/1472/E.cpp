#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
void solve() {
    struct pot { int w, h, id; };
    int n;
    cin >> n;
    vector<pot> v1, v2;
    vector<pair<int, int>> width(n), height(n);
    vector<int> ans(n, -1);
    v1 = vector<pot>(n);
    for (int i = 0; i < n; ++i) {
        cin >> v1[i].h >> v1[i].w;
        v1[i].id = i;
    }
    v2 = v1;
    sort(v1.begin(), v1.end(), [](auto &a, auto &b) { return a.h < b.h; });
    sort(v2.begin(), v2.end(), [](auto &a, auto &b) { return a.w < b.w; });

    auto getIdWidth = [&](int val) -> int {
        int lo = 0, hi = n - 1, mid, ans = -1;
        while (lo <= hi) {
            mid = (lo + hi) / 2;
            if (v2[mid].w < val) {
                ans = mid;
                lo = mid + 1;
            } else hi = mid - 1;
        }
        return ans;
    };

    for (int i = 0; i < n; i++) {
        width[i] = {v1[i].w, v1[i].id};
        height[i] = {v2[i].h, v2[i].id};

        if (i) {
            auto solve = [](pair<int, int> &a, pair<int, int> b) {
                if (b.first < a.first) a = b;
            };
            solve(width[i], width[i - 1]);
            solve(height[i], height[i - 1]);
        }
    }
    for (int i = 0; i < n; i++) {
        int ID = -1, lo = 0, hi = i - 1, mid;
        while (lo <= hi) {
            mid = (lo + hi) / 2;
            if (v1[mid].h < v1[i].h) {
                ID = mid;
                lo = mid + 1;
            } else hi = mid - 1;
        }
        if (ID != -1) {
            auto val = width[ID];
            if (val.first < v1[i].w) {
                ans[v1[i].id] = val.second + 1;
                continue;
            }
        }
        ID = getIdWidth(v1[i].h);
        if (ID == -1)continue;
        auto val = height[ID];
        if (val.first < v1[i].w)ans[v1[i].id] = val.second + 1;
    }
    for (auto x: ans)cout << x << " ";
    cout << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--)solve();
    return 0;
}