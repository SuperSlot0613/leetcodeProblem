class Solution {
public:
    int ans=INT_MIN;
    
    void maxPoint(vector<int>& nums,vector<int>& temp,int point){
        if(temp.empty()){
            ans=max(ans,point);
            return;
        }
        for(int i=0;i<nums.size();i++){
            int val=nums[i];
            point+=val;
            remove(temp.begin(),temp.end(),val);
            remove(temp.begin(),temp.end(),val-1);
            remove(temp.begin(),temp.end(),val+1);
            maxPoint(temp,temp,point);
            temp.clear();
            point=0;
            copy(temp.begin(), temp.end(), back_inserter(nums));
        }
    }
    
    int deleteAndEarn(vector<int>& nums) {
        vector<int> temp(10001,0);
        int inc=0;
        int exc=0;
        for(int val : nums){
            temp[val]++;
        }
        for(int i=0;i<=10000;i++){
            int ni=exc+temp[i]*i;
            int ne=max(inc,exc);
            inc=ni;
            exc=ne;
        }
        return max(inc,exc);
    }
};