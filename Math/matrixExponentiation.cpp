#include "bits/stdc++.h"

using namespace std;

/*
Time Complexity: O(n^3 * log p) where n is matrix dimension and p is exponent
Space Complexity: O(n^2) for storing matrices
*/

typedef long long ll;
typedef vector<vector<ll>> matrix;

const ll MOD = 1e9 + 7;

matrix multiply(matrix &A, matrix &B, int n) {
    matrix C(n, vector<ll>(n, 0));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            for(int k = 0; k < n; k++) {
                C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % MOD;
            }
        }
    }
    return C;
}

matrix matrixExp(matrix &A, ll p, int n) {
    matrix result(n, vector<ll>(n, 0));
    for(int i = 0; i < n; i++) {
        result[i][i] = 1;
    }
    while(p > 0) {
        if(p & 1) {
            result = multiply(result, A, n);
        }
        A = multiply(A, A, n);
        p >>= 1;
    }
    return result;
}