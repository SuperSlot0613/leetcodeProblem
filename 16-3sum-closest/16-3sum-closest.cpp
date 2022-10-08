class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        long long currsum,minsum=INT_MAX;
        
        for(int i=0;i<nums.size();i++){
            for(int j=i+1,z=nums.size()-1;j<z;){
                currsum=nums[i]+nums[j]+nums[z];
                
                if(currsum==target){
                    minsum=currsum;
                    break;
                }else if(abs(target-currsum) < abs(target-minsum) ){
                    minsum=currsum;
                }
                
                if(currsum>target){
                    z--;
                }else{
                    j++;
                }
                
            }
        }
        return minsum;
    }
};