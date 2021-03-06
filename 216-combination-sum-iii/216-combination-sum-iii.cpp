class Solution {
public:
    
    void dfs(int num, int sum, int count, vector<int>& path, vector<vector<int>>& ans) {
        if(sum == 0 && count == 0) {
            ans.push_back(path);
            return;
        }
        if(sum == 0 || count == 0) {
            return;
        }
        if(num > 9) return;
        
        //take it
        if(sum >= num && count > 0) {
            path.push_back(num);
            dfs(num+1, sum-num, count-1, path, ans);
            path.pop_back();
        }
        
        //leave it
        dfs(num+1, sum, count, path, ans);
    }
    
    
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> path;
        dfs(1, n, k, path, ans);
        return ans;
    }
};