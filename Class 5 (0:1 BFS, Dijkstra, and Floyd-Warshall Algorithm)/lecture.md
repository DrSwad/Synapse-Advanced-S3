# Dijkstra

- What it does
- When applicable
  - Negative edge?
    - Directed/Undirected
  - Negative cycle?
    - Directed/Undirected
- Pseudocode and simulation
- 3 implementation variants
- Complexities of each variant
- Why Dijkstra fails for negative edge weights
- Example problems
  - Classic
  - Twist: minimum length path with minimum weight
  - Toll management

# 0/1 BFS

- What it does
- When applicable
  - Edge weights 0 or 1
  - Edge weights 0 and unique w? // w > 1
  - Edge weights w1 and w2? // w1 > 0 and w2 > 0
- Dial's algorithm

# Floyd-Warshall

- What it does
- When applicable
  - Negative edge?
    - Directed/Undirected
  - Negative cycle?
    - Directed/Undirected
- Dijkstra could be an alternative when edges are non-negative
- Pseudocode and simulation
- Handling infinity when there are negative weights
- Detecting negative cycle
- Implementation and complexity