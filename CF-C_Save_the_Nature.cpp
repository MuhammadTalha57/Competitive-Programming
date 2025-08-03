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

ll n, x, a, y, b, k, lcmAB;

bool check(vll &arr, int m)
{
    ll res = 0;
    ll lcmCount = m / lcmAB;
    ll aCount = (m / a) - lcmCount;
    ll bCount = (m / b) - lcmCount;
    ll lo = 1, hi; // For Prefix Sum [lo, hi]

    // LCM
    hi = lo + lcmCount - 1;
    res += ((x + y) * (arr[hi] - arr[lo - 1])) / 100;
    lo = hi + 1;

    // a, x
    hi = lo + aCount - 1;
    res += (x * (arr[hi] - arr[lo - 1])) / 100;
    lo = hi + 1;

    // b, y
    hi = lo + bCount - 1;
    res += (y * (arr[hi] - arr[lo - 1])) / 100;
    lo = hi + 1;

    return res >= k;
}

void solve()
{
    cin >> n;
    vll arr(n + 1, LONG_LONG_MAX);
    f(i, 1, n + 1) cin >> arr[i];
    sort(arr.rbegin(), arr.rend());

    f(i, 2, n + 1)
    {
        arr[i] += arr[i - 1];
    }
    arr[0] = 0;

    cin >> x >> a >> y >> b >> k;
    if (y > x)
    {
        swap(x, y);
        swap(a, b);
    }

    lcmAB = lcm(a, b);

    ll lo = 1, hi = n;
    ll res = -1;
    while (lo <= hi)
    {
        // cout << n << ' ' << lo << ' ' << hi << '\n';
        ll m = (lo + hi) / 2;
        if (check(arr, m))
        {
            hi = m - 1;
            if (res == -1)
            {
                res = m;
            }
            else
                res = min(res, m);
        }
        else
        {
            lo = m + 1;
        }
    }

    cout << res << '\n';
}

// Problem Link: https://codeforces.com/problemset/problem/1223/C

int main()
{
    ios::ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}