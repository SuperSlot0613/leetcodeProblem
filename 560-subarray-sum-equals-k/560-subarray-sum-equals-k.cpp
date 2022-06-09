class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> ma;
        int count=0;
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum=sum+nums[i];
            if(sum==k) count++;
            
            if(ma.find(sum-k)!=ma.end()){
                count=ma[sum-k]+count;
            }
            
            if(ma.find(sum)!=ma.end()){
                ma[sum]++;
            }else{
                ma[sum]=1;
            }
        }
        return count; 
    }
};