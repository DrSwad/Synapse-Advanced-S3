# Prefix function

- What is prefix function?
- How to calculate it?
  - Trivial brute force.
  - Reduce the number of string comparisons to O(N): π(i) <= π(i - 1) + 1.
  - Avoid string comparisons all together: π(i) = 0 or [π(π(...π(i - 1) - 1) - 1) + 1]
- Time and space complexity.
- Applications:
  - KMP
  - DP
    - Count the number of occurrences of each prefix.
    - Find the shortest divisor of a string.

# KMP (Knuth–Morris–Pratt) Algorithm

- Find a pattern p in a text t.
- Time and space complexity.