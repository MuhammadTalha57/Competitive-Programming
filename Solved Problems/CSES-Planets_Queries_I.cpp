#include "bits/stdc++.h"

using namespace std;

int n, q;

void solve() {
    cin >> n >> q;
    vector<vector<int>> par(n + 1, vector<int>(30));
    int u;
    for(int i = 0; i < n; i++) {
        cin >> u;
        par[i + 1][0] = u;
    }

    for(int l = 1; l < 30; l++) {
        for(int u = 1; u <= n; u++) {
            par[u][l] = par[par[u][l - 1]][l - 1]; 
        }
    }

    int k;
    while(q--) {
        cin >> u >> k;
        for(int i = 0; i < 30; i++) {
            if((1 << i) & k) u = par[u][i];
        }
        cout << u << '\n';
    }
}

// Problem Link: https://cses.fi/problemset/task/1750

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    

    solve();

    return 0;
}