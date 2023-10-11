class Solution {
public:
    string reverseWords(string s) {
        string st = "";
        int wordCnt = 0;
        if(s[0] != ' '){
            st+=s[0];
        }
        for(int i = 1; i < s.size(); i++){
            if(s[i] == ' ' && s[i-1] == ' '){
                continue;
            }else{
                st+=s[i];
            }
        }
        if(st.back() == ' ') st.resize(st.size()-1);
        reverse(st.begin(),st.end());
        int it = 0;
        for(int i = 0; i < st.size(); i++){
            if(st[i] == ' '){
                reverse(st.begin()+it,st.begin()+i);
                it = i+1;
            }
        }
        reverse(st.begin()+it,st.end());
        return st;
    }
};