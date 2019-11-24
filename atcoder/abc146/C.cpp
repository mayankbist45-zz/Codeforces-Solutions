#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define MOD 1000000007
#define maxn 100010
int a, b, x;

bool check(int p) {
    int dig = 0, tp = p;
    while (tp > 0) {
        dig++;
        tp /= 10;
    }

    if(a * p  + b * dig <= x)
        return true;
    return false;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> a >> b >> x;

    int l = 1, h = 1e9, mid, ans = 0;
    while (l <= h) {
        mid = l + h >> 1;
        if (check(mid)) {
            ans = mid;
            l = mid + 1;
        } else
            h = mid - 1;
    }
    cout << ans << endl;
}