#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 100010
const int MOD = 1000000007;

void done() {
    cout << "NO" << endl;
    exit(0);
}

void doit(int &a, int &b) {
    int diff = min(a, b);
    a -= diff;
    b -= diff;
}

void solve() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int sum = a + b + c + d;

    if (a > b and c)done();
    if (a > b and !c and d)done();
    if (d > c and b)done();
    if (d > c and !b and a)done();
    string one, two;
    for (int i = 0; i < min(a, b); i++)one += "01";
    doit(a, b);
    if (a)one += '0';
    for (int i = 0; i < min(c, d); i++)two += "23";
    doit(c, d);
    if (d)two = "3" + two;
    string mid;
    for (int i = 0; i < min(b, c); i++)mid += "21";
    doit(b, c);
    if (c)two += '2';
    if (b)one = '1' + one;
    string ans = one + mid + two;
    if (ans.size() != sum)done();
    for (int i = 1; i < ans.size(); i++) if(abs(ans[i] - ans[i - 1]) != 1)done();
    cout << "YES" << endl;
    for(auto x: ans)cout << x << " ";
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