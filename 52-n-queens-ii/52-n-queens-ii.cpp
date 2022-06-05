class Solution {
public:
    int count=0;
    bool Issafe(vector<vector<bool>>& grid,int row,int col,int n){
        
        for(int i=row-1;i>=0;i--){
            if(grid[i][col]){
                return false;
            }
        }
        
        for(int i=row-1,j=col+1;i>=0&&j<n;i--,j++){
            if(grid[i][j])
                return false;
        }
        
        for(int i=row-1,j=col-1;i>=0&&j>=0;i--,j--){
            if(grid[i][j])
                return false;
        }
        return true;
    }
    
    void countQueens(vector<vector<bool>>& grid,int curr_row,int n){
        
        if(curr_row==n){
            count++;
            return;
        }
        
        for(int i=0;i<n;i++){
            if(Issafe(grid,curr_row,i,n)){
                grid[curr_row][i]=true;
                countQueens(grid,curr_row+1,n);
                grid[curr_row][i]=false;
            }
        }

    }
    
    int totalNQueens(int n) {
      vector<vector<bool>> grid( n , vector<bool> (n, false));
      countQueens(grid,0,n);
      return count;
    }
};