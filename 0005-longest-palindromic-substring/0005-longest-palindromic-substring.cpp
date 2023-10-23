class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        int start = 0, end = 1;
        int low,high;

        for(int i = 0; i < n; i++){
            //when length of palindromic substring is even.
            low = i-1;
            high = i;
            while(low >= 0 && high < n && s[low] == s[high]){
                int len = (high - low) + 1;
                if(len > end){
                    start = low;
                    end = len;
                }
                low--;
                high++;
            }

            //when length of palindromic substring is odd.
            low = i-1;
            high = i+1;
            while(low >= 0 && high < n && s[low] == s[high]){
                int len = (high - low) + 1;
                if(len > end){
                    start = low;
                    end = len;
                }
                low--;
                high++;
            }
        }

        string ans = "";
        int t = start + end - 1;
        for(int i = start; i <= t; i++){
            ans += s[i];
        }
        return ans;
    }
};