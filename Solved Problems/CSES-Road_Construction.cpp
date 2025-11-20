#include "bits/stdc++.h"

using namespace std;
map<int, int> mp;

vector<int> parent;

int mxSize = 1;
int findSet(int u) {
    if(parent[u] == u) return u;
    return parent[u] = findSet(parent[u]);
}

void dsuUnion(int u, int v) {
    u = findSet(u);
    v = findSet(v);
    if(u != v) {parent[v] = u; mp[u] += mp[v]; mxSize = max(mxSize, mp[u]);}
}


void solve() {
    int n, m;
    cin >> n >> m;
    parent.resize(n + 1);
    for(int i = 1; i <= n; i++) {parent[i] = i; mp[i] = 1;}

    int u, v;
    int comps = n;
    for(int i = 0; i < m; i++) {
        cin >> u >> v;
        if(findSet(u) != findSet(v)) {
            dsuUnion(u, v);
            comps--;
        }
        cout << comps << ' ' << mxSize << '\n';
    }

}

// Problem Link: https://cses.fi/problemset/task/1676

int main() {
    solve();


    return 0;
}