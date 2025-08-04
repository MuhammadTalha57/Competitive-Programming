## 1. Binary Exponentiation

```cpp
long long binpow(long long a, long long b) {
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}
```
> Time Complexity = O(log b), Space Complexity = O(1)

## 2. Modular Arithmetic

$$(a + b) mod m = ( (a mod m) + (b mod m) ) mod m$$
$$(a * b) mod m = ( (a mod m) * (b mod m) ) mod m$$
$$(a - b) mod m = ( (a mod m) - (b mod m) + m ) mod m$$