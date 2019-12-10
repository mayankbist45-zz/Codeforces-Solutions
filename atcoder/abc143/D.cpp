#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define MOD 1000000007
#define maxn 100010

bool check(int a, int b, int c) {
    return a < b + c and b < c + a and c < a + b;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }

    sort(v.begin(), v.end());
    int pans = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            int a = v[i], b = v[j];
            int mid, lo = j + 1, h = n - 1, ans = -1;
            while (lo <= h) {
                mid = lo + h >> 1;
                if (check(a, b, v[mid])) {
                    ans = mid;
                    lo = mid + 1;
                } else
                    h = mid - 1;
            }
            if (ans != -1)
                pans += ans - j;
        }
    }
    cout << pans << endl;
    return 0;
}