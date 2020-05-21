#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 100010
const int MOD = 1000000007;

int getBlock(vector<int> &r, int fd) {
    if(r.empty())return -1;
    auto tp = upper_bound(r.begin(), r.end(), fd);
    if (tp == r.begin())return -1;
    tp--;
    return *tp;
}

int getBlockB(vector<int> &r, int fd) {
    if(r.empty())return -1;
    auto tp = lower_bound(r.begin(), r.end(), fd);
    if (tp == r.end())return -1;
    return *tp;
}

void solve() {
    int h, w;
    cin >> h >> w;

    vector<string> v(h);
    for (int i = 0; i < h; i++) cin >> v[i];

    vector<int> row[h], col[w];
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (v[i][j] == '#')row[i].push_back(j);
        }
    }
    for (int i = 0; i < w; i++) {
        for (int j = 0; j < h; j++) {
            if (v[j][i] == '#')col[i].push_back(j);
        }
    }
    int ans = 0;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            int pans = 0;
            if (v[i][j] == '#')continue;
            int block = getBlock(row[i], j - 1);
            pans += j - block;
            block = getBlock(col[j], i - 1);
            pans += i - block;

            block = getBlockB(row[i], j + 1);
            if (block == -1)block = w;
            pans += block - j;
            block = getBlockB(col[j], i + 1);
            if (block == -1)block = h;
            pans += block - i;

            ans = max(ans, pans - 3);
        }
    }
    cout << ans << endl;
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