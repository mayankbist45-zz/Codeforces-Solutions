#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 100010
const int MOD = 1000000007;

char mat[110][110];

void solve() {
    int h, w;
    cin >> h >> w;

    for (int i = 0; i < h; i++)
        for (int j = 0; j < w; j++)cin >> mat[i][j];

    vector<bool> rows(h + 1), col(w + 1);
    for (int i = 0; i < h; i++) {
        bool f = true;
        for (int j = 0; j < w; j++) {
            if (mat[i][j] == '#') {
                f = false;
                break;
            }
        }
        rows[i] = f;
    }
    for (int i = 0; i < w; i++) {
        bool f = true;
        for (int j = 0; j < h; j++) {
            if (mat[j][i] == '#') {
                f = false;
                break;
            }
        }
        col[i] = f;
    }
    for (int i = 0; i < h; i++) {
        if(rows[i])continue;
        for (int j = 0; j < w; j++) {
            if (col[j])continue;
            cout << mat[i][j];
        }
        cout << endl;
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