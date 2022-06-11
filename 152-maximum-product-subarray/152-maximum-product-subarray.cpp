class Solution {
public:
    int maxProduct(vector<int>& nums) {
         int curr_maxx=1;
        int res=INT_MIN;
        for(auto x:nums){
            curr_maxx*=x;
            res=max(res,curr_maxx);
            if(x==0){
                curr_maxx=1;
            }
        }
        
        //right->left
        curr_maxx=1;
        reverse(nums.begin(),nums.end());
        for(auto x:nums){
            curr_maxx*=x;
            res=max(res,curr_maxx);
            if(x==0){
                curr_maxx=1;
            }
        }
        return res;
    }
};