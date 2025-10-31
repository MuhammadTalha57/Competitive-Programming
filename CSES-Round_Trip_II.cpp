#include "bits/stdc++.h"

using namespace std;

vector<int> res;
// bool found = false;

bool dfs(int u, vector<vector<int>>& adjList, vector<int>& vis, vector<int>& par) {
    vis[u] = 1;

    for(int v: adjList[u]) {
        if(vis[v] == 1) {
            // Cycle
            res.push_back(v);
            for(; u != v; u = par[u]) {
                res.push_back(u);
            }
            res.push_back(v);
            return true;
        }
        else if(vis[v] == 0) {
            par[v] = u;
            if(dfs(v, adjList, vis, par)) {
                return true;
            }
        }
    }

    vis[u] = 2;
    return false;
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adjList(n + 1);
    int u, v;
    for(int i = 0 ; i < m; i++) {
        cin >> u >> v;
        adjList[u].push_back(v);
    }

    vector<int> vis(n + 1, 0);
    vector<int> par(n + 1, 0);
    for(int u =1 ; u <= n; u++) {
        if(vis[u] == 0) {
            par[u] = u;
            if(dfs(u, adjList, vis, par)) {
                cout << res.size() << '\n';
                reverse(res.begin(), res.end());
                for(int x: res) {cout << x << ' ';}
                return;
            }
        }
    }
    cout << "IMPOSSIBLE\n";
}

// Problem Link: https://cses.fi/problemset/task/1678

int main() {

    solve();


    return 0;
}