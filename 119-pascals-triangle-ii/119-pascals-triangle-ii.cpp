class Solution {
public:
    vector<int> getRow(int rowIndex) {
         vector<vector<int>> v;
        for (int line = 1; line <= rowIndex+1; line++)
        {
            vector<int> row;
            long C = 1;
            for (int i = 1; i <= line; i++)
            {
                row.push_back(C);
                C = C * (line - i) / i;
            }
            v.push_back(row);   
        }
        return v[rowIndex];
        
    }
};