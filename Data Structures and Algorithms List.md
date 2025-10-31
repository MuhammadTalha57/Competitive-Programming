# Math

## 1. Binary Exponentiation
> Time Complexity = O(log b), Space Complexity = O(1)

## 2. Modular Arithmetic

# Bit Manipulation

## 1. Gray Code
> Time Complexity = O(1), Space Complexity = O(1)

## 2. Inverse Gray Code
> Time Complexity O(1), Space Complexity = O(1)

# Tree

## 1. Segment Tree
> Range Operations in logarithmic time, Requires linear memory
> Can be used for higher dimensions as well such as Matrix

## 2. Lazy Segment Tree
> Range Operations in logarithmic time, Requires linear memory
> Allows range modifications in logarithmic time.
# Stack

## 1. Increasing Monotonic Stack
> Useful for problems like finding next greater element

## 2. Decreasing Monotonic Stack
> Useful for problems like finding next smaller element

# Dynamic Programming

## 1. 0-1 Knapsack
> O - 1 Knapsack -> O(N W) Time and O(W) Space
Each item can be taken once

## 2. Complete Knapsack
> Complete Knapsack -> O(N W) Time ans O(W) Space
Each item can be taken any number of times

## 3. Multiple Knapsack
> Given n items and weight limit W. Each item has a value, weight and **quantity (k<sub>i</sub>)**. You have to find maximum value while keeping the total weight of items <= W
Each item **i** can be taken **at most k<sub>i</sub> times**

> We use binary grouping for optimization.

> Time Complexity = O(W n log k), Space Complexity = O(W)

## 4. Longest Increasing Subsequence (LIS)
> Time Complexity =  O(N log N)
Space Complexity =  O(N)

## 5. Weighted Interval Scheduling
> Time Complexity = O(N log N)
Space Complexity = O(N)

## 6. Broken Profile DP
> Time Complexity = O(m m 2<sup>min(n, m)</sup>)
Space Complexity = O(max(n, m) 2<sup>min(n, m)</sup>)

# Graph

# Path Finding Algorithms

## 1. BFS
> Given a **unweighted** graph with n vertices, m edges and a source vertex s. Find Shortest path to all nodes from the given source node (s)

> Time Complexity = O(N + M)

## 2. 0-1 BFS
> Given a **weighted** graph with weights **0** or **1** with n vertices, m edges and a source vertex s. Find Shortest path to all nodes from the given source node (s)

> Time Complexity = O(N + M)

## 3. K-BFS (Dials Aglrorithm)
> Given a **weighted** graph with weights at most k with n vertices, m edges and a source vertex s. Find Shortest path to all nodes from the given source node (s)

> Time Complexity = O(N + M + k * N)

## 4. Bellman Ford
> Given a **weighted** graph with n vertices, m edges and a source vertex s. Find Shortest path to all nodes from the given source node (s)

> Time Complexity = O(N M)

## 5. Shortest Path Faster Algorithm (Bellman Ford Improvement)
> Given a **weighted** graph with n vertices, m edges and a source vertex s. Find Shortest path to all nodes from the given source node (s)

> Time Complexity = O(N M), Avg Time Complexity = O(M)


## 6. Dijkstra For Dense Graph
> Given a **weighted** graph with n vertices, m edges, a source vertex s and with no **negative cycle**. Find Shortest path to all nodes from the given source node (s)

> Time Complexity = O(N<sub>2</sub> + M)

## 7. Dijkstra For Sparse Graph
> Given a **weighted** graph with n vertices, m edges, a source vertex s and with no **negative cycle**. Find Shortest path to all nodes from the given source node (s)

> Time Complexity = O(M Log N)

## 8. Floyd Warshall
> Given a **weighted** graph with n vertices, m edges and a source vertex s. Find Shortest path from all nodes to all other nodes.

> Time Complexity = O(N^3), Space Complexity = O(N^2)