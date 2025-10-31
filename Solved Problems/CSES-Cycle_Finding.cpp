#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define vll vector<ll>
#define pll pair<ll, ll>

const ll INF = (1e9) * (25000LL);

void solve() {
    ll n, m;
    cin >> n >> m;
    vector<vector<pll>> adjList(n + 1);

    ll u, v, w;

    for(int i = 0; i < m; i++) {
        cin >> u >> v >> w;
        adjList[u].push_back({v, w});
    }

    for(int i = 1; i <= n; i++) {
        adjList[0].push_back({i, 0});
    }


    vll dist(n + 1, INF);
    dist[0] = 0;
    ll x = -1;
    vll par(n + 1, -1);
    for(int i = 0; i <= n; i++) {
        x = -1;
        for(int u = 0; u <= n; u++) {
            if(dist[u] == INF) {continue;}

            for(auto [v, w]: adjList[u] ) {
                if(dist[v] > (dist[u] + w)) {
                    dist[v] = dist[u] + w;
                    par[v] = u;
                    x = v;
                }    
            }
        }

    }

    if(x == -1) {
        cout << "NO\n";
    }
    else {
        cout << "YES\n";

        for(int i = 0; i <= n; i++) {
            x = par[x];
        }

        vll cycle;
        // cout << '\n';
        cycle.push_back(x);
        ll v = par[x];
        for(; v != x; v = par[v]) {
            // cout << v << ' ' << par[v] << '\n';
            cycle.push_back(v);
        }

        // cycle.push_back(v);
        cycle.push_back(x);

        reverse(cycle.begin(), cycle.end());
        for(ll u: cycle) {
            cout << u << ' ';
        }
    }


}

// Problem Link: https://cses.fi/problemset/task/1197

int main() {

    solve();

    return 0;
}