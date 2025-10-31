#include "bits/stdc++.h"


using namespace std;

vector<int> path;
int n, m;

void dfs1(int u, vector<vector<int>>& adjList, vector<int>& dist) {
    dist[u] = -1;

    if(u == n) {
        dist[n] = 0;
        return;
    }   

    for(int v: adjList[u]) {
        if(dist[v] == -2) {
            dfs1(v, adjList, dist);
        }
        if(dist[v] == -1) continue;
        dist[u] = max(dist[u], dist[v] + 1);
    }

    return;

}

void dfs2(int u, vector<vector<int>>& adjList, vector<int>& dist) {

    path.push_back(u);

    if(u == n) {
        return;
    }   

    int mxDist = -1, nextNode = -1;

    for(int v: adjList[u]) {
        if(dist[v] > mxDist) {
            mxDist = dist[v];
            nextNode = v;
        }
    }

    dfs2(nextNode, adjList, dist);

}

void solve()  {

    cin >> n >> m;
    vector<vector<int>> adjList(n + 1);

    int u, v;
    for(int i = 0; i < m; i++) {
        cin >> u >> v;
        adjList[u].push_back(v);
    }

    vector<int> dist(n + 1, -2);

    dfs1(1, adjList, dist);

    if(dist[n] == -2) {
        cout << "IMPOSSIBLE\n";
        return;
    }

    dfs2(1, adjList, dist);

    cout << path.size() << '\n';
    for(int x: path) {
        cout << x << ' ';
    }

}

// Problem Link: https://cses.fi/problemset/task/1680/

int main() {
    solve();

    return 0;
}