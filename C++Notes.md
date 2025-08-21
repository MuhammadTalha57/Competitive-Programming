# C++ / STL Notes

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