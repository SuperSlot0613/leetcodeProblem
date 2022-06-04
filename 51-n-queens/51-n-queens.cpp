class Solution {
public:
    
 void rec(int row,vector<int> &pos,vector<int> &visited,
            vector<string> &temp,vector<vector<string>> &ans)
{
    int n=visited.size();
    if(row==n)  
    {
        ans.push_back(temp);
        return;
    }

    for(int i=0;i<n;i++)
    {
        if(visited[i]==1)   continue;
        int x=row,y=i;  
        int clash=0;    

        for(int j=0;j<pos.size();j++)
        {
            // j is row, pos[j] is col
            if(abs(j-x)==abs(pos[j]-y)) 
            {
                clash=1;
                break;
            }
        } 
        if(clash==0)    
        {
            pos.push_back(i);
            visited[i]=1;
            temp[row][i]='Q';
            rec(row+1,pos,visited,temp,ans);
            temp[row][i]='.';
            visited[i]=0;
            pos.pop_back();
        }
    }
}
    
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<int> pos;
        vector<int> visited(n,0);   
        vector<string> temp(n,string(n,'.'));  

        rec(0,pos,visited,temp,ans);

        return ans;
    }
};