class Solution {
public:
    int findTheWinner(int n, int k) {
        
        queue<int> qe;
        int count=1;
        for(int i=1;i<=n;i++){
            qe.push(i);
        }
        
        while(qe.size()>1){
            if(count==k){
                qe.pop();
                count=1;
                continue;
            }
            int val=qe.front();
            qe.pop();
            qe.push(val);
            count++;
        }
        
        return qe.front();
        
    }
};