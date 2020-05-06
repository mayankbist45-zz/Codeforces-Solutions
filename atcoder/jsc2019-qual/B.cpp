#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 100010
const int MOD = 1000000007;

class BIT{
public:
    vector<int> bit;
    int N;
    BIT(int n){
        N = n;
        bit = vector<int>(N + 1);
    }
    void add(int idx, int val){
        for(;idx <= N; idx += idx & (-idx))bit[idx] += val;
    }
    int pref(int idx){
        int ret = 0;
        for(;idx > 0; idx -= idx & (-idx))ret += bit[idx];
        return ret;
    }
};

int n ,k;
void solve() {
    cin >> n >>k;

    ordered_set st;
    vector<int> v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
        st.insert(v[i]);
    }
    for(auto &x: v)x = st.order_of_key(x + 1);
    int N = *max_element(v.begin() ,v.end());
    BIT a(N) , b(N);
    for(auto x: v)a.add(x, 1);
    int ans = 0;

    auto put = [](int a){
        int tp = (k *(k - 1))/2;
        tp %= MOD;
        return a * tp % MOD;
    };

    for(int i = 0; i < n; i++){
        ans = (ans + (b.pref(N) - b.pref(v[i])) * k % MOD) % MOD;
        ans = (ans + (put(a.pref(v[i] - 1)))) % MOD;
        b.add(v[i], 1);
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
