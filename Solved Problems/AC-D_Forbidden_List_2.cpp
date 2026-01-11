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

int tc = 1;

struct Data {
    ll lo;
    ll hi;
    ll cnt;
};

void solve() {
    int n, q;
    cin >> n >> q;
    vi arr(n);
    rep(i, 0, n) cin >> arr[i];

    sort(all(arr));

    vector<Data> temp;
    ll preCnt = 0;
    ll a = 1;
    rep(i, 0, n) {
        if(arr[i] - a > 0) {
            temp.pb({a, arr[i] - 1, arr[i] - a + preCnt});
            preCnt = temp.back().cnt;
        }

        a = arr[i] + 1;
    }

    temp.pb({arr.back() + 1, (ll)2e9, (ll)(2e9 - arr.back()) + preCnt});

    // return;

    while(q--) {
        int x, y;
        cin >> x >> y;
        // cout << x << ' ' << y << '\n';

        ll low = 0, high;
        ll lo = 0, hi = temp.size() - 1;
        ll m;
        while(lo <= hi) {
            m = (lo + hi) / 2;

            if(temp[m].hi < x) {
                lo = m + 1;
            } else {
                low = m;
                hi = m - 1;
            }

        }

        // cout << low << ' ' << temp[low].lo << ' ' << temp[low].hi << '\n';
        // continue;


        if(low == temp.size() - 1) {
            cout << max((ll)x, temp[low].lo) + y - 1ll << '\n';
            goto done;
        }

        if( max((ll)x, temp[low].lo) + y - 1ll <= temp[low].hi ) {
            cout << max((ll)x, temp[low].lo) + y - 1ll << '\n';
            goto done;
        }

        lo = low + 1;
        hi = temp.size() - 1;

        high = lo;
        
        while(lo <= hi) {
            m = (lo + hi) / 2;
            // cout << m << ' ' << temp[m].lo << ' ' << temp[m].hi << '\n';

            if( (temp[m].cnt - temp[low].cnt + ( temp[low].hi -  max((ll)x , temp[low].lo) + 1ll )) < y ) {
                lo = m + 1;
            } else if( (temp[m].cnt - temp[low].cnt + ( temp[low].hi -  max((ll)x , temp[low].lo) + 1ll )) == y ) {
                cout << temp[m].hi << '\n';
                goto done;
            }
            else {
                high = m;
                hi = m - 1;
            }

        }

        // cout << high << ' ' << temp[high].lo << ' ' << temp[high].hi << '\n';


        lo = temp[high].lo;
        hi = temp[high].hi;

        while(lo <= hi) {
            m = (lo + hi) / 2;

            if( ( (temp[high].cnt - ( temp[high].hi  - m)  ) - temp[low].cnt + ( temp[low].hi -  max((ll)x , temp[low].lo) + 1ll )) < y ) {
                lo = m + 1;
            } else if( ( (temp[high].cnt - ( temp[high].hi  - m)  ) - temp[low].cnt + ( temp[low].hi -  max((ll)x , temp[low].lo) + 1ll )) == y ) {
                cout << m << '\n';
                goto done;
            } else {
                hi = m - 1;
            }

        }


        done:


    }


               
}

// Problem Link: https://atcoder.jp/contests/abc440/tasks/abc440_d 

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //int t; cin >> t; while(t--)
    solve();
    return 0;
}