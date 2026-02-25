// Euclidean Algorithm

/*

Time Complexity = O(log(min(a, b)))
Space Complexity = O(1)

*/
int gcd (int a, int b) {
    if (b == 0)
        return a;
    else
        return gcd (b, a % b);
}