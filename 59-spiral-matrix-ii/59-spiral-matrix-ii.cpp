class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int top=0,down=n-1,left=0,right=n-1;
        int val=1;
        vector<vector<int>> matrix(n,vector<int>(n));
        int dir=0;
        while(top<=down && left<=right){
            if(dir==0){
                for(int i=left;i<=right;i++){
                    matrix[top][i]=val;
                    val++;
                }
                top++;
            }
            else if(dir==1){
                for(int i=top;i<=down;i++){
                    matrix[i][right]=val;
                    val++;
                }
                right--;
            }
            else if(dir==2){
                for(int i=right;i>=left;i--){
                    matrix[down][i]=val;
                    val++;
                }
                down--;
            }
            else{
                for(int i=down;i>=top;i--){
                    matrix[i][left]=val;
                    val++;
                }
                left++;
            }
            dir=(dir+1)%4;
        }
        return matrix;
    }
};