# algorithms
dfs footprint.

/*  graph:
 *  i    [0   1   2   3]
 *  [0]   0   1   1   0
 *  [1]   1   0   0   1
 *  [2]   1   0   0   1
 *  [3]   0   1   1   0
 *
 * node:      [0]  1   2   3
 * visit:      1   0   0   0
 * father:    -1   0  -1  -1
 *
 * node:       0  [1]  2   3
 * visit:      1   1   0   0
 * father:     -1  0  -1   1
 *
 * node:       0   1   2  [3]
 * visit:      1   1   0   1
 * father:    -1   0   3   1
 *
 * node:       0   1   2  [3]
 * visit:      1   1   1   1
 * father:    -1   0   3   1
 *
 * */
