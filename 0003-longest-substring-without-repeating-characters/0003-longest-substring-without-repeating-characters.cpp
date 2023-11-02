class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,bool> mp;
        int i = 0;
        int j = 0;
        int mxLen = 0;
        while(j < s.size()){
            if(mp[s[j]] == true){
                mxLen = max(mxLen,(j-i));
                while(s[i] != s[j]){
                    mp[s[i]] = false;
                    i++;
                }
                i++;
            }else{
                mp[s[j]] = true;
            }
            j++;
        }
        mxLen = max(mxLen,(j-i));
        return mxLen;
    }
};