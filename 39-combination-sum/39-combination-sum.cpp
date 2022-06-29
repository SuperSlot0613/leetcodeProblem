class Solution {
public:
    
    void findNumbers(vector<int>& arr,vector<vector<int>>& res,int sum,int i,vector<int>& r){
        if(sum==0){
            res.push_back(r);
            return;
        }
        
        while(i<arr.size() && (sum-arr[i])>=0){
            r.push_back(arr[i]);
            findNumbers(arr,res,sum-arr[i],i,r);
            i++;
            r.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        //candidates.erase(unique(candidates.begin(),candidates.end()),candidates.end());
        vector<int> r;
        vector<vector<int>> res;
        findNumbers(candidates,res,target,0,r);
        return res;
    }
};