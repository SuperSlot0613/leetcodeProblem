class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> v(2,0);
      
        
        for(int i=0;i<nums.size()-1;i++){
            int temp=target-nums[i];
            auto it=find(nums.begin()+i+1,nums.end(),temp);
            if(it!=nums.end()){
                v[0]=i;
                int index=it-nums.begin();
                v[1]=index;
                break;
            }
        }
        return v;
    }
};