#include "bits/stdc++.h"

using namespace std;

int longestIncreasingSubsequence(int n, vector<int> &arr)
{
    /*
        Asymptotic Analysis
        TC = O(N Log N)
        SC = O(N)
    */
    int result = 0;
    vector<int> best(n + 1);

    for (int i = 0; i < n; i++)
    {
        int len = lower_bound(best.begin(), best.begin() + result + 1, arr[i]) - best.begin();
        if (len > result)
        {
            result = len;
            best[len] = arr[i];
        }
        else
        {
            best[len] = min(best[len], arr[i]);
        }
    }

    return result;
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << longestIncreasingSubsequence(n, arr) << '\n';

    return 0;
}