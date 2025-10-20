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

int n;
int getDia(int u, vector<vi>& adjList) {

    queue<pii> q;
    vi vis(n + 1, 0);
    vis[u] = 1;
    int d = 0;
    int res = u;
    q.push({u, 0});
    while(q.size()) {
        auto [u, w] = q.front();
        q.pop();

        for(int v: adjList[u]) {
            if(vis[v] == 0) {
                vis[v] = 1;
                q.push({v, w + 1});
                if(w + 1 > d) {
                    d = w + 1;
                    res = v;
                }
                else if(w + 1 == d) {
                    if(v > res) {
                        res = v;
                    }
                }
            }
        }

    }

    return res;

}

void func(int u, vector<vi>& adjList, vi& dist) {
    queue<pii> q;
    vi vis(n + 1, 0);
    vis[u] = 1;
    dist[u] = 0;
    q.push({u, 0});
    while(q.size()) {
        auto [u, w] = q.front();
        q.pop();

        for(int v: adjList[u]) {
            if(vis[v] == 0) {
                vis[v] = 1;
                dist[v] = dist[u] + 1;
                q.push({v, dist[v]});
            }
        }

    }
}

void solve() {
               
    cin >> n;
    vector<vi> adjList(n + 1);
    int u, v;
    rep(i, 0, (n - 1))  {
        cin >> u >> v;
        adjList[u].pb(v);
        adjList[v].pb(u);
    }

    int n1 = getDia(1, adjList);
    int n2 = getDia(n1, adjList);


    vi dist1(n + 1, 0), dist2(n + 1, 0);

    func(n1, adjList, dist1);
    func(n2, adjList, dist2);

    rep(i, 1, (n + 1)) {
        if(dist1[i] > dist2[i]) {
            print(n1);
        }
        else if(dist2[i] > dist1[i]) {
            print(n2);
        }
        else {
            print(max(n1, n2));
        }
        
    }



}

// Problem Link: 

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //int t; cin >> t; while(t--)
    solve();
    return 0;
}