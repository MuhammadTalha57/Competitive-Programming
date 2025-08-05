## 1. Gray Code

```cpp
int gray(int n) {return n ^ (n >> 1);}
```
> Time Complexity = O(1), Space Complexity = O(1)

## 2. Inverse Gray Code

```cpp
int invGray(int g) {
    int n = 0;
    while(g) {
        n ^= g;
        g >> 1;
    }
    return n;
}
```
> Time Complexity O(1), Space Complexity = O(1)