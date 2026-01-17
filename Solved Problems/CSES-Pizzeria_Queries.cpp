#include "bits/stdc++.h"
#include "ext/pb_ds/assoc_container.hpp"
#include "ext/pb_ds/tree_policy.hpp"

// #define ONLINE_JUDGE

#ifndef ONLINE_JUDGE
#include "debugging.cpp"
#else
#define debug(...)
#define debugArr(...)
#endif

using namespace std;
using namespace __gnu_pbds;

#define ff first
#define ss second
#define ll long long
#define ld long double
#define pii pair<int, int>
#define pll pair<long long, long long>
#define vi vector<int>
#define vll vector<long long>
#define vvi vector<vector<int>>
#define vpii vector<pair<int, int>>
#define vpll vector<pair<long long, long long>>
#define vvll vector<vector<long long>>
#define vc vector<char>
#define vs vector<string>
#define vb vector<bool>
#define mii map<int, int>
#define si set<int>
#define sc set<char>
#define mll map<long long, long long>
#define umap unordered_map
#define uset unordered_set
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define len(s) (ll)s.size()
#define pb push_back
#define eb emplace_back
#define fraction(a) cout.unsetf(ios::floatfield); cout.precision(a); cout.setf(ios::fixed, ios::floatfield);

template <class T> void print_v(vector<T> &v) { for (auto x : v) cout << x << " "; cout << "\n"; }
template<char sep=' ', char end='\n', class T, class... U>
void print(const T& first, const U&... rest) {
    std::cout << first;
    ((std::cout << sep << rest), ...);
    std::cout << end;
}
void print() { cout << '\n'; }
void printInt128(__int128 x) { if (x == 0) { cout << "0"; return; } string res = ""; while (x) { res += (char)('0' + (x % 10)); x /= 10; } reverse(res.begin(), res.end()); cout << res; }

#define MOD 1000000007
#define PI 3.1415926535897932384626433832795
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()

ll gcd(ll a, ll b) { return __gcd(a, b); }
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }
string to_upper(string a) { for (int i = 0; i < (int)a.size(); ++i) if (a[i] >= 'a' && a[i] <= 'z') a[i] -= 'a' - 'A'; return a; }
string to_lower(string a) { for (int i = 0; i < (int)a.size(); ++i) if (a[i] >= 'A' && a[i] <= 'Z') a[i] += 'a' - 'A'; return a; }
bool prime(ll a) { if (a == 1) return 0; for (int i = 2; i <= round(sqrt(a)); ++i) if (a % i == 0) return 0; return 1; }
ll modexp(ll a, ll b, ll m) { ll res = 1; while (b > 0) { if (b & 1) res = (res * a) % m; a = (a * a) % m; b >>= 1; } return res; }
void yes() { cout << "YES\n"; }
void no() { cout << "NO\n"; }
void Case(int &x) { cout << "Case " << x++ << ": "; }

mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

typedef long int int32;
typedef unsigned long int uint32;
typedef long long int int64;
typedef unsigned long long int uint64;
typedef __int128 lll;

// #define int ll

class SegTree {
public:
    vll segTree;
    ll n;
    bool left;

    void build(vll& arr, ll u, ll l, ll r) {
        if(l == r) {
            if(left) {
                segTree[u] = arr[l] + n - l + 1;
            } else {
                segTree[u] = arr[l] + l;
            }
            return;
        } 

        ll m = (l + r) / 2;
        build(arr, u * 2ll, l, m);
        build(arr, u * 2ll + 1ll, m + 1, r);
        segTree[u] = min(segTree[u * 2ll], segTree[u * 2ll + 1ll]);

    }

    void update(ll u, ll l, ll r, ll k, ll x) {
        if(k < l || k > r) return;
        if(l == k && r == k) {
            if(left) {
                segTree[u] = x + n - l + 1;
            } else {
                segTree[u] = x + l;
            }
            return;
        }
        ll m = (l + r) / 2;
        update(u * 2ll, l, m, k, x);
        update(u * 2ll + 1ll, m + 1ll, r, k, x);

        segTree[u] = min(segTree[u * 2ll], segTree[u * 2ll + 1ll]);

    }

    ll query(ll u, ll l, ll r, ll tl, ll tr) {
        if(tl > tr) return 1e17;
        if(tl == l && tr == r) {
            return segTree[u];
        } else {
            ll m = (l + r) / 2;
            return min( query(u * 2ll, l, m, tl, min(m, tr)), query(u * 2ll + 1ll, m + 1, r, max(m + 1, tl), tr) );
        }
    }

    SegTree(vll& arr, bool left) {
        this->n = arr.size() - 1;
        this->left = left;
        
        segTree.resize(4ll * n);
        build(arr, 1, 1, n);
    }



};

int tc = 1;

void solve() {
    ll n, q;
    cin >> n >> q;
    vll p(n + 1);
    rep(i, 1, (n + 1)) cin >> p[i];

    SegTree right(p, false);
    SegTree left(p, true);

    ll a, k, x;
    while(q--) {
        cin >> a >> k;
        if(a == 1) {
            cin >> x;
            left.update(1, 1, n, k, x);
            right.update(1, 1, n, k, x);
        } else {
            // continue;
            ll t1 = left.query(1, 1, n, 1, k);
            ll t2 = right.query(1, 1, n, k, n);
            print(min(t1 - (n - k + 1), t2 - k));
        }
    }
               
}

// Problem Link: https://cses.fi/problemset/task/2206

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //int t; cin >> t; while(t--)
    solve();
    return 0;
}