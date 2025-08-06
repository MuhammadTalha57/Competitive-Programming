## 1. Increasing Monotonic Stack

```cpp
int n, vector<int> arr;
// Input

stack<int> s;
for(int i = 0; i < n; i++) {
    while(!s.empty() && s.top() < arr[i]) {
        s.pop();
    }

    s.insert(arr[i]);
}
```

## 2. Decreasing Monotonic Stack

```cpp
int n, vector<int> arr;
// Input

stack<int> s;
for(int i = 0; i < n; i++) {
    while(!s.empty() && s.top() > arr[i]) {
        s.pop();
    }

    s.insert(arr[i]);
}
```
> Space Complexity = O(n)
> Solve problems like next greater or smaller element in O(n) time.