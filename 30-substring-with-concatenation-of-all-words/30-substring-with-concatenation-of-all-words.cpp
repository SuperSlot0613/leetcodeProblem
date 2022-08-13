class Solution {
public:
    int wordLength;
    bool match(string s, unordered_map<string, int> words, int beg, int end) {
        string temp = "";
        for(int i = beg; i <= end; i++) {
            temp += s[i];
            if((i - beg + 1) % wordLength == 0) {
                if(words[temp] == 0) return false;
                words[temp]--;
                temp = "";
            }
        }
        return true;
    }
    vector<int> findSubstring(string s, vector<string>& words) {
        wordLength = words[0].size();
        int totalLength = words.size() * wordLength;
        vector<int> ans;
        unordered_map<string, int> mp;
        
        for(auto word : words) mp[word]++;
        
        for(int i = 0; i + totalLength - 1 < s.size(); i++) {
            if(match(s, mp, i, i + totalLength - 1)) ans.push_back(i);
        }
        
        return ans;
    }
};