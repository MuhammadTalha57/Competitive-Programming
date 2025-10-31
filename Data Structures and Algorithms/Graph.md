## 1. BFS

```cpp
// Vertices = {1, 2, ..., n}
int n, m, s;
vector<vector<int>> adjList(n + 1);

queue<int> q;
vector<int> dist(n + 1, INF);
vector<int> par(n + 1, -1);
q.push(s);
dist[s] = 0;
while(!q.empty()) {
    int u = q.front();
    q.pop();

    for(int v: adjList[u]) {
        if(dist[v] > (dist[u] + 1)) {
            dist[v] = dist[u] + 1;
            par[v] = u;
            q.push(v);
        }
    }

}

// Path Reconstruction
vector<vector<int>> paths(n + 1);

for(int u = 1; u <= n; u++) {
    vector<int> res;
    int v;
    for(v = u; par[v] != -1; v = par[v]) {
        res.push_back(v);
    }
    res.push_back(v);
    reverse(all(res));

    paths[u] = res;
}

```
> Time Complexity = O(N + M)

## 2. 0-1 BFS

```cpp
// Vertices = {1, 2, ..., n}
// Deque is used
int n, m, s;
vector<vector<pair<int, int>>> adjList(n + 1);

dequeue<int> q;
vector<int> dist(n + 1, INF);
vector<int> par(n + 1, -1);
q.push(s);
dist[s] = 0;
while(!q.empty()) {
    int u = q.front();
    q.pop();

    for(auto [v, w]: adjList[u]) {
        if(dist[v] > (dist[u] + w)) {
            dist[v] = dist[u] + w;
            par[v] = u;
            if(w == 1) {
                q.push_back(v);
            }
            else {
                q.push_front(v);
            }
        }
    }

}

// Path Reconstruction
vector<vector<int>> paths(n + 1);

for(int u = 1; u <= n; u++) {
    vector<int> res;
    int v;
    for(v = u; par[v] != -1; v = par[v]) {
        res.push_back(v);
    }
    res.push_back(v);
    reverse(all(res));

    paths[u] = res;
}

```
> Time Complexity = O(N + M)

## 3. K-BFS

```cpp
vector<int> shortestPath(int n, int src, vector<vector<int>> &edges) {
    vector<vector<vector<int>>> adj(n);
    int maxWeight = 0;
    
    // Build adjacency list and find maximum weight
    for (auto e: edges) {
        adj[e[0]].push_back({e[1], e[2]});
        adj[e[1]].push_back({e[0], e[2]});
        maxWeight = max(maxWeight, e[2]);
    }
    
    // Initialize distance array
    vector<int> dist(n, INT_MAX);
    dist[src] = 0;
    
    // Create buckets for distances
    int maxDist = (n - 1) * maxWeight;
    vector<unordered_set<int>> buckets(maxDist + 1);
    
    // Add source to bucket 0
    buckets[0].insert(src);
    
    // Process buckets in order
    for (int d = 0; d <= maxDist; d++) {
        
        // Process all nodes in current bucket
        while (!buckets[d].empty()) {
            int u = *buckets[d].begin();
            buckets[d].erase(buckets[d].begin());
            
            // Skip if we already found a better path
            if (d > dist[u]) continue;
            
            // Process all adjacent nodes
            for (auto& edge : adj[u]) {
                int v = edge[0];
                int weight = edge[1];
                int newDist = dist[u] + weight;
                
                // If shorter path found
                if (newDist < dist[v]) {
                    
                    // Remove from old bucket if it was there
                    if (dist[v] != INT_MAX) {
                        buckets[dist[v]].erase(v);
                    }
                    
                    // Update distance and add to new bucket
                    dist[v] = newDist;
                    buckets[newDist].insert(v);
                }
            }
        }
    }
    
    return dist;
}
```
> Time Complexity = O(N + M + V * K)


## 4. Bellman Ford

```cpp
struct Edge {
    int a, b, cost;
};

int n;
vector<Edge> edges;
const int INF = 1000000000;

void solve() {
    vector<int> d(n, 0);
    vector<int> p(n, -1);
    int x;

    for (int i = 0; i < n; ++i) {
        x = -1;
        for (Edge e : edges) {
            if (d[e.a] + e.cost < d[e.b]) {
                d[e.b] = max(-INF, d[e.a] + e.cost);
                p[e.b] = e.a;
                x = e.b;
            }
        }
    }

    if (x == -1) {
        cout << "No negative cycle found.";
    } else {
        for (int i = 0; i < n; ++i)
            x = p[x];

        vector<int> cycle;
        for (int v = x;; v = p[v]) {
            cycle.push_back(v);
            if (v == x && cycle.size() > 1)
                break;
        }
        reverse(cycle.begin(), cycle.end());

        cout << "Negative cycle: ";
        for (int v : cycle)
            cout << v << ' ';
        cout << endl;
    }
}
```
> Time Complexity = O(N M)


## 5. Shortest Path Faster Algorithm
```cpp
const int INF = 1000000000;
vector<vector<pair<int, int>>> adj;

bool spfa(int s, vector<int>& d) {
    int n = adj.size();
    d.assign(n, INF);
    vector<int> cnt(n, 0);
    vector<bool> inqueue(n, false);
    queue<int> q;

    d[s] = 0;
    q.push(s);
    inqueue[s] = true;
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        inqueue[v] = false;

        for (auto edge : adj[v]) {
            int to = edge.first;
            int len = edge.second;

            if (d[v] + len < d[to]) {
                d[to] = d[v] + len;
                if (!inqueue[to]) {
                    q.push(to);
                    inqueue[to] = true;
                    cnt[to]++;
                    if (cnt[to] > n)
                        return false;  // negative cycle
                }
            }
        }
    }
    return true;
}
```
> Time Complexity = O(N M), Avg Time Complexity = O(M)


## 6. Dijkstra For Dense Graph
```cpp
const int INF = 1000000000;
vector<vector<pair<int, int>>> adj;

void dijkstra(int s, vector<int> & d, vector<int> & p) {
    int n = adj.size();
    d.assign(n, INF);
    p.assign(n, -1);
    vector<bool> u(n, false);

    d[s] = 0;
    for (int i = 0; i < n; i++) {
        int v = -1;
        for (int j = 0; j < n; j++) {
            if (!u[j] && (v == -1 || d[j] < d[v]))
                v = j;
        }

        if (d[v] == INF)
            break;

        u[v] = true;
        for (auto edge : adj[v]) {
            int to = edge.first;
            int len = edge.second;

            if (d[v] + len < d[to]) {
                d[to] = d[v] + len;
                p[to] = v;
            }
        }
    }
}
```

> Time Complexity = O(N<sub>2</sub> + M)

## 7. Dijkstra For Sparse Graph
```cpp
const int INF = 1000000000;
vector<vector<pair<int, int>>> adj;

void dijkstra(int s, vector<int> & d, vector<int> & p) {
    int n = adj.size();
    d.assign(n, INF);
    p.assign(n, -1);

    d[s] = 0;
    set<pair<int, int>> q;
    q.insert({0, s});
    while (!q.empty()) {
        int v = q.begin()->second;
        q.erase(q.begin());

        for (auto edge : adj[v]) {
            int to = edge.first;
            int len = edge.second;

            if (d[v] + len < d[to]) {
                q.erase({d[to], to});
                d[to] = d[v] + len;
                p[to] = v;
                q.insert({d[to], to});
            }
        }
    }
}
```

> Time Complexity = O(M Log N)


## 8. Floyd Warshall
```cpp
for (int k = 0; k < n; ++k) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (d[i][k] < INF && d[k][j] < INF)
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]); 
        }
    }
}
```

> Time Complexity = O(N^3), Space Complexity = O(N^2)

## 9. K-Shortest Path Lengths
```cpp
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
```

> Time Complexity = $O(k m log (m k))$