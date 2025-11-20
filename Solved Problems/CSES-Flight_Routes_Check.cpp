#include "bits/stdc++.h"

using namespace std;

void dfs(int u, vector<vector<int>>& adjList, vector<int>& vis) {
    vis[u] = 1;
    for(int v: adjList[u]) {
        if(vis[v] == 0) {
            dfs(v, adjList, vis);
        }
    }
}

// Problem Link: https://cses.fi/problemset/task/1682

int main() {
    int n, m;
    cin >> n >> m;
    int u, v;
    vector<vector<int>> adjList(n + 1), invAdjList(n + 1);
    vector<int> vis(n + 1, 0);
    for(int i = 0; i < m; i++) {
        cin >> u >> v;
        adjList[u].push_back(v);
        invAdjList[v].push_back(u);
    }

    bool flag = false;
    for(int u = 1; u <= n; u++) {
        if(vis[u] == 0) {
            if(flag) { 
                cout << "NO\n";
                cout << 1 << ' ' << u << '\n';
                return 0;
            }
            flag = true;
            dfs(u, adjList, vis);
        }
    }


    flag = false;
    vis.assign(n + 1, 0);
    for(int u = 1; u <= n; u++) {
        if(vis[u] == 0) {
            if(flag) { 
                cout << "NO\n";
                cout << u << ' ' << 1 << '\n';
                return 0;
            }
            flag = true;
            dfs(u, invAdjList, vis);
        }
    }

    cout << "YES\n";
    return 0;
}