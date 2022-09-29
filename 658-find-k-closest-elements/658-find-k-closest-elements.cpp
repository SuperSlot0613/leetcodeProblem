class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<pair<int,int>> store;
        for(auto  it:arr){
            int num = it;
            int diff = abs(num-x);
            store.push_back({diff,num});
            
        }
        sort(store.begin(),store.end());
        vector<int> ans;
        for(int i=0;i<k;i++){
            ans.push_back(store[i].second);
            
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};