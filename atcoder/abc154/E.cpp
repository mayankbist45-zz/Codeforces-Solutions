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
using int32 = __uint32_t;

string num;
int a, b, d, k;
int DP[210][4][2];

int call(int pos, int cnt, int f){
    if(cnt > k) return 0;

    if(pos == num.size()){
        if(cnt == k) return 1;
        return 0;
    }

    if(DP[pos][cnt][f] != -1) return DP[pos][cnt][f];
    int res = 0;

    int LMT;

    if(f == 0){
        LMT = num[pos] - '0';
    } else {
        LMT = 9;
    }

    for(int dgt = 0; dgt<=LMT; dgt++){
        int nf = f;
        int ncnt = cnt;
        if(f == 0 && dgt < LMT) nf = 1;
        if(dgt > 0) ncnt++;
        if(ncnt <= k) res += call(pos+1, ncnt, nf);
    }

    return DP[pos][cnt][f] = res;
}

void solve() {
    cin >> num >> k;

    memset(DP, -1, sizeof(DP));
    int res = call(0, 0, 0);
    cout << res << endl;
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
