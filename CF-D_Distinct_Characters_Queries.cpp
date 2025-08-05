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

string s;
vector<vi> tree((2*1e5) + 10, vi(26, 0));

void build(string& s, int v, int tl, int tr) {
    if(tl == tr) {
        tree[v][s[tl - 1] - 'a']++;
    }
    else {
        int tm = (tl + tr) / 2;
        build(s, v + 1, tl, tm);
        build(s, v + (2*(tm - tl + 1)), tm + 1, tr);
        f(i, 0, 26) {
            tree[v][i] = tree[v + 1][i] + tree[v + (2*(tm - tl + 1))][i];
        }
    }
}

vi sum(int v, int tl, int tr, int l, int r) {
    if(l > r) {return tree[0];}
    if(l == tl && r == tr) {
        //cout << "Returning: " << tl << ' ' << tr << ' ' << v << '\n';
        //print_v(tree[v]);
        //cout << '\n';

        return tree[v];
    }
    int tm = (tl + tr) / 2;
    vi left = sum(v + 1, tl, tm, l, min(r, tm));
    vi right = sum(v + (2*(tm - tl + 1)), tm + 1, tr, max(l, tm + 1), r);
    vi res(26, 0);
    f(i, 0, 26) {
        res[i] = left[i] + right[i];
    }
    return res;
}

void update(int v, int tl, int tr, int pos, char newChar) {
    if(tl == tr) {
        //cout << "Update: " << ' ' << tl << ' ' << tr << ' ' << pos << ' ' << v << '\n';
        f(i, 0, 26) {
            if(i == (newChar - 'a')) {
                tree[v][i] = 1;
            }
            else {tree[v][i] = 0;}
        }
        //print_v(tree[v]);
        //cout << '\n';
    }
    else {
        int tm = (tl + tr) / 2;
        if(pos <= tm) {
            update(v + 1, tl, tm, pos, newChar);
        }
        else {
            update(v + (2*(tm - tl + 1)), tm + 1, tr, pos, newChar);
        }
        f(i, 0, 26) {
            tree[v][i] = tree[v + 1][i] + tree[v + (2*(tm - tl + 1))][i];
        }
        //cout << "Update: " << ' ' << tl << ' ' << tr << ' ' << pos << ' ' << v << '\n';
        //print_v(tree[v]);
        //cout << '\n';

    }

}

void solve() {
    cin >> s;
    int n = s.size();
    build(s, 1, 1, n);

    int q;
    cin >> q;
    int x, l, r, pos;
    vi temp;
    char c;
    while(q--) {
        cin >> x;
        if(x == 1) {
            cin >> pos >> c;
            update(1, 1, n, pos, c);
        }
        else {
            cin >> l >> r;
            temp = sum(1, 1, n, l, r);
            int res = 0;
            f(i, 0, 26) {
                if(temp[i] > 0) {
                    res++;
                }
            }
            cout << res << '\n';
        }
    }


}

//Problem Link: https://codeforces.com/problemset/problem/1234/D

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