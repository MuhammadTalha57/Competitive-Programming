#include "bits/stdc++.h"

using namespace std;

vector<int> parent;

int getPar(int u) {
    if(u == parent[u]) return u;
    return parent[u] = getPar(parent[u]);
}

void dsuUnion(int a, int b) {
    a = getPar(a);
    b = getPar(b);
    if(a != b) parent[b] = a;
}

// 2 + 3 + 4 + 5
void solve() {
    int n, m;
    cin >> n >> m;

    parent.resize(n + 1, 0);
    for(int i = 1; i <= n; i++) {
        parent[i] = i;
    }

    set<pair<int, pair<int, int>>> edges;
    int a, b, c;
    for(int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        edges.insert({c, {a, b}});
    }

    long long ans = 0;
    while(!edges.empty()) {
        auto [c, p] = *edges.begin();
        edges.erase(edges.begin());
        auto [a, b] = p;

        if(getPar(a) != getPar(b)) {
            dsuUnion(a, b);
            // cout << a << ' ' << b << ' ' << c << '\n';
            // for(int x: parent) cout << x << ' ';
            // cout << '\n';
            ans += c;
        }

    }

    int temp = getPar(1);
    for(int i = 2; i <= n; i++) {
        if(getPar(i) != temp) {
            cout << "IMPOSSIBLE\n";
            return;
        }
    }
    

    cout << ans << '\n';


}

// Problem Link: https://cses.fi/problemset/task/1675

int main() {

    solve();

    return 0;
}