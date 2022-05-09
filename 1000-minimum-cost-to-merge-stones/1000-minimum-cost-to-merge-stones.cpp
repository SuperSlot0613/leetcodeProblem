class Solution {
public:
    int mergeStones(vector<int>& stones, int K) {
        int n = stones.size();
    if (K <= 1 || (n - K) % (K - 1) != 0) {
      return -1;
    }
    vector<int> presum(n + 1, 0);
    for (int i = 0; i < n; ++ i) {
      presum[i + 1] = presum[i] + stones[i];
    }
    vector<vector<int>> table(n, vector<int>(n, 0));  // table[i][j] means minCost for stones[i...j], k
    for (int len = K; len <= n; ++ len) {
      for (int i = 0; i + len <= n; ++ i) {
        int j = i + len - 1;
        table[i][j] = INT_MAX;
        for (int t = i; t < j; t += K - 1) {
          table[i][j] = min(table[i][j], table[i][t] + table[t + 1][j]);
        }
        if ((j - i) % (K - 1) == 0) {
          table[i][j] += presum[j + 1] - presum[i];
        }
      }
    }
    return table[0][n - 1];
    }
};