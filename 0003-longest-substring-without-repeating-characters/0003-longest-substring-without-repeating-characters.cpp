class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int mxlen = 0;
        if(n == 0) return mxlen;
        vector<bool> arr(256,false);
        int i = 0;
        int j = 0;
        int len = 0;
        while(j < n){
            if(arr[int(s[j])] != false){
                arr[int(s[i])] = false;
                i++;
                len--;
            }else{
                arr[int(s[j])] = true;
                j++;
                len++;
            }
            mxlen = max(len,mxlen);
        }
        return mxlen;
    }
};