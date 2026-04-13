#include "bits/stdc++.h"

using namespace std;

const int MOD = 1e9 + 7;

// Use 1 Based Indexing
void add(vector<int> &tree, int n, int k, int x)
{
    while (k <= n)
    {
        tree[k] += x;
        tree[k] %= MOD;
        k += k & -k;
    }
}

int sum(vector<int> &tree, int k)
{
    int s = 0;
    while (k >= 1)
    {
        s += tree[k];
        s %= MOD;
        k -= k & -k;
    }
    return s;
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    return 0;
}