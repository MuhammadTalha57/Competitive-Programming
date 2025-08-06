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

vll primes(1e5 + 20, 1);

void solve()
{

    ll n, k;
    cin >> n >> k;
    vll res;
    for (int p = 2; p < primes.size(); p++)
    {
        if (primes[p] == 1)
        {
            while (n % p == 0)
            {
                res.pb(p);
                n = n / p;
            }
        }
    }

    if (res.size() >= k)
    {
        for (int i = 0; i < k - 1; i++)
        {
            cout << res[i] << ' ';
        }
        ll x = 1;
        f(i, k - 1, res.size())
        {
            x = x * res[i];
        }
        cout << x << '\n';
    }
    else
    {
        cout << -1 << '\n';
    }
}

// Problem Link: https://codeforces.com/problemset/problem/797/A

int main()
{
    ios::ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int t = 1;

    primes[1] = 0;
    for (int p = 2; p < primes.size(); p++)
    {
        if (primes[p] == 1)
        {
            for (int k = p + p; k < primes.size(); k += p)
            {
                primes[k] = 0;
            }
        }
    }

    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}