class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int elem=0;
        for(int i=0;i<nums.size();i++){
            elem=elem^nums[i];
        }
        
        return elem;
    }
};