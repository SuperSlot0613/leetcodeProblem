class Solution {
public:
    int missingNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int ans=nums.size();
        for(int i=0;i<nums.size();i++){
            if((nums[i])!=i){
                ans=i;
                break;
            }
        }
        return ans;
    }
};