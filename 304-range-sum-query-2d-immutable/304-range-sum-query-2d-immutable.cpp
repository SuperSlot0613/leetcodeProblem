class NumMatrix {
public:
    int pref[201][201];
    NumMatrix(vector<vector<int>>& mat) {
        
        int m = mat.size() , n = mat[0].size();
        
        for(int i=0; i<m ; i++ ){
            for(int j=0; j< n ; j++ ){
                pref[i][j] = mat[i][j];
                if(i > 0){
                    pref[i][j] += pref[i-1][j];
                }
            }
        }
        for(int i=0; i<m ; i++ ){
            for(int j=1; j< n ; j++ ){
                pref[i][j] += pref[i][j-1];
            }
        } 
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int ans = pref[row2][col2];
        
        if(row1 > 0 ) ans-= pref[row1-1][col2];
        if(col1 > 0 ) ans-= pref[row2][col1-1];
        if(row1 > 0 && col1 > 0) ans+= pref[row1-1][col1-1];
        
        return ans;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */