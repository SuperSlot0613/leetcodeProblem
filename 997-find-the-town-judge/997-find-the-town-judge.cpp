class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> trustedTable(n, 0);
        vector<int> trustTable(n, 0);
        
        for (const vector<int> &edge: trust)
        {
            ++trustedTable[edge[1] - 1];
            ++trustTable[edge[0] - 1];
        }
        
        for (int i = 0; i < n; ++i)
        {
            if (trustedTable[i] == n - 1 && trustTable[i] == 0)
                return i + 1;
        }
        return -1;
    }
};