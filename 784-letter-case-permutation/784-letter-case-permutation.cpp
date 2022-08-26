class Solution {
public:
    
    void func(int ind, string curr, string &s, vector<string> &answer){
        if(ind == s.size()){
            answer.push_back(curr);
            return;
        }

        if((s[ind] >= 'a' && s[ind] <= 'z') || (s[ind] >= 'A' && s[ind] <= 'Z')){
            curr += toupper(s[ind]);
            func(ind + 1, curr, s, answer);

            int del = curr.size() - 1;
            curr.erase(curr.begin() + del);
            curr += tolower(s[ind]);
            func(ind + 1, curr, s, answer);
        }else{
            curr += s[ind];
            func(ind + 1, curr, s, answer);
        }
    }

    vector<string> letterCasePermutation(string s) {
        vector<string> answer;
        string curr = "";
        int ind = 0;
        func(ind, curr, s, answer);
        return answer;
    }
};