class Solution {
public:
      void count(vector<int>& nums,vector<int>& result, int start, int end){
        if(start==end) return;
        int mid = (start+end)/2;
        int i,pos;
        count(nums,result,start,mid);
        count(nums,result,mid+1,end);
        vector<int>sortedHalf;
        for(i=mid+1;i<=end;i++) sortedHalf.push_back(nums[i]);
        sort(sortedHalf.begin(),sortedHalf.end());
        for(i=start;i<=mid;i++){
            pos = lower_bound(sortedHalf.begin(),sortedHalf.end(),nums[i])-sortedHalf.begin();
            result[i]+=pos;
        }
    }
      
    
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n,0);
        count(nums,result,0,n-1);
        return result;
        
    }
};