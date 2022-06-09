class Solution {
public:
    
     bool canPatitionsum(int index,int target, vector<int>&arr,vector<vector<int>>& dp){
        if(target==0) return true;
        
        if(index==0){
            return (arr[index]==target);
        }
        if(dp[index][target]!=-1){
            return dp[index][target];
        }
        
        bool notake=canPatitionsum(index-1,target,arr,dp);
        bool take=false;
        if(target>=arr[index]){
            take=canPatitionsum(index-1,target-arr[index],arr,dp);
        }
        
        dp[index][target]=(take or notake);
        
        return dp[index][target];
        
    }
    
    bool canThreePartsEqualSum(vector<int>& arr) {
        int sum = accumulate(arr.begin(), arr.end(), 0), cnt = 0, partSum=0;
        if(sum%3)
            return false;
        for(int i=0; i<arr.size(); i++)
        {
            partSum += arr[i];
            if(partSum == sum/3)
            {
                if(++cnt == 3)
                    return true;
                partSum = 0;
            }
        }
        return false;
    }
};