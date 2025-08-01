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
#define f(i, s, e) for (long long int i = s; i < e; i++)
#define fe(i, s, e) for (long long int i = s; i <= e; i++)
#define fr(i, e, s) for (long long int i = e - 1; i >= s; i--)
#define pb push_back
#define eb emplace_back
#define all(x) x.begin(), x.end()

/* PRINTS */
template <class T>
void print_v(vector<T> &v)
{
    for (auto x : v)
        cout << x << ' ';
}

/* UTILS */
#define MOD 1000000007
#define PI 3.1415926535897932384626433832795
#define read(type) readInt<type>()
ll min(ll a, int b)
{
    if (a < b)
        return a;
    return b;
}
ll min(int a, ll b)
{
    if (a < b)
        return a;
    return b;
}
ll max(ll a, int b)
{
    if (a > b)
        return a;
    return b;
}
ll max(int a, ll b)
{
    if (a > b)
        return a;
    return b;
}
ll gcd(ll a, ll b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }
bool prime(ll a)
{
    if (a == 1)
        return 0;
    for (int i = 2; i <= round(sqrt(a)); ++i)
        if (a % i == 0)
            return 0;
    return 1;
}
void yes() { cout << "YES\n"; }
void no() { cout << "NO\n"; }
void printCase(int i) { cout << "Case " << i << ": "; }

int dfs1(vi &temp, string &s, int i, int n)
{
    if (i == n - 1)
        return n - 1;

    int x = dfs1(temp, s, i + 1, n);

    if (s[i] == '1')
    {
        temp[i] = max(temp[i], x);
    }

    return temp[i];
}

void dfs2(vi &temp, string &s, int i, int n)
{
    // if(i == -1) return -1;
    if (i == n)
        return;

    if (i != 0)
    {
        if (s[i - 1] == '1')
        {
            temp[i] = min(temp[i], temp[i - 1]);
        }
    }

    dfs2(temp, s, i + 1, n);
}

void solve()
{
    int n;
    cin >> n;
    vll arr(n);
    f(i, 0, n) cin >> arr[i];
    string s;
    cin >> s;

    vi forward(n), rev(n);
    f(i, 0, n) forward[i] = i;
    rev = forward;

    dfs1(forward, s, 0, n);

    dfs2(rev, s, 0, n);

    f(i, 0, n)
    {
        int x = arr[i] - 1;

        if (x < i)
        {
            if (rev[i] > x)
            {
                no();
                return;
            }
        }
        if (x > i)
        {
            if (forward[i] < x)
            {
                no();
                return;
            }
        }
    }
    yes();
}

// Problem Link: https://codeforces.com/problemset/problem/920/C

int main()
{
    ios::ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}