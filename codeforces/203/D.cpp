#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 100010
const int MOD = 1000000007;

int a, b, m;

double doit(double dist, int dt, int ct) {
    while (dist >= dt) {
        ct++;
        dist -= dt;
    }
    if (ct & 1)dist = dt - dist;
    return dist;
}

void solve() {
    cout << fixed << setprecision(10);
    cin >> a >> b >> m;

    int vx, vy, vz;
    cin >> vx >> vy >> vz;
    double timeTaken = (double) m / (double) abs(vy);
    double cordz = doit(vz * timeTaken, b, 0);
    double cordx = doit(timeTaken * abs(vx) + (double) a / 2.0, a, vx < 0);
    if (cordx >= a)cordx -= a;
//    if (vx < 0)cordx = a - cordx;
    cout << cordx << " " << cordz << endl;
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