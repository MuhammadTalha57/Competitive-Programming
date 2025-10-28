#include "bits/stdc++.h"

using namespace std;

// Problem Link : https://cses.fi/problemset/task/1672

const long long inf = 1e9 * 505LL;

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    long long n, m, q;
    cin >> n >> m >> q;
    long long c;
    vector<vector<long long>> res(n + 1, vector<long long>(n + 1, inf));
    for(int i = 1; i <= n; i++) {
        res[i][i] = 0;
    }

    int a, b;   
    for(int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        res[a][b] = min(res[a][b], c);
        res[b][a] = min(res[b][a], c);
    }

    for(int k = 1; k <= n; k++) {
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                res[i][j] = min(res[i][j], res[i][k] + res[k][j]);
            }
        }
    }

    while(q--) {
        cin >> a >> b;
        if(res[a][b] == inf) {cout << -1 << '\n';} 
        else {cout << min(res[a][b], res[b][a]) << '\n';}
    }



    return 0;
}