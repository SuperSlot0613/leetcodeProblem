class Solution {
public:
    bool checkAlmostEquivalent(string w1, string w2) {
        unordered_map<int,int>m1,m2;
        
        for(auto it:w1)
            m1[it]++;
        
        for(auto it:w2)
            m2[it]++;
        
        int n=w1.size();
        vector<int>v;
        
        for(int i=0;i<n;i++)
        {
            if(m2.find(w1[i])!=m2.end())
            {
                v.push_back(abs(m1[w1[i]]-m2[w1[i]]));
            }
            else
            {
                v.push_back(m1[w1[i]]);
            }
        }
        
        for(int i=0;i<n;i++)
        {
            if(m1.find(w2[i])!=m1.end())
            {
                v.push_back(abs(m1[w2[i]]-m2[w2[i]]));
            }
            else
            {
                v.push_back(m2[w2[i]]);
            }
        }
        
        int maxi=*max_element(v.begin(),v.end());
        
        if(maxi<=3)
            return true;
        
        return false;
    }
};