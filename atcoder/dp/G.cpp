#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 5;

bool visited[maxn];
int dist[maxn];
vector<int> g[maxn];
int indegree[maxn];

void dfs(int a){
    visited[a] = true;
    for(auto b : g[a]){
        dist[b] = max(dist[b] , 1 + dist[a]);
        --indegree[b];
        if(indegree[b] == 0)
            dfs(b);
    }
}

int main(){
    int n,m;
    cin>>n>>m;

    for(int u=0;u<m;u++){
        int a,b;
        cin>>a>>b;

        g[a].push_back(b);
        indegree[b]++;
    }

    for(int i=1;i<=n;i++){
        if(!visited[i] && indegree[i] == 0)
            dfs(i);
    }

    cout<<*max_element(dist,dist+maxn);
}