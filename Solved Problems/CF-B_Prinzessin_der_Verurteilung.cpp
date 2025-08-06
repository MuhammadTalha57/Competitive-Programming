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

vector<string> checks;

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    string test;

    // print_v(checks);

    for (int j = 0; j < checks.size(); j++)
    {
        string temp = checks[j];
        // cout << c << '\n';
        int k = temp.size();
        bool flag = true;
        for (int i = 0; i < (n - k + 1); i++)
        {
            if (s.substr(i, k) == temp)
            {
                flag = false;
                break;
            }
        }

        if (flag)
        {
            cout << temp << '\n';
            return;
        }
    }
}

// Problem Link: https://codeforces.com/problemset/problem/1536/B

int main()
{
    ios::ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int t = 1;
    cin >> t;

    f(i, 0, 26)
    {

        string temp;
        temp += char('a' + i);
        // cout << temp << '\n';
        checks.pb(temp);
        // cout << checks.back() << '\n';
    }
    f(i, 0, 26)
    {
        f(j, 0, 26)
        {
            checks.pb(string() + char('a' + i) + char('a' + j));
        }
    }

    f(i, 0, 26)
    {

        f(j, 0, 26)
        {
            f(k, 0, 26)
            {

                checks.pb(string() + char('a' + i) + char('a' + j) + char('a' + k));
            }
        }
    }

    while (t--)
    {
        solve();
    }
    return 0;
}