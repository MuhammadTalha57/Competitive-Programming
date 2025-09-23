#include "bits/stdc++.h"

using namespace std;
int n, m;
vector<vector<int>> g;
vector<int> par, vis, res;
bool flag = false;

void dfs(int u) {
    vis[u] = 1;

    for(int v: g[u]) {
        if(flag) {return;}
        if(v == par[u]) {continue;}
        if(vis[v] == 0) {
            par[v] = u;
            dfs(v);
        }
        else if(vis[v] == 1) {
            flag = true;
            for(int t = u; t != v; t = par[t]) {
                res.push_back(t);
            }
            res.push_back(v);
            res.push_back(u);
            reverse(res.begin(), res.end());
        
        }
    }

    vis[u] = 2;

}

// Problem Link: https://cses.fi/problemset/task/1669/

int main() {

    cin >> n >> m;
    g.resize(n + 1);
    par.resize(n + 1, -1);
    vis.resize(n + 1, 0);
    int u, v;
    for(int i = 0; i < m; i++) {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    for(int i = 1; i <= n && !flag; i++) {
        if(vis[i] == 0) {
            par[i] = i;
            dfs(i);
        }
    }

    if(res.size()) {
        cout << res.size() << '\n';
        for(int v: res) {cout << v << ' ';}
    }
    else {cout << "IMPOSSIBLE\n";}

    return 0;
}