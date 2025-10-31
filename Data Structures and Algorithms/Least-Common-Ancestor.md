## 1. LCA using Euler Tour and Segment Tree

```cpp
int n;
vector<int> height(n), euler, first(n), segTree(4*n);
vector<bool> visited;

void dfs(int u, vector<vector<int>>& adj, int h = 0) {
    visited[u] = true;
    height[u] = h;
    first[u] = euler.size();
    euler.push_back(u)
    for(int v: adj[u]) {
        if(!visited[v]) {
            dfs(v, adj, h + 1);
            euler.push_back(u);
        }
    }
}

void build(vector<int>& arr, int v, int tl, int tr) {
    if(tl == tr) {
        segTree[v] = arr[tl];
    }
    else {
        int tm = (tl + tr) / 2;
        build(arr, v*2, tl, tm);
        build(arr, v*2 + 1, tm + 1, tr);
        int l = segTree[v*2];
        int r = segTree[v*2 + 1];
        segTree[v] = (height[l] < height[r]) ? l : r;
    }
}

int query(int v, int tl, int tr, int l, int r) {
    if(l > r) return -1;
    if(tl == l && tr == r) return segTree[v];

    int tm = (tl + tr) / 2;
    int l = query(arr, v*2, tl, tm, l, min(tm, tr));
    int r = query(arr, v*2 + 1, tm + 1, tr, max(tm + 1, l), r);

    if(l == -1) return r;
    if(r == -1) return l;
    return (height[l] < height[r] ? l : r);
}

int lca(int u int v) {
    int l = first[u], r = first[v];
    if(l > r) swap(l, r);
    return query(1, 0, euler.size() - 1, l, r);
}

dfs(adj, root);
build(1, 0, euler.size() - 1);

```

> Space Complexity = O(4n)
> Time Complexity = O(log n) per query with O(n) preprocessing time.
