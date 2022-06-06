class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        vector<string>ans;
        int n1=list1.size();
        int n2=list2.size();
        unordered_map<string,int>m;
        for(int i=0;i<n1;i++){
            m[list1[i]]=i;
        }
        int min=INT_MAX;
        for(int i=0;i<n2;i++){
            if(m.find(list2[i])!=m.end()){
               if(min>=i+m[list2[i]]){
                    if(min>i+m[list2[i]]){
                   ans.clear();
                   min=i+m[list2[i]];
                 }
                ans.push_back(list2[i]);
               }
            }
        }
        return ans;
    }
};