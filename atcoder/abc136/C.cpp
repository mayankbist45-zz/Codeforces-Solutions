#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    for (int j = 1; j < n; ++j) {
        if (v[j] < v[j - 1])
            return cout << "No" << endl, 0;
        else if (v[j] > v[j - 1])
            v[j]--;
    }
    cout << "Yes" << endl;

    return 0;
}