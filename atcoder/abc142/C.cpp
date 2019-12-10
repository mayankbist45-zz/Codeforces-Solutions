//When nothing comes in mind gcd laga lena
#include <bits/stdc++.h>

using namespace std;

#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
#define int long long
#define endl '\n'
#define MOD 1000000007

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<pair<int, int>> v;
    for (int i = 0; i < n; ++i) {
        int tp;
        cin >> tp;

        v.push_back({tp, i + 1});
    }
    sort(v.begin(), v.end());
    for (auto x:v)
        cout << x.second << " ";

    return 0;
}