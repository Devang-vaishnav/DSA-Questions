class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int mxlen = 0;
        for(int i = 0; i < n; i++){
            vector<bool> arr(256,false);
            int len = 0;
            for(int j = i; j < n; j++){
                if(arr[int(s[j])] != false) break;
                arr[int(s[j])] = true;
                len++;
            }
            mxlen = max(mxlen,len);
        }
        return mxlen;
    }
};