#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pll pair<ll, ll>
#define vll vector<ll>
#define pb push_back

const ll INF = (1e9) * (1e6);


void solve() {

    ll n, m, k;
    cin >> n >> m >> k;
    
    vector<vector<pll>> adjList(n + 1);

    ll u, v, w;
    for(int i = 0; i < m; i++) {
        cin >> u >> v >> w;
        adjList[u].pb({v,w});
    }

    multiset<pll> q;
    q.insert({0, 1});
    vll cnt(n + 1, 0);
    vll res;

    while(cnt[n] < k) {
        auto [l, u] = *q.begin();
        q.erase(q.begin());

        if(cnt[u] == k) continue;
        cnt[u]++;
        if(u == n) res.pb(l);

        for(auto [v, w]: adjList[u]) {
            q.insert({l + w, v});
        }
    }

    for(ll x: res) {cout << x << ' ';}

}

// Problem Link: https://cses.fi/problemset/task/1196/

int main() {

    solve();

    return 0;
}