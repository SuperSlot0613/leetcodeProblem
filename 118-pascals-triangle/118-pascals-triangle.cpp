class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> v;
        for (int line = 1; line <= numRows; line++){
            vector<int> row;
            int C = 1;
            for (int i = 1; i <= line; i++)
            {
                row.push_back(C);
                C = C * (line - i) / i;
            }
            v.push_back(row);   
        }
        return v;
    }
};