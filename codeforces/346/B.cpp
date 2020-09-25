#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 110
const int MOD = 1000000007;

vector<int> prefixFunction(string &s) {
    vector<int> pi(s.size());
    for (int i = 1; i < s.size(); i++) {
        int j = pi[i - 1];
        while (j > 0 and s[i] != s[j])j = pi[j - 1];
        if (s[i] == s[j])pi[i] = j + 1;
    }
    return pi;
}

void compute_automaton(string s, vector<vector<int>> &aut) {
    s += '#';
    int n = s.size();
    vector<int> pi = prefixFunction(s);
    aut.assign(n, vector<int>(26));
    for (int i = 0; i < n; i++) {
        for (int c = 0; c < 26; c++) {
            if (i > 0 and 'A' + c != s[i])aut[i][c] = aut[pi[i - 1]][c];
            else aut[i][c] = i + ('A' + c == s[i]);
        }
    }
}
string a, b, virus;
int dp[maxn][maxn][maxn], pre[maxn][maxn][maxn];

void solve() {
    cin >> a >> b >> virus;

    vector<vector<int>> aut;
    compute_automaton(virus, aut);
    memset(dp, -1, sizeof dp);

    dp[0][0][0] = 0;
    for (int i = 0; i <= a.size(); i++)
        for (int j = 0; j <= b.size(); j++)
            for (int k = 0; k < virus.size(); k++) {
                if (dp[i][j][k] == -1)continue;
                if (i < a.size() and dp[i + 1][j][k] < dp[i][j][k]) {
                    dp[i + 1][j][k] = dp[i][j][k];
                    pre[i + 1][j][k] = -1;
                }
                if (j < b.size() and dp[i][j + 1][k] < dp[i][j][k]) {
                    dp[i][j + 1][k] = dp[i][j][k];
                    pre[i][j + 1][k] = -2;
                }
                int kk = aut[k][a[i] - 'A'];
                if (i < a.size() and j < b.size() and a[i] == b[j] and kk < virus.size() and
                    dp[i + 1][j + 1][kk] < 1 + dp[i][j][k]) {
                    dp[i + 1][j + 1][kk] = dp[i][j][k] + 1;
                    pre[i + 1][j + 1][kk] = k;
                }
            }
    int mx = 0, id = -1;
    for (int i = 0; i <= virus.size(); i++) {
        if (dp[a.size()][b.size()][i] > mx) {
            mx = dp[a.size()][b.size()][i];
            id = i;
        }
    }
//    cout << mx << endl;
    if (mx == 0) {
        cout << 0 << endl;
    } else {
        vector<char> v;
        int x = a.size(), y = b.size(), c = id;
        while (x > 0 and y > 0 and id >= 0) {
            int val = pre[x][y][id];
            if (val == -1)x--;
            if (val == -2)y--;
            if (val >= 0) {
                v.push_back(a[x - 1]);
                x--, y--;
                id = val;
            }
        }
        reverse(v.begin(), v.end());
        for (auto x: v)cout << x;
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