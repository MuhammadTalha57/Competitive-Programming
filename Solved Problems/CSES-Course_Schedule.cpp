#include "bits/stdc++.h"

using namespace std;

vector<int> res;
// bool found = false;

bool dfs(int u, vector<vector<int>>& adjList, vector<int>& vis) {
    vis[u] = 1;

    for(int v: adjList[u]) {
        if(vis[v] == 1) {
            // Cycle
            return true;
        }
        else if(vis[v] == 0) {
            if(dfs(v, adjList, vis)) {
                return true;
            }
        }
    }

    vis[u] = 2;
    res.push_back(u);
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
    for(int u =1 ; u <= n; u++) {
        if(vis[u] == 0) {
            if(dfs(u, adjList, vis)) {
                cout <<  "IMPOSSIBLE\n";
                return;
            }
        }
    }
    // cout << ;
    reverse(res.begin(), res.end());
    for(int x: res) {
        cout << x << ' ';
    }
}

// Problem Link: https://cses.fi/problemset/task/1679/

int main() {

    solve();


    return 0;
}