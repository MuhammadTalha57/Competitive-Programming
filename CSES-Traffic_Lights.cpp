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
    int x, n;
    int t;
    cin >> x >> n;
    set<int> s;
    map<int, int> dist;
    dist[x - 0]++;
    int i, j;
    int l1, l2;
    f(_, 0, n) {
        cin >> t;

        // Find i
        if(s.empty() || *s.begin() > t) {
            // There is no light to the left of t
            i = 0;
        }
        else {
            auto low = s.lower_bound(t);
            if(low == s.end()) {low--;}
            if(*low > t) {
                low--;
            }
            i = *low;
        }
        

        // Find j
        if(s.empty() || *s.rbegin() < t) {
            // There is no light to the right of t
            j = x;
        }
        else {
            auto up = s.upper_bound(t);
            j = *up;
        }

        
        // i   t   j
        
        // Remove i - j distance
        dist[j - i]--;
        if(dist[j - i] == 0) {dist.erase(j - i);}

        // Adding
        // i - t and t - j  distance
        dist[t - i]++;
        dist[j - t]++;
        cout << (*dist.rbegin()).first << ' ';

        s.insert(t);
    }

    


}



//Problem Link: https://cses.fi/problemset/task/1163

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