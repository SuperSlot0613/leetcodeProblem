class Solution {
public:
    int count=0;
    void subset(vector<int>&nums,int n,int i,vector<int>&temp){
        
        if(i==n){
            bool ans=true;
            if(temp.size()>=3){
                int diff=abs(temp[1]-temp[0]);
                for(int i=1;i<temp.size()-1;i++){
                    int diff1=abs(temp[i+1]-temp[i]);
                    if(diff!=diff1){
                        ans=false;
                        break;
                    }
                }
            }else{
                ans=false;
            }
            if(ans){
                count++;
            }
            return;
        }
        temp.push_back(nums[i]);
        subset(nums,n,i+1,temp);
        temp.pop_back();
        subset(nums,n,i+1,temp);
    }
    
    int numberOfArithmeticSlices(vector<int>& nums) {
        if(nums.size() < 3)
            return 0;
        
        int cnt = 0, diff;
        
        for(int i = 0; i<nums.size()-2; ++i)
        {
            diff = nums[i+1] - nums[i];
            for(int j = i+2; j<nums.size(); ++j)
            {
                if(nums[j] - nums[j-1] == diff)
                    ++cnt;
                else
                    break;
            }
        }
        return cnt;
    }
};