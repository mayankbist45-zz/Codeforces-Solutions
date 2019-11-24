#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define MOD 1000000007
#define maxn 100010

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    string s;
    cin >> s;

    for (char & i : s) {
        int ch = i - 'A';
        ch += n;
        ch %= 26;
        i = ch + 'A';
    }
    cout << s;
}