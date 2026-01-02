

```cpp
using cd = complex<double>;
const double PI = acos(-1);

void fft(vector<cd>& a, bool invert) {
    int n = a.size();
    // n = 2^k
    if(n == 1)
        return;

    vector<cd> a0(n / 2), a1(n / 2);
    for(int i = 0; 2*i < n; i++) {
        a0[i] = a[2*i];
        a1[i] = a[2*i + 1]; 
    }

    fft(a0, invert);
    fft(a1, invert);

    double ang = (2 * PI) / n * (invert ? -1 : -1);
    cd w(1), wn(cos(ang), sin(ang));

    for(int i = 0; 2*i < n; i++) {
        a[i] = a0[i] + w * a1[i];
        a[i + n/2] = a0[i] - w * a1[i];
        if(invert) {
            a[i] /= 2;
            a[i + n/2] /= 2;
        }
        w *= wn;
    }
}

```


```cpp
vector<int> multiply(vector<int>& a, vector<int>& b) {
    vector<cd> fa(a.begin(), a.end()), fb(b.begin(), b.end());
    int n = 1;
    while(n < a.size() + b.size())
        n <<= 1;
    
    fa.resize(n);
    fb.resize(n);

    fft(fa, false);
    fft(fb, false);

    for(int i = 0; i < n; i++) {
        fa[i] *= fb[i];
    }
    fft(fa, true);

    vector<int> result(n);
    for(int i = 0; i < n; i++) 
        result[i] = round(fa[i].real());
    
    return result;
}

```

```cpp
vector<int> stringMatch(string text, string pattern) {
    int n = text.size();
    int m = pattern.size();
    
    // Create polynomial A(x) for text
    vector<cd> A(n);
    for(int i = 0; i < n; i++) {
        double alpha = 2 * PI * (text[i] - 'a') / 26.0;
        A[i] = cd(cos(alpha), sin(alpha));
    }
    
    // Create polynomial B(x) for pattern (reversed)
    vector<cd> B(n); // pad with zeros
    for(int i = 0; i < m; i++) {
        double beta = 2 * PI * (pattern[m - 1 - i] - 'a') / 26.0;
        B[i] = cd(cos(beta), -sin(beta)); // conjugate
    }
    
    // Find next power of 2
    int size = 1;
    while(size < n + m)
        size <<= 1;
    
    A.resize(size);
    B.resize(size);
    
    // Multiply using FFT
    fft(A, false);
    fft(B, false);
    
    for(int i = 0; i < size; i++) {
        A[i] *= B[i];
    }
    
    fft(A, true);
    
    // Find matches
    vector<int> matches;
    for(int i = m - 1; i < n; i++) {
        // Check if coefficient is close to m (allowing floating point error)
        double coeff = A[i].real();
        if(abs(coeff - m) < 0.5) {
            matches.push_back(i - m + 1); // starting position of match
        }
    }
    
    return matches;
}

```