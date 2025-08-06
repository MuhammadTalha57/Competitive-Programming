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


void solve() {
    int n, x;
    cin >> n;
    cin >> x;
    map<int, int> pos;
    pos[x] = 1;
    ll res = 0;
    ll temp;
    ll i = 1;
    ll covered = 0;
    ll overlapSize = 0;
    f(j, 2,  n + 1) {
        cin >> x;
        if(pos[x] == 0) {
            // First Occurence
            pos[x] = j;
        }
        else {
            // Repeat

            if(pos[x] < i) {
                // x is not in curr subarray
                pos[x] = j;
            }
            else {
                // x is already in the curr subarray
                temp = j - i;
                overlapSize = max(0, covered - i + 1);
                
                res += ( (temp * (temp + 1)) / 2) - ( (overlapSize*(overlapSize + 1)) / 2 );
                covered = j - 1;
                i = pos[x] + 1;
                pos[x] = j;
            }
        }

        if(j == n) {
            temp = j - i + 1;
            overlapSize = max(0, covered - i + 1);
            res += ( (temp * (temp + 1)) / 2) - ( (overlapSize*(overlapSize + 1)) / 2 );
        }
    }
    cout << res << '\n';

}

//Problem Link: https://cses.fi/problemset/task/3420

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