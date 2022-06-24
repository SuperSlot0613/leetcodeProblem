class Solution {
public:
    bool isPossible(vector<int>& target) {
        if(target.size()==1){
            return target[0] == 1;
        }
        long sum = 0;
        for(int i=0; i<target.size();i++){
            sum += target[i];
        }
        priority_queue<int> pq(target.begin(), target.end());
        while(pq.top() != 1){
            long largest = pq.top();
            pq.pop();
            long largest_2 = pq.top();
            long restArrSum = sum - largest;

            int n = max(1l, (largest-largest_2)/restArrSum);

            largest -= (restArrSum * n);

            pq.push(largest);
            sum = restArrSum + largest;

            if(largest<1)
                return false;
        }
        
        return true;
        
    }
};