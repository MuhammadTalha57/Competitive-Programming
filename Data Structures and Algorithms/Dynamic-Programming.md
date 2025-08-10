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