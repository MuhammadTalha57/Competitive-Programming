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
    int n;
    cin >> n;
    vi arr(n);
    f(i, 0, n) cin >> arr[i];

    
    int i = 0, j = n -1;
    int k = 0;
    vi res(n, 0);
    res[0] = arr[0];
    res[1] = arr[n - 1];
    cout << "LR";

    k = 2;
    i = 1;
    j = n - 2;

    while(i < j) {
        int x1 = res[k - 2];
        int y1 = res[k - 1];
        int m1 = max(arr[i], arr[j]);
        int m2 = min(arr[i], arr[j]);
        if(x1 > y1) {
            res[k] = m2;
            res[k + 1] = m1;
            if(m2 == arr[i]) {
                cout << "LR";
            }
            else cout << "RL";
        }
        else {
            res[k] = m1;
            res[k + 1] = m2;
            if(m1 == arr[i]) {
                cout << "LR";
            }
            else cout << "RL";
        }

        i++;
        j--;
        k += 2;

    }

    if(i == j) {cout << 'L';}
    cout << '\n';



}

//Problem Link: https://codeforces.com/contest/2128/problem/B

int main() {
   ios::ios_base::sync_with_stdio(0);
   cin.tie(NULL);
   int t = 1;
   cin >> t;
   while(t--) {
       solve();
   }
   return 0;
}