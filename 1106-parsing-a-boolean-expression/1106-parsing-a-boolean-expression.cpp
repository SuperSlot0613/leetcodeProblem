class Solution {
public:
    bool parseBoolExpr(string s) {
        stack<char> st;
		for (int i = 0; i < s.size(); ++i) {
			if (s[i] == '(' || s[i] == ',') continue;
			if (s[i] == ')') {
				bool isTrue = false, isFalse = false;
				while (st.top() == 't' || st.top() == 'f') {
					if (st.top() == 't') isTrue = true;
					if (st.top() == 'f') isFalse = true;
					st.pop();
				}
				char temp;
				if (st.top() == '&') {
					temp = isFalse ? 'f' : 't';
					st.pop();
				}
				else if (st.top() == '|') {
					temp = isTrue ? 't' : 'f';
					st.pop();
				}
				else if (st.top() == '!') {
					temp = isTrue ? 'f' : 't';
					st.pop();
				}
				st.push(temp);
			}
			else st.push(s[i]);
		}
		return st.top() == 't';
    }
};