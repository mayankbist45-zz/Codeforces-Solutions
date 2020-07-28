#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 100010
const int MOD = 1000000007;

struct Matrix {
    vector<vector<int> > mat;
    int n_rows, n_cols;

    Matrix(vector<vector<int> > values) : mat(values), n_rows(values.size()), n_cols(values[0].size()) {}

    static Matrix identity_matrix(int n) {
        vector<vector<int> > values(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++)
            values[i][i] = 1;
        return values;
    }

    Matrix operator*(const Matrix &other) const {
        int n = n_rows, m = other.n_cols;
        vector<vector<int> > result(n_rows, vector<int>(m, 0));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) {
                for (int k = 0; k < n_cols; k++) {
                    result[i][j] = (result[i][j] + mat[i][k] * 1ll * other.mat[k][j]) % MOD;
                }
            }
        return Matrix(result);
    }

    inline bool is_square() const { return n_rows == n_cols; }
};

Matrix fast_exponentiation(Matrix m, int power) {
    assert(m.is_square());
    Matrix result = Matrix::identity_matrix(m.n_rows);
    while (power) {
        if (power & 1)
            result = result * m;
        m = m * m;
        power >>= 1;
    }
    return result;
}


void solve() {
    int n, k;
    cin >> n >> k;

    vector<vector<int>> v = vector<vector<int>>(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++)cin >> v[i][j];
    }
    Matrix a(v);
    Matrix res = fast_exponentiation(a, k);
    int ans = 0;
    for (int i = 0; i < n; i++)for (int j = 0; j < n; j++)(ans += res.mat[i][j]) %= MOD;
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