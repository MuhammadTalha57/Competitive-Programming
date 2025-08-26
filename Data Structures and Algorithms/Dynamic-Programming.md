## 1. 0-1 Knapsack
> Given n items and weight limit W. Each item has a value and weight. You have to find maximum value while keeping the total weight of items <= W
Each item can be taken **once**

```cpp
// input
int n, W;
vector<int> value(n), weight(n);

// Implmentation
vector<int> dp(W + 1, 0);
for(int i = 1; i <= n; i++) {
    for(int j = W; j >= weight[i]; j--) {
        dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);
    }
}

// dp[W] is the answer
```
> Time Complexity = O(n W), Space Complexity = O(W)

> Note the order of execution of the second loop

## 2. Complete Knapsack
> Given n items and weight limit W. Each item has a value and weight. You have to find maximum value while keeping the total weight of items <= W
Each item can be taken **any number of times**
```cpp
int n, W;
vector<int> value(n), weight(n);

// Implmentation
vector<int> dp(W + 1, 0);
for(int i = 1; i <= n; i++) {
    for(int j = weight[i]; j <= W>; j++) {
        dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);
    }
}

// dp[W] is the answer
```
> Time Complexity O(n W), Space Complexity = O(n W)

> Note that everything is same as 0-1 Knapsack except the order of execution of second loop

## 3. Multiple Knapsack
> Given n items and weight limit W. Each item has a value, weight and **quantity (k<sub>i</sub>)**. You have to find maximum value while keeping the total weight of items <= W
Each item **i** can be taken **at most k<sub>i</sub> times**

> We use binary grouping for optimization.

```cpp

int n, W;
cin >> n >> W;

int weight, value, quantity;

vector<int> weights, values;
// Binary Grouping
for(int i = 1; i <= n; i++) {
    int c = 1;
    cin >> weight >> value >> quantity;

    while(quantity > c) {
        quantity -= c;
        weights.push_back(c * weight);
        values.push_back(c * value);
        c = c * 2;
    }
    if(quantity > 0) {
        weights.push_back(quantity * weight);
        values.push_back(quantity * value);
    }

}

// Now just execute simple 0-1 Knapsack.

```
> Time Complexity O(W n log k), Space Complexity = O(W)

## 4. Longest Increasing Subsequence (LIS)

> Using binary search and DP

```cpp
int n;
cin >> n;
vi arr(n);
for(int i = 0; i < n; i++) {cin >> arr[i];}

vi dp(n + 1, INF);
dp[0] = -INF;
vi dpInd(n + 1, -1);
/*
dp[i] is the smallest number on which LIS of length i ends.

LIS length will be the max i where dp[i] < INF

To reconstruct LIS, We can use array p which points to the indices of the elements in dp array.
p[i] will be the index of the of the previous element 
*/


int LISLength = 0, LISLstInd = -1;
for(int j = 0; j < n; j++) {
    int i = upper_bound(all(dp), arr[j]);

    if(dp[i - 1] < arr[j] && arr[j] < dp[i] ) {
        dp[i] = arr[j];
        dpInd[i] = j;
        p[j] = dpInd[i - 1];

        if(i > LISLength) {
            LISLength = i;s
            LISLstInd = j;
        }
    }

    cout << "LIS Length: " << LISLength << '\n';
    if(LISLength) {
        vi seq;
        int k = LISLstInd;
        seq.pb(arr[k]);
        while(p[k] != -1) {
            k = p[k];
            seq.pb(arr[k]);
        }
        reverse(all(seq));
    }
    print_v(seq);

}


```
> Time Complexity O(W n log k), Space Complexity = O(W)

## 5. Weighted Interval Scheduling
> Given n jobs with starting time (a), ending time (b) and profit (p).
Find the subset of mutually compatible jobs (Non Overlapping) which maximizes the profit.

> We use Sorting + Binary Search + DP

```cpp

int n;
cin >> n;
vvi jobs(n + 1);
jobs[0] = {0, 0, 0};
int a, b, p;
rep(i, 1, (n + 1)) {
    cin >> a >> b >> p;
    jobs[i] = {a, b, p};
}

// SORT JOBS w.r.t finish time  (Start Time doesn't matter)
sort(jobs, ...)

vi prev(n + 1, 0);
// prev[i] give the highest index of the job among jobs (0 to i - 1)
// which is compatible with job i.
// Computed using Binary Search

rep(i, 1, (n + 1)) {
    int target = jobs[i][0]; // Start Time of job i
    int lo = 1, hi = i - 1, mid;
    int res = 0;
    while(lo <= hi) {
        mid = (lo + hi) / 2;

        if(jobs[mid][1] < target) {
            res = mid;
            lo = mid + 1;
        }
        else {
            hi = mid - 1;
        }

    }

    prev[i] = res; // res is the index of the job among jobs (0 to i - 1) that is compatible with job i.
}


vll dp(n + 1, 0);
// dp[i] is the max Profit when considering jobs (1 to i)

rep(i, 1, (n + 1)) {
    dp[i] = max(dp[i - 1], jobs[i][2] + dp[prev[i]]);
}

long long maxProfit = dp[n];

// Reconstructing Subset
int k = n;
vi jobsSet;
while(k != 0) {
    if(jobs[k][2] + dp[prev[k]] > dp[k - 1]) {
        // Job k was selected
        jobsSet.pb(k);
        k = prev[k];
    }
    else {
        k = k - 1;
    }
}


// Now just execute simple 0-1 Knapsack.

```
> Time Complexity O(W n log k), Space Complexity = O(W)