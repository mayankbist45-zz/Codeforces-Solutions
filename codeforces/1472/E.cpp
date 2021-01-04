#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

struct pot {
    int w, h, id;
};

vector<vector<pair<int, int>>> tree;
vector<pot> v1, v2;
int id, n;

pair<int, int> doit(pair<int, int> a, pair<int, int> b) {
    pair<int, int> p;
    p.first = min(a.first, b.first);
    if (a.first < b.first)p.second = a.second;
    else p.second = b.second;
    return p;
}

void build(int start, int end, int index = 1) {
    if (start == end) {
        if (id == 0)
            tree[index][id] = {v1[start].w, v1[start].id};
        else
            tree[index][id] = {v2[start].h, v2[start].id};
        return;
    }
    int mid = start + end >> 1;
    build(start, mid, 2 * index);
    build(mid + 1, end, 2 * index + 1);
    tree[index][id] = doit(tree[2 * index][id], tree[2 * index + 1][id]);
}

pair<int, int> queryTree(int start, int end, int l, int r, int index = 1) {
    if (r < start or l > end)return {LLONG_MAX, -1};
    if (l <= start and r >= end)return tree[index][id];
    int mid = start + end >> 1;
    return doit(queryTree(start, mid, l, r, 2 * index), queryTree(mid + 1, end, l, r, 2 * index + 1));
}

int getIdHeight(int val) {
    //v1
    int lo = 0, hi = n - 1, mid, ans = -1;
    while (lo <= hi) {
        mid = lo + hi >> 1;
        if (v1[mid].h < val) {
            ans = mid;
            lo = mid + 1;
        } else hi = mid - 1;
    }
    return ans;
}
int getIdWidth(int val) {
    //v2
    int lo = 0, hi = n - 1, mid, ans = -1;
    while (lo <= hi) {
        mid = lo + hi >> 1;
        if (v2[mid].w < val) {
            ans = mid;
            lo = mid + 1;
        } else hi = mid - 1;
    }
    return ans;
}
void solve() {
    cin >> n;

    vector<int> ans(n, -1);
    v1 = vector<pot>(n);
    for (int i = 0; i < n; ++i) {
        cin >> v1[i].h >> v1[i].w;
        v1[i].id = i;
    }
    tree = vector<vector<pair<int, int>>>(4 * (n + 10), vector<pair<int, int>>(2));
    v2 = v1;
    sort(v1.begin(), v1.end(), [](auto &a, auto &b) { return a.h < b.h; });
    sort(v2.begin(), v2.end(), [](auto &a, auto &b) { return a.w < b.w; });

    id = 0;
    build(0, n - 1);
    id = 1;
    build(0, n - 1);

    for (int i = 0; i < n; i++) {
        id = 0;
        int ID = -1, lo = 0, hi = i - 1, mid;
        while (lo <= hi) {
            mid = (lo + hi) / 2;
            if (v1[mid].h < v1[i].h) {
                ID = mid;
                lo = mid + 1;
            } else hi = mid - 1;
        }
        if (ID != -1) {
            pair<int, int> val = queryTree(0, n - 1, 0, ID, 1);
            if (val.first < v1[i].w) {
                ans[v1[i].id] = val.second + 1;
            }

        }
        //do v2 here h and w combination
        ID = getIdWidth(v1[i].h);
        if (ID == -1)continue;
        id = 1;
        auto val = queryTree(0, n - 1, 0, ID, 1);
        if (val.second != -1 and val.first < v1[i].w)
            ans[v1[i].id] = val.second + 1;
    }

    for (auto x: ans)cout << x << " ";
    cout << endl;
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
