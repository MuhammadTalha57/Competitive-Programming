#include "bits/stdc++.h"

using namespace std;

int n;
void dfs(int col, int row, vector<vector<long long>>& dp, int mask, int nextMask) {
    if(row == 3) {
        dp[col + 1][nextMask] += dp[col][mask];
        return;
    }

    if((1 << row) & mask) {
        dfs(col, row + 1, dp, mask, nextMask);
        return;
    }

    // Bottom left Empty
    if(col < n - 1 && row < 2 && !( (nextMask & (1 << row)) || (nextMask & (1 << (row + 1))) ) ) {
        dfs(col, row + 1, dp, mask, nextMask | (1 << row) | (1 << (row + 1)));
    }

    // Top left Empty
    if(col < n - 1 && row > 0  && !( (nextMask & (1 << row)) || (nextMask & (1 << (row - 1))) ) ) {
        dfs(col, row + 1, dp, mask, nextMask | (1 << row) | (1 << (row - 1)));
    }

    // Bottom Right Empty
    if(col < n - 1 && row < 2  && !( (nextMask & (1 << row)) )) {
        dfs(col, row + 2, dp, mask, nextMask | (1 << row));
    }

    // Top Right Empty
    if(col < n - 1 && row < 2  && !( (nextMask & (1 << (row + 1) ) ) ) )  {
        dfs(col, row + 2, dp, mask, nextMask | (1 << (row + 1)) );
    }


}

void solve() {
    cin >> n;
    
    vector<vector<long long>> dp(n + 1, vector<long long>(1 << 3, 0));

    dp[0][0] = 1;

    for(int col = 0; col < n; col++) {
        for(int mask = 0; mask < (1 << 3); mask++) {
            dfs(col, 0, dp, mask, 0);
        }

    }

    cout << dp[n][0] << '\n';

}

// Problem Link: https://codeforces.com/problemset/problem/1182/A

int main() {

    solve();

    return 0;
}