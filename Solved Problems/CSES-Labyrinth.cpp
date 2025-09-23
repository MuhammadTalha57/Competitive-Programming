#include <bits/stdc++.h>
using namespace std;
 
/* TYPES  */
#define ll long long
#define pii pair<int, int>
#define pll pair<long long, long long>
#define vi vector<int>
#define vll vector<long long>
#define mii map<int, int>
#define si set<int>
#define sc set<char>
 
/* FUNCTIONS */
#define f(i,s,e) for(long long int i=s;i<e;i++)
#define fe(i,s,e) for(long long int i=s;i<=e;i++)
#define fr(i,e,s) for(long long int i=e-1;i>=s;i--)
#define pb push_back
#define eb emplace_back
#define all(x) x.begin(), x.end()
 
/* PRINTS */
template <class T>
void print_v(vector<T> &v) { for (auto x : v) cout << x << ' '; }
 
/* UTILS */
#define MOD 1000000007
#define PI 3.1415926535897932384626433832795
#define read(type) readInt<type>()
ll min(ll a,int b) { if (a<b) return a; return b; }
ll min(int a,ll b) { if (a<b) return a; return b; }
ll max(ll a,int b) { if (a>b) return a; return b; }
ll max(int a,ll b) { if (a>b) return a; return b; }
ll gcd(ll a,ll b) { if (b==0) return a; return gcd(b, a%b); }
ll lcm(ll a,ll b) { return a/gcd(a,b)*b; }
bool prime(ll a) { if (a==1) return 0; for (int i=2;i<=round(sqrt(a));++i) if (a%i==0) return 0; return 1; }
void yes() { cout<<"YES\n"; }
void no() { cout<<"NO\n"; }
void printCase(int i) {cout << "Case " << i << ": ";}
 
char func(int r, int c, int nr, int nc) {
    //cout << r << ' ' << c << ' ' << nr << ' ' << nc << '\n';
    if(nr == r + 1) {return 'D';}
    else if(nr == r - 1) {return 'U';}
    else if(nc == c + 1) {return 'R';}
    else {return 'L';}
}
 
void solve() {
   int n, m;
   cin >> n >> m;
   vector<string> g(n);
   string s;
   int r, c;
   f(i, 0, n) {
        cin >> s;
        g[i] = s;
        f(j, 0, m) {
            if(s[j] == 'A') {
                r = i; c = j;
                break;
            }
        }
   }
 
   vector<vector<pii>> parent(n, vector<pii>(m));
   vector<vi> dist(n, vi(m, -1));
   queue<pii> q;
   q.push({r, c});
   dist[r][c] = 0;
   parent[r][c] = pii(r, c); 
 
   vector<vi> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
   int nr, nc;
   while(!q.empty()) {
        auto [r, c] = q.front();
        q.pop();
 
        if(g[r][c] == 'B') {
            yes();
            cout << dist[r][c] << '\n';
 
            string path = "";
            while(parent[r][c] != pii(r, c)) {
                //cout << r << ' ' << c << '\n';
                path += func(parent[r][c].first, parent[r][c].second, r, c);
                nr = parent[r][c].first;
                nc = parent[r][c].second;
                r = nr;
                c = nc;
            }
 
            reverse(all(path));
            cout << path << '\n';
 
            return;
        }
 
        f(i, 0, 4) {
            nr = r + dir[i][0];
            nc = c + dir[i][1];
 
            if(nr < 0 || nr >= n || nc < 0 || nc >= m) {continue;}
 
            if(dist[nr][nc] == -1 && g[nr][nc] != '#') {
                dist[nr][nc] = dist[r][c] + 1;
                parent[nr][nc] = pii(r, c);
                q.push({nr, nc});
            }
 
        }
   }
 
   no();
 
   
}
 
// Problem Link: https://cses.fi/problemset/task/1193

int main() {
   ios::ios_base::sync_with_stdio(0);
   cin.tie(NULL);
   int t = 1;
   // cin >> t;
   while(t--) {
       solve();
   }
   return 0;
}