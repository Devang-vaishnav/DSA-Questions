class Solution {
public:
    string convert(string s, int numRows) {
        int n = s.size();
        if(n < 3 || numRows == 1) return s;

        vector<vector<char>> v(numRows,vector<char>(n,'$'));
        int i = 0;
        int r = 0;
        int c = 0;
        while(i < n){
            while(i < n && r < numRows){
                v[r++][c] = s[i++];
            }
            r--;
            r--;
            c++;
            while(i < n && r >= 0){
                v[r--][c++] = s[i++];
            }
            r++;
            r++;
            c--;
        }

        string ans = "";
        for(int j = 0; j < numRows; j++){
            for(int k = 0; k < n; k++){
                if(v[j][k] != '$') 
                    ans += v[j][k];
            }
        }
        return ans;
    }
};