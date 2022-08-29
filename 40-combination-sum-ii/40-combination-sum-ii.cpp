class Solution {
public:
    
    void getCombination(int index,int target, vector<int> can,vector<vector<int>>&ans,vector<int> ds){
        if(target==0){
            ans.push_back(ds);
            return;
        }
        
        for(int i=index;i<can.size();i++){
            if(i>index && can[i-1]==can[i]) continue;
            if (can[i] > target) break;
            ds.push_back(can[i]);
            getCombination(i + 1, target - can[i], can, ans, ds);
            ds.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
      sort(candidates.begin(), candidates.end());
      vector < vector < int >> ans;
      vector < int > ds;
      getCombination(0, target, candidates, ans, ds);
      return ans;
    }
};