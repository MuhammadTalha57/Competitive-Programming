// Linear Diophantine Equation (ax + by = c)

/*
Special Cases:

1. a == 0 and b == 0 -> zero or infinite solutions if c == 0
2. a == 0 and b != 0 -> (x, c / b)
3. a != 0 and b == 0 -> (c / a, y)

*/

// Default Case a != 0 and b != 0

#include "bits/stdc++.h"

using namespace std;

int eegcd(int a, int b, int& x, int& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1;
    int d = eegcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}


// 1. Find any solution
bool findAnySolution(int a, int b, int c, int& x, int& y, int& g) {
    g = eegcd(abs(a), abs(b), x, y);
    if(c % g) return false;

    // ax + by = g

    x *= c / g;
    y *= c / g;

    // ax + by = c

    if(a < 0) x = -x;
    if(b < 0) y = -y;

    return true;
}

// 2. Getting all solutions

/*
x' = x + k * (b / g)
y' = y - k * (a / g)

*/


// 3. Getting solutions in given range [minx, maxx] and [miny, maxy]

void shiftSolution(int& x, int& y, int a, int b, int cnt) {
    // should be cnt * (b / g)
    // but for simplicity we have divided whole equation by g
    // ax + by = c  -> (a / g)x + (b / g)y = c / g

    x += cnt * b;
    y -= cnt * a;
}


int findAllSolutions(int a, int b, int c, int minx, int maxx, int miny, int maxy) {
    int x, y, g;
    if(!findAnySolution(a, b, c, x, y, g))  {
        return 0;
    }

    // modifying equation
    a /= g;
    b /= g;
    c /= g;

    int signA = a > 0 ? 1: -1;
    int signB = b > 0 ? 1: -1;

    shiftSolution(x, y, a, b, (minx - x) / b);  // * b is modified
    if(x < minx) {
        shiftSolution(x, y, a, b, signB);
    }
    if(x > maxx) return 0;

    int lx1 = x;

    shiftSolution(x, y, a, b, (maxx - x) / b);
    if(x > maxx) {
        shiftSolution(x, y, a, b, -signB);
    }
    int rx1 = x;

    shiftSolution(x, y, a, b, -(miny - y) / a);
    if(y < miny) {
        shiftSolution(x, y, a, b, -signA);
    }
    if(y > maxy) return 0;

    int lx2 = x;

    shiftSolution(x, y, a, b, -(maxy - y) / a);;
    if(y > maxy) {
        shiftSolution(x, y, a, b, signA);
    }
    int rx2 = x;

    if(lx2 > rx2) {
        swap(lx2, rx2);
    }
    int lx = max(lx1, lx2);
    int rx = max(rx1, rx2);

    if(lx > rx) return 0;

    return (rx - lx) / abs(b) + 1;
}


// 4. Finding solution with minimum value of x + y

// Range must be restricted otherwise the answer may become negative infinity

/*
x' = x + k * (b / g)
y' = y - k * (a / g)

x' + y' = x + y + k * ( (b - a) / g)

Therefore,
if a < b -> we need smallest possible k
if a > b -> we need largest possible k
if a == b -> all solution will have the same sum

*/
