#include <bits/stdc++.h>

using namespace std;

double ar[3000];
int n;
double dp[3000][3000];
bool visited[3000][3000];

double solve(int i, int heads) {
    if (i == n)
        return heads * 2 >= n;
    double &ans = dp[i][heads];
    if (visited[i][heads])
        return ans;
    visited[i][heads] = true;
    ans = ar[i] * solve(i + 1, heads + 1) + (1-ar[i]) * solve(i+1 , heads);
    return ans;
}

int main() {

    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> ar[i];
    cout << setprecision(10) << fixed << solve(0, 0) << endl;

    return 0;
}
