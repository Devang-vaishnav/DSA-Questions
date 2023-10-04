class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> pascalNumbers;

        for(int r = 0; r < numRows; r++){
            vector<int> row;
            long long ans = 1;
            row.push_back(ans);
            for(int i = 0; i < r; i++){
                ans = ans * (r - i);
                ans = ans / (i+1);
                row.push_back(ans);
            }
            pascalNumbers.push_back(row);
        }
        return pascalNumbers;
    }
};