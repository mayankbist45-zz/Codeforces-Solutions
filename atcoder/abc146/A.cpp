#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define MOD 1000000007
#define maxn 100010

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
//
//    int n;
//    cin >> n;
//
//    vector<int> v(n);
//    for (int i = 0; i < n; ++i) {
//        cin >> v[i];
//    }

    vector<string> s = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};
    string st;
    cin >> st;

    int an = 0;
    for (int j = 0; j < s.size(); ++j) {
        if (s[j] == st)
            an = j;
    }
    cout << 7 - an << endl;
}