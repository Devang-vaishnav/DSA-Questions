class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        int n = s.size();
        int i = 0;
        while(i < n){
            if(s[i] == ')' || s[i] == '}' || s[i] == ']'){
                if(st.empty()) return 0;
                else if(s[i] == ')' && st.top() == '('){
                    st.pop();
                }
                else if(s[i] == '}' && st.top() == '{'){
                    st.pop();
                }
                else if(s[i] == ']' && st.top() == '['){
                    st.pop();
                }
                else {
                    return 0;
                }
            }
            else{
                st.push(s[i]);
            }
            i++;
        }
        if(st.empty()) return 1;
        return 0;
    }
};