class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.size() != t.size()) return 0;
        unordered_map<char,char> mp1;
        unordered_map<char,char> mp2;
        for(int i = 0; i < s.size(); i++){
            if(mp1.find(s[i]) != mp1.end()){
                if(mp1[s[i]] != t[i]) return 0;
            }
            if(mp2.find(t[i]) != mp2.end()){
                if(mp2[t[i]] != s[i]){
                    return 0;
                }
            }
            mp1[s[i]] = t[i];
            mp2[t[i]] = s[i];
        }
        return 1;
    }
};