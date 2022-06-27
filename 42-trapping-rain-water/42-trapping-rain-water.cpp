class Solution {
public:
    int trap(vector<int>& v) {
        int n=v.size();
        int l=0,r=n-1;
        int res=0,leftmax=0,rightmax=0;
        while(l<r){
            if(v[l]<=v[r]){
                if(v[l]>=leftmax){
                    leftmax=v[l];
                }
                else{
                    res+=leftmax-v[l];
                }
                l++;
            }else{
                if(v[r]>=rightmax){
                    rightmax=v[r];
                }else{
                    res+=rightmax-v[r];
                }
                r--;
            }
        }
        return res;
    }
    
    int waterTrapped(vector<int>&v){
        int watretraped=0;
        int n=v.size();
        for(int i=0;i<v.size();i++){
            int j=i;
            int leftmax=0,rightmax=0;
            while(j>=0){
                leftmax=max(leftmax,v[i]);
                j--;
            }
            j=i;
            while(j<n){
                rightmax=max(rightmax,v[i]);
                j++;
            }
            
            watretraped+=min(leftmax,rightmax)-v[i];
        }
        return watretraped;
    }
    
};