class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            if(k>0){
                if(nums[i]<0){
                    nums[i]=nums[i]*(-1);
                    k--;
                }
            }
        }
        int sum= accumulate(nums.begin(),nums.end(),0);
        sort(nums.begin(),nums.end());
        int minim=nums[0];
        if(k%2==0){
            return sum;
        }
        return sum-minim-minim;
    }
};