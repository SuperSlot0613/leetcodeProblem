class Solution {
public:
    int jump(vector<int>& arr) {
        
        int n=arr.size();
        
        int count=0;
        int currJump=0;
        int farthestjump=0;

        for(int i=0;i<n-1;i++){
            farthestjump=max(farthestjump,arr[i]+i);
            if(i==currJump){
                currJump=farthestjump;
                count++;
            }
        }
        
        return count;
    }
};