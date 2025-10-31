#include "bits/stdc++.h"

using namespace std;

int n, m;
vector<vector<int>> adjList;
vector<int> dp;
const int MOD = 1000000007;

void dfs(int u) {
    dp[u] = 0;

    if(u == n) {
        dp[u] = 1;
        return;
    }

    for(int v: adjList[u]) {
        if(dp[v] == -1) {
            dfs(v);
        }
        dp[u] += dp[v];
        dp[u] %= MOD;
    }

}

void solve() {
    cin >> n >> m;
    adjList.resize(n + 1);
    dp.resize(n + 1, -1);

    int u, v;
    for(int i = 0; i < m; i++) {
        cin >> u >> v;
        adjList[u].push_back(v);
    }

    dfs(1);

    cout << dp[1] << '\n';

}

// Problem Link: https://cses.fi/problemset/task/1681/

int main() {

    solve();

    return 0;
}