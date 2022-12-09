/**
 * Description: Fast sum over subsets $g_i = \sum_{j\subseteq i} f_j$ and supersets $g_i=\sum_{i\subseteq j} f_j$.
 * Time: $O(n 2^n)$
 */
for (int mask = 0; mask < 1 << n; mask++) f[mask] = a[mask];
// sum over subsets
for (int i = 0; i < n; ++i) {
  for (int mask = 0; mask < 1 << n; ++mask) {
    if (mask & 1 << i) f[mask] += f[mask ^ 1 << i];
  }
}
// sum over supersets
for (int i = 0; i < n; ++i) {
  for (int mask = (1 << n) - 1; mask >= 0; --mask) {
    if (~mask & 1 << i) f[mask] += f[mask | 1 << i];
  }
}
