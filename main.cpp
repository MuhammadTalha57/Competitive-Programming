#include "bits/stdc++.h"

using namespace std;

#define ll long long

int getOrg(int l, int r) {
    cout << 1 << ' ' << l << ' ' << r << '\n';
    cout.flush();
    ll x;
    cin >> x;
    return x;
}

int getNew(ll l, ll r) {
    cout << 2 << ' ' << l << ' ' << r << '\n';
    cout.flush();
    ll x;
    cin >> x;
    return x;
}

pair<int, int> func(int l, int r) {
    ll x = getOrg(l, r);
    ll y = getNew(l, r);

    if(l == r) {

        if(x == y) {return {-1, -1};}
        else {return {l, r};}
        
    }

    if(x == y) {
        return {-1, -1};
    }
    else {
        ll d = y - x;
        if(d == (r - l + 1)) {
            return {l, r};
        }
    }

    int m = (l + r) / 2;
    
    auto [l1, r1] = func(l, m);
    auto [l2, r2] = func(m + 1, r);

    if(l1 == -1) {
        return {l2, r2};
    }
    else if(l2 == -1) {
        return {l1, r1};
    }
    else {
        return {l1, r2};
    }

}

void solve() {
    int n;
    cin >> n;

    auto [x, y] = func(1, n);
    cout << '!' << ' ' << x << ' ' << y << '\n';
    cout.flush();

}

int main() {
    int t = 1;
    cin >> t;
    while(t--) {
        solve();
    }
    
}