#include "bits/stdc++.h"

using namespace std;

/*

Time Complexity = O(Log b)
Space Complexity = O(1)

*/
int bExp(int a, int b, int m) {
    int res = 1;
    a = a % m;
    while(b) {
        if(b & 1) {
            res = res * a;
            res = res % m;
        }
        a = a * a;
        a = a % m;
        b >>= 1;
    }

    return res;
}