class Solution {
public:
    int maxSubArray(vector<int>& nums) {
         int sum=0;
        int persum=-100000;
        
        for(int i=0;i<nums.size();i++)
        {
            sum=sum+nums[i];
            
            if(sum<nums[i])
                sum=nums[i];
            if(persum<sum)
                persum=sum;
        }
        return persum;
    }
};