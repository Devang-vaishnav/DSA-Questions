class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string st = strs[0];
        for(int i = 1; i < strs.size(); i++){
            int k = 0;
            for(int j = 0; j < strs[i].size(); j++){
                if(k < st.size() && st[k] != strs[i][j]){
                    st.erase(k,st.size()-k);
                    break;
                }
                k++;
                if(k == st.size()){
                    break;
                }
            }
            if(k < st.size()) st.erase(k,st.size()-k);
        }
        return st;
    }
};