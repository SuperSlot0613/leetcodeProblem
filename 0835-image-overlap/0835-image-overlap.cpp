class Solution {
public:
    
    int countValue(int x,int y,vector<vector<int>> m,vector<vector<int>> r){
        int lcount=0,rcount=0;
        int rrow=0;
        for(int i=y;i<m.size();i++){
            int rcol=0;
            for(int j=x;j<m.size();j++){
                if(m[i][j]==1 && m[i][j]==r[rrow][rcol]){
                    lcount++;
                }
                if(m[i][rcol]==1 && m[i][rcol]==r[rrow][j]){
                    rcount++;
                }
                rcol++;
            }
            rrow++;
        }
        return max(lcount,rcount);
    }
    
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int ans=0;
        for(int i=0;i<img1.size();i++){
            for(int j=0;j<img1.size();j++){
                ans=max(ans,countValue(j,i,img1,img2));
                ans=max(ans,countValue(j,i,img2,img1));
            }
        }
        return ans;
    }
};