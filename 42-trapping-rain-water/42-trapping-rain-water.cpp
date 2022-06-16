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
};