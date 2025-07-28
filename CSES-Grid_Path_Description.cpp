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

vector<vi> g(7, vi(7, 0));
vector<pii> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
string moves = "UDLR";
string s;

ll ans = 0;

bool isValid(int x, int y) {
    return (x >= 0 && y >= 0 && x < 7 && y < 7);
}

bool isVisited(int x, int y) {
    if(!isValid(x, y)) {return true;}
    return g[x][y];
}

int dfs(int x, int y, int i) {

    //cout << x << ' ' << y << ' ' << i << '\n';
    
    if(i == 48) {
        return (x == 6 && y == 0);
    }

    if(x == 6 && y == 0) return 0;


    if(!isVisited(x - 1, y) && !isVisited(x + 1, y) && isVisited(x, y + 1) && isVisited(x, y - 1)) return 0;
    if(isVisited(x - 1, y) && isVisited(x + 1, y) && !isVisited(x, y + 1) && !isVisited(x, y - 1)) return 0;
    // if(isVisited(x - 1, y + 1) && !isVisited(x - 1, y) && !isVisited(x, y + 1) ) return 0;
    // if(isVisited(x + 1, y + 1) && !isVisited(x + 1, y) && !isVisited(x, y + 1) ) return 0;
    // if(isVisited(x + 1, y - 1) && !isVisited(x + 1, y) && !isVisited(x, y - 1) ) return 0;
    // if(isVisited(x - 1, y - 1) && !isVisited(x - 1, y) && !isVisited(x, y - 1) ) return 0;


    g[x][y] = 1;
    int paths = 0;

    if(s[i] != '?') {
        f(j, 0, 4) {
            char c = moves[j];
            if(s[i] == c) {
                auto [dx, dy] = dirs[j];
                int nx = x + dx;
                int ny = y + dy;
                if(!isValid(nx, ny) || isVisited(nx, ny)) continue;
                paths += dfs(nx, ny, i + 1);
            }
        }

    }
    else if(y > 1 && (isVisited(x, y - 2) && (isVisited(x - 1, y - 1) || isVisited(x + 1, y - 1)) && !isVisited(x, y - 1))) {
        paths += dfs(x, y - 1, i + 1);
    }
    else if(y < 5 && (isVisited(x, y + 2) && (isVisited(x - 1, y + 1) || isVisited(x + 1, y + 1)) && !isVisited(x, y + 1) )) {
        paths += dfs(x, y + 1, i + 1);
    }
    else if(x > 1 && (isVisited(x - 2, y) && (isVisited(x - 1, y - 1) || isVisited(x - 1, y + 1)) && !isVisited(x - 1, y))) {
        paths += dfs(x - 1, y, i + 1);
    }
    else if(x < 5 && (isVisited(x + 2, y) && (isVisited(x + 1, y - 1) || isVisited(x + 1, y + 1)) && !isVisited(x + 1, y))) {
        paths += dfs(x + 1, y, i + 1);
    }
    else {
        f(j, 0, 4) {
            char c = moves[j];
            auto [dx, dy] = dirs[j];
            int nx = x + dx;
            int ny = y + dy;
            if(isVisited(nx, ny)) continue;
            paths += dfs(nx, ny, i + 1);
        }
    }

    
    g[x][y] = 0;

    return paths;

}

void solve() {

    cin >> s;
    cout << dfs(0, 0, 0) << '\n';

}

//Problem Link: https://cses.fi/problemset/task/1625

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