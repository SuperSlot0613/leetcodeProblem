class Solution {
public:
     vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> v;
        int a=firstPosition(nums,target);
        v.push_back(a);
        int b=lastPosition(nums,target);
        v.push_back(b);
        return v;
        
        
    }
    
     int firstPosition(vector<int>& nums, int target){
        int start =0;
        int end = nums.size()-1;
        int mid = start + (end-start)/2;
        int ans = -1;
        while(start<=end){
            if(nums[mid] == target){
                ans = mid;
                end = mid-1;
            }
            if(target>nums[mid]){
                start = mid+1;
            }
            if(target<nums[mid]){
               end = mid -1;
            }
             mid = start + (end-start)/2;
        } 
        return ans;
    }
    
    int lastPosition(vector<int>& nums, int target){
        int start =0;
        int end = nums.size()-1;
        int mid = start + (end-start)/2;
        int ans = -1;
        while(start<=end){
            if(nums[mid] == target){
                ans = mid;
                start = mid+1;
            }
            if(target>nums[mid]){
                start = mid+1;
            }
            if(target<nums[mid]){
               end = mid -1;
            }
             mid = start + (end-start)/2;
        } 
        return ans;
    }
};