class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxi = 0;
        int n = nums.size();
        
        for(int i = 0 ; i<n ; i++) {
            if(i > maxi) return false;
            maxi = max(nums[i] + i , maxi);
        }
        return true;
        
    }
};