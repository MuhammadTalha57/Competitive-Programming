## 1. Segment Tree

### Memory Efficient

```cpp
vector<int> tree((2 * N) + 10);

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
    // Only updates one value at given position
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

## 2. Lazy Segment Tree

```cpp
vector<int> tree(4*n);
vector<bool> marked(4*n, false);

void build(vector<int>& arr, int v, int tl, int tr) {
    // v is vertex where current segment will be stored
    if(tl == tr) {
        tree[v] = arr[tl];
    }
    else {
        int tm = (tl + tr) / 2;
        build(arr, v*2, tl, tm);
        build(arr, v*2 + 1, tm + 1, tr);
        tree[v] = tree[v*2] + tree[v*2 + 1];
    }
}

void push(int v) {
    if (marked[v]) {
        t[v*2] = t[v*2+1] = t[v];
        marked[v*2] = marked[v*2+1] = true;
        marked[v] = false;
    }
}
int sum(int v, int tl, int tr, int l, int r) {
    // V holds this range [tl, tr]
    // We want [l, r]
    if(l > r) return 0;
    if(l == tl && r == tr) return tree[v];
    push(v);
    int tm = (tl + tr) / 2;
    return sum(v*2, tl, tm, l, min(r, tm)) + sum(v*2 + 1 , tm + 1, tr, max(l, tm + 1), r);
}


void update(int v, int tl, int tr, int l, int r, int new_val) {
    if (l > r)
        return;
    if (l == tl && tr == r) {
        t[v] = new_val;
        marked[v] = true;
    } else {
        push(v);
        int tm = (tl + tr) / 2;
        update(v*2, tl, tm, l, min(r, tm), new_val);
        update(v*2+1, tm+1, tr, max(l, tm+1), r, new_val);
    }
}
```

> Space Complexity = O(4n)
> Time Complexity = O(log n)
