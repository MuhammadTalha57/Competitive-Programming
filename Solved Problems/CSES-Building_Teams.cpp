#include "bits/stdc++.h"
#include "ext/pb_ds/assoc_container.hpp"
#include "ext/pb_ds/tree_policy.hpp"
 
#define ONLINE_JUDGE
 
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
#define ordered_set                                                            \
  tree<int, null_type, less<int>, rb_tree_tag,                                 \
       tree_order_statistics_node_update>
#define rep(i, begin, end)                                                     \
  for (__typeof(end) i = (begin) - ((begin) > (end));                          \
       i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define len(s) (ll) s.size()
#define pb push_back
#define eb emplace_back
#define fraction(a)                                                            \
  cout.unsetf(ios::floatfield);                                                \
  cout.precision(a);                                                           \
  cout.setf(ios::fixed, ios::floatfield);
 
template <class T> void print_v(vector<T> &v) {
  for (auto x : v)
    cout << x << " ";
  cout << "\n";
}
template <char sep = ' ', char end = '\n', class T, class... U>
void print(const T &first, const U &...rest) {
  std::cout << first;
  ((std::cout << sep << rest), ...);
  std::cout << end;
}
void print() { cout << '\n'; }
void printInt128(__int128 x) {
  if (x == 0) {
    cout << "0";
    return;
  }
  string res = "";
  while (x) {
    res += (char)('0' + (x % 10));
    x /= 10;
  }
  reverse(res.begin(), res.end());
  cout << res;
}
 
#define MOD 1000000007
#define PI 3.1415926535897932384626433832795
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
 
ll gcd(ll a, ll b) { return __gcd(a, b); }
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }
string to_upper(string a) {
  for (int i = 0; i < (int)a.size(); ++i)
    if (a[i] >= 'a' && a[i] <= 'z')
      a[i] -= 'a' - 'A';
  return a;
}
string to_lower(string a) {
  for (int i = 0; i < (int)a.size(); ++i)
    if (a[i] >= 'A' && a[i] <= 'Z')
      a[i] += 'a' - 'A';
  return a;
}
bool prime(ll a) {
  if (a == 1)
    return 0;
  for (int i = 2; i <= round(sqrt(a)); ++i)
    if (a % i == 0)
      return 0;
  return 1;
}
ll modexp(ll a, ll b, ll m) {
  ll res = 1;
  while (b > 0) {
    if (b & 1)
      res = (res * a) % m;
    a = (a * a) % m;
    b >>= 1;
  }
  return res;
}
void yes() { cout << "YES\n"; }
void no() { cout << "NO\n"; }
void Case(int &x) { cout << "Case " << x++ << ": "; }
 
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());
 
typedef long int int32;
typedef unsigned long int uint32;
typedef long long int int64;
typedef unsigned long long int uint64;
typedef __int128 lll;
 
struct Comp {
  bool operator()(const vi &a, const vi &b) const {
    int x1 = a[2], y1 = a[3], x2 = b[2], y2 = b[3];
 
    if(x1 >= x2 && x1 >= y2) {return true;}
    if(y1 >= x2 && y1 >= y2) {return true;}
    return false;
  }
};
 
// bool comp(vi &a, vi &b) {
  
// }
 
void solve() {
 
  int n, m;
  cin >> n >> m;
 
  vvi adjList(n + 1);
  int u, v;
  rep(i, 1, (m + 1)) {
    cin >> u >> v;
    adjList[u].pb(v);
    adjList[v].pb(u);
  }
  vi res(n + 1, 0);
  rep(u, 1, (n + 1)) {
    if(res[u] == 0) {
      queue<int> q;
      q.push(u);
      res[u] = 1;
      while(!q.empty()) {
        int v = q.front();
        q.pop();
        for(auto x: adjList[v]) {
          if(res[x] == 0) {
            res[x] = 3 - res[v];
            q.push(x);
          }
          else if(res[x] == res[v]) {
            cout << "IMPOSSIBLE";
            return;
          }
        }
      }
    }
    
  }
 
  for(int i = 1; i <= n; i++) {
    cout << res[i] << " ";
  }
  
}
 
// Problem Link: https://cses.fi/problemset/task/1668
 
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  // freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", stdout);
  int t = 1;
  // cin >> t;
  while (t--)
    solve();
  return 0;
}