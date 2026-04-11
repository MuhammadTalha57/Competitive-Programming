# C++ / STL Notes

# Optimizations

### 1. Array Vs Vector

Try to use arrays instead of vector

### 2. Same Complexities

When mulitple techniques / DS offers same complexity always opt that uses simpler implementation

Example: Use sort() instead of map

## 1. Decimal Comparision

Rounding off errors can occur.
To check two decimal numbers are equal use this:

```cpp
bool areEqual(double a, double b) {
    return abs(a - b) < 1e9;
}
```

## 2. Double Precision

Double can precisely represent all integers with an absolute value up 2<sup>53</sup>.
