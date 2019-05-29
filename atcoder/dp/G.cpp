#include <bits/stdc++.h>

#define int long long
using namespace std;
#define maxn 100010
int n,m;
vector<int> g[maxn];
int indegree[maxn] ,dist[maxn] ;
bool visited[maxn];

void dfs(int v,int p){
    visited[v] = true;
    for(auto x: g[v]){
        if(x == p)continue;
        dist[x] = max(dist[x] , 1 + dist[v]);
        indegree[x]--;
        if(indegree[x] == 0 and !visited[x])
            dfs(x ,v);
    }
}

int32_t main() {

    cin >> n >> m;

    int a ,b;
    for (int i = 0; i < m; ++i) {
        cin >> a >> b;
        g[a].push_back(b);
        indegree[b]++;
    }
    for(int i = 1; i <= n ;i++){
        if(!visited[i] and indegree[i] == 0)
            dfs(i , -1);
    }
    int ans = 0;
    for (int j = 1; j <= n; ++j) {
        ans = max(ans,dist[j]);
    }
    cout << ans;
}

