#include "bits/stdc++.h"

using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<int> p(n + 1);

    vector<int> pre(n + 1, 1e9);
    vector<int> suf(n + 1);

    for(int i = 0 ; i < n; i++) {
        cin >> p[i+1];
        pre[i + 1] = min(pre[i], p[i + 1]);
    }

    suf[n] = p[n];
    for(int i = n - 1; i >= 1; i--) {
        suf[i] = max(p[i], suf[i + 1]);
    }


    for(int i = 2; i <= n; i++) {
        if(pre[i-1] > suf[i]){
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";


}

// Problem Link: https://codeforces.com/contest/2171/problem/D


int main() {
    int t;
    cin >> t;
    while(t--) solve();
}