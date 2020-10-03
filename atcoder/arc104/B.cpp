#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 100010
const int MOD = 1000000007;

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

int add(unordered_map<char, int, custom_hash> &mp, char ch, int val) {
    int ret = 0;
    if (mp.count(ch) and mp[ch] == 0)ret--;
    mp[ch] += val;
    if (mp[ch] == 0)ret++;
    return ret;
}

void solve() {
    int n;
    cin >> n;

    string s;
    cin >> s;

    string tp = s;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'A')tp[i] = 'T';
        else if (s[i] == 'T')tp[i] = 'A';
        else if (s[i] == 'G')tp[i] = 'C';
        else if (s[i] == 'C')tp[i] = 'G';
    }
    int ans = 0;
    for (int i = 0; i < s.size(); i++) {
        //start from i
        int ct = 0;
        unordered_map<char, int, custom_hash> mp;
        for (int j = i; j < s.size(); j++) {
            ct += add(mp, s[j], 1);
            ct += add(mp, tp[j], -1);

            if (ct == mp.size())ans++;
        }
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