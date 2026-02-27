// Fibonacci Numbers

// Properties

/*

1. Cassini's Identity

Fn-1 + Fn+1 - Fn^2 = (-1)^n

2. Additon Rule

Fn+k = (Fk * Fn+1) + (Fk-1 * Fn)

* Put k = n
F2n = Fn(Fn+1 + Fn-1)

-> Fnk is multiple of Fn
-> if Fm is multiple of Fn then m is multiple of n

3. GCD Identity

GCD(Fm, Fn) = Fgcd(m, n)

*/



// Closed Form Expression

/*

Fn = ( ((1 + sqrt(5))/ 2)^n - ((1 - sqrt(5)) / 2)^n  ) / sqrt(5)

For large n 2nd term can be neglected.

*/


// Matrix Form

/*

Fn+1 = [[1, 1]] [Fn]
       [[1, 0]] [Fn-1]

*/





