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

```cpp
(a + b) mod m = ( (a mod m) + (b mod m) ) mod m
(a * b) mod m = ( (a mod m) * (b mod m) ) mod m
(a - b) mod m = ( (a mod m) - (b mod m) + m ) mod m
```

## 3. Arithmetic Series
```cpp
S = (n * (a + l)) / 2

S = ( n* ( (2 * a) + (n - 1)*d ) ) / 2

```

## 4. Geometric Series
```cpp
S = ( (l * r) - a ) / (r - 1)
```

## 5. Common Sums
```cpp
1 + 2 + 3 + ... + n = ( n*(n + 1) ) / 2

1^2 +2^2 + 3^2 + ... + n^2 = ( n*(n + 1)*(2*n + 1) ) / 6
```

## 6. Fibonacci Numbers
```math
f(0) = 0 \\
f(1) = 1 \\
f(n) = f(n - 1) + f(n - 2) \\
\quad \\

Closed Form Formula: f(n) = \frac{(1 + \sqrt{5})^n - (1 - \sqrt{5})^n}{2^n \sqrt{5}} \\
\textit{Round off decimals to nearest integer}
```

## 7. Logarithms
```math
log_k (x) = a \\
k^a = x

\\ \quad \\

log_k(ab) = log_k(a) + log_k(b) \\
log_k(a / b) = log_k(a) - log_k(b) \\
log_k(a^n) = nlog_k(a) \\
log_u(x) = \frac{log_k(x)}{log_k(u)}
```
> The Number of digits in number (x) represented in base (b) is **$log_b(x) + 1$**


## 8. Geometry Shapes Formulas

### 8.1 Volume of Sphere
$V = \frac{4}{3}\pi r^3$


## 8. Modular Inverse Factorial
```cpp
ll inv(int a){
    return a <= 1 ? a : MOD - MOD / a * inv(MOD % a) % MOD;
}
```