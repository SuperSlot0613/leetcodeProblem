class Solution {
public:
    int mod=1000000007;
    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<int> temp(n+1,1);
        for(int i=1;i<=n;i++){
            temp[i]=(2*temp[i-1])%mod;
        }
        int i=0,j=n-1,count=0;
        while(i<=j){
            if((nums[i]+nums[j])<=target){
                count=(count+temp[j-i])%mod;
                i++;
            }else{
                j--;
            }
        }
        return count;
    }
};