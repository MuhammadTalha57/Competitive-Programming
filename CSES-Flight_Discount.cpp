#include "bits/stdc++.h"

using namespace std;

#define ll long long
#define vll vector<long long>
#define pll pair<long long, long long>

const ll INF = LONG_LONG_MAX;

int n, m;
ll u, v, w;
vector<vector<pll>> adjList, invAdjList;

void dijkstra(int u, vector<vector<pll>>& adjList, vll& dist) {
    dist[u] = 0;
    set<pll> q;
    q.insert({0, u});

    while(!q.empty()) {
        auto [d, u] = *q.begin();
        q.erase(q.begin());

        for(auto [v, w]: adjList[u]) {
            if(dist[v] > (d + w)) {
                q.erase({dist[v], v});
                dist[v] = d + w;
                q.insert({dist[v], v});
            }
        }
    }

}


int main() {
    cin >> n >> m;
    adjList.resize(n + 1);
    invAdjList.resize(n + 1);

    for(int i = 0; i < m; i++) {
        cin >> u >> v >> w;
        adjList[u].push_back({v, w});
        invAdjList[v].push_back({u, w});
    }

    vll dist1(n + 1, INF), dist2(n + 1, INF);

    dijkstra(1, adjList, dist1);
    dijkstra(n, invAdjList, dist2);

    ll ans = INF;
    for(int u = 1; u <= n; u++) {
        for(auto [v, w]: adjList[u]) {
            if(dist1[u] == INF || dist2[v] == INF) {continue;}
            ans = min(ans, dist1[u] + (w / 2) + dist2[v]);
        }
    }

    cout << ans << '\n';


}