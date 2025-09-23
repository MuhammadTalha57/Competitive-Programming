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
 
/* PRINTS */
template <class T>
void print_v(vector<T> &v) { for (auto x : v) cout << x.first  << ' ' << x.second << ' '; }
 
/* UTILS */
#define MOD 1000000007
#define PI 3.1415926535897932384626433832795
#define read(type) readInt<type>()
ll min(ll a,int b) { if (a<b) return a; return b; }
ll min(int a,ll b) { if (a<b) return a; return b; }
ll max(ll a,int b) { if (a>b) return a; return b; }
ll max(int a,ll b) { if (a>b) return a; return b; }
int min(int a, int b) {if (a < b) return a; return b;}
ll gcd(ll a,ll b) { if (b==0) return a; return gcd(b, a%b); }
ll lcm(ll a,ll b) { return a/gcd(a,b)*b; }
bool prime(ll a) { if (a==1) return 0; for (int i=2;i<=round(sqrt(a));++i) if (a%i==0) return 0; return 1; }
void yes() { cout<<"YES\n"; }
void no() { cout<<"NO\n"; }
void printCase(int c) {cout << "Case " << c << ": ";}
 
int binarySearch(vi& arr, int start, int end, int t) {
    int lo = start, hi = end, m;
    while(lo <= hi) {
        m = (lo + hi) / 2;
        if(arr[m] == t) {
            return m;
        }
        else if(arr[m] > t) {hi = m - 1;}
        else {lo = m + 1;}
    }
    if(lo < start) {return start;}
    if(lo > end) {return end;}
    return lo;
}
 
// bool compare(string& a, string& b) {
//     if(a.size() == b.size()) {return a < b;}
//     return a.size() < b.size();
// }
 
 
bool find(string s, string t, char c, int i, int j) {
    if(c == 'o') {
        return s.find(c, i) != string::npos;
    }
    int res = s.find(c, i);
    return res != string::npos && find(s, t, t[j+1], res + 1, j+1);
}
 
class Compare {
public:
    bool operator() (pii a, pii b) {
        return b.first < a.first;
    }
};
 
bool compare(pii a, pii b) {
    return ( a.first < b.first );
}
 
double getP(ll a, ll b, ll c, ll d) {
    return double( -b + sqrt( double(d) ) ) / double(2*a);
}
 
double getM(ll a, ll b, ll c, ll d) {
    return double( -b - sqrt( double(d) ) ) / double(2*a);
}
 
void rotateMatrix(vector<vi>& mat, int k) {
    int c2 = mat.size(), r2 = mat[0].size();
    int r1 = -1, c1 = -1;
    int i, j;
 
    int t; // Insertion Ptr
    int size; // Size of a layer
 
    cout << "RAN\n";
 
    while(r1 <= r2 && c1 <= c2) {
 
        cout << r1 << ' ' << r2 << ' ' << c1 << ' ' << c2 << '\n';
 
        size = 2*( (r2 - (r1 + 1) ) + ( c2 - (c1 + 1) ) ) ;
        vi temp(size);
        t = 0;
        
        // Starting Pos
        i = r1 + 1; j = c1 + 1;
 
        //cout << mat[i][j] << '\n';
 
        for(int i = 0; i < mat.size(); i++) {
            for(int j = 0; j < mat[i].size(); j++) {
                cout << mat[i][j] << ' ';
            }
            cout << '\n';
        }
        
        // ROTATING within temp
 
        // Right
        while(j < c2) {
            temp[ (t++ + k) % size ] = mat[i][j];
            j++;
        }
        j--; 
 
        // Bottom
        while(i < r2) {
            temp[(t++ + k) % size] = mat[i][j];
            i++;
        }
        i--;
 
        // Left
        while(j > c1) {
            temp[(t++ + k) % size] = mat[i][j];
            j--;
        }
        j++;
 
        // Top
        while(i > r1) {
            temp[(t++ + k) % size] = mat[i][j];
            i--;
        }
        i++;
 
        // Copying back to MAT
        i = r1 + 1; j = c1 + 1;
        t = 0;
        // Right
        while(j < c2) {
            mat[i][j] = temp[t++];
            j++;
        }
        j--; 
 
        // Bottom
        while(i < r2) {
            mat[i][j] = temp[t++];
            i++;
        }
        i--;
 
        // Left
        while(j > c1) {
            mat[i][j] = temp[t++];
            j--;
        }
        j++;
 
        // Top
        while(i > r1) {
            mat[i][j] = temp[t++];
            i--;
        }
        i++;
 
 
 
        r1++; c1++;
        r2--; c2--;
        if(r1 >= r2 && c1 >= c2) {break;}
        
    }
 
 
    
    return;
 
}
 
string getString(int i, int j) {
    return to_string(i) + ' ' + to_string(j);
}
 
bool notVisited(vector<string>& g, int i, int j) {
    return g[i][j] != '1';
}
 
void dfs(vector<string>& g, int i, int j) {
    g[i][j] = '1';
 
    if( i - 1 >= 0 && g[i-1][j] == '.' && notVisited(g, i-1, j) ) {
        dfs(g, i-1, j);
    }
 
    if( i + 1 < g.size() && g[i+1][j] == '.' && notVisited(g, i+1, j) ) {
        dfs(g, i+1, j);
    }
 
    if( j - 1 >= 0 && g[i][j-1] == '.' && notVisited(g, i, j-1) ) {
        dfs(g, i, j-1);
    }
 
    if( j + 1 < g[0].size() && g[i][j+1] == '.' && notVisited(g, i, j+1) ) {
        dfs(g, i, j+1);
    }
 
}
 
 
void solve() {
    int n, m;
    cin >> n >> m;
 
    vector<string> g(n);
    f(i, 0, n) {
        cin >> g[i];
    }
    int res = 0;
 
    // unordered_set<string> visited;
 
    f(i, 0, n) {
        f(j, 0, m) {
            if(g[i][j] == '.' && notVisited(g, i, j) ) {
                dfs(g, i, j);
                res++;
            }
            
        }
    }
 
    cout << res << '\n';
 
 
}

// Problem Link: https://cses.fi/problemset/task/1192/
 
int main() {
    
    
    solve();
    
    return 0;
}