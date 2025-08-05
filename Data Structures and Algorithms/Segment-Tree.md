## 1. Segment Tree

```cpp
vector<int> tree(N + 10);

void build(vector<int>& arr, int v, int tl, int tr) {
    // v is vertex where current segment will be stored
    if(tl == tr) {
        tree[v] = arr[tl];
    }
    else {
        int tm = (tl + tr) / 2;
        build(arr, v + 1, tl, tm);
        build(arr, v + (2*(tm - tl + 1)), tm + 1, tr);
        tree[v] = tree[v + 1] + tree[v + (2*(tm - tl + 1))];
    }
}

int sum(int v, int tl, int tr, int l, int r) {
    if(l > r) return 0;
    if(l == tl && r == tr) return tree[v];
    int tm = (tl + tr) / 2;
    return sum(v + 1, tl, tm, l, min(r, tm)) + sum(v + (2*(tm - tl + 1)), tm + 1, tr, max(l, tm + 1), r);
}

void update(int v, int tl, int tr, int pos, int newVal) {
    // Only updates on value at given position
    if(tl == tr) {
        tree[v] = newVal;
    }
    else {
        int tm = (tl + tr) / 2;
        if(pos <= tm) {
            update(v + 1, tl, tm, pos, newVal);
        }
        else {
            update(v + (2*(tm - tl + 1)), tm + 1, tr, pos, newVal);
        }
        tree[v] = tree[v + 1] + tree[v + (2 * (tm - tl + 1))];
    }
}
```
> Space Complexity = O(2n)
> Time Complexity = O(log n)