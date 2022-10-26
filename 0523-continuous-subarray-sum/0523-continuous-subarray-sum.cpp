class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        vector<int> arr(nums.size()+1,0);
        for(int i=1;i<=nums.size();i++){
            arr[i]=arr[i-1]+nums[i-1];
        }
        
        set<int> st;
        for(int i=2;i<=nums.size();i++){
            st.insert(arr[i-2]%k);
            if(st.find(arr[i]%k) != st.end()){
                return true;
            }
        }
        return false;
    }
};