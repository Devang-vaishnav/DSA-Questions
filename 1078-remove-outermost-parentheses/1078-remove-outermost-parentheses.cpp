class Solution {
public:
    string removeOuterParentheses(string s) {
        string st = "";
        int cnt = 0;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '(' && cnt == 0){
                cnt++;
                continue;
            }else if(s[i] == ')' && cnt == 1){
                cnt--;
                continue;
            }else if(s[i] == '('){
                cnt++;
                st+='(';
            }else{
                cnt--;
                st+=')';
            }
        }
        return st;
    }
};