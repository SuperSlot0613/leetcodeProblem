class Solution {
public:
    bool searchMatrix(vector<vector<int>>& v, int target) {
        int rows =0;
        int cols = v[0].size()-1;
        int n=v.size();

        while(rows<n && cols>=0){

            if(v[rows][cols]==target){
                return true;
            }
            else if (v[rows][cols]>target){
                cols--;
            }
            else
                rows++;
        }
        return false; 
    }
};