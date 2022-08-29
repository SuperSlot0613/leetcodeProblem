class Solution {
public:
    
    void getCombination(vector<vector<int>>&ans,vector<int>&res,
                        vector<int> arr,int i, int target){
        if(target==0){
            ans.push_back(res);
            return;
        }
        while(i<arr.size() && (target-arr[i])>=0){
            res.push_back(arr[i]);
            getCombination(ans,res,arr,i,target-arr[i]);
            i++;
            res.pop_back();
        }
    }
    
    
    vector<vector<int>> combinationSum(vector<int>& arr, int target) {
        sort(arr.begin(),arr.end());
        vector<int> res;
        vector<vector<int>> ans;
        getCombination(ans,res,arr,0,target);
        return ans;
    }
};