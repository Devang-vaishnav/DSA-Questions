class Solution {
public:

    long long generateNumber(int n, int r){
        long long ans = 1;

        for(long long i = 0; i < r; i++){
            ans = ans * (n-i);
            ans = ans / (i+1);
        }
        return ans;
    }
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> pascalNumbers;

        for(int i = 1; i <= numRows; i++){
            vector<int>temp;
            for(int c = 1; c <= i; c++){
                temp.push_back(generateNumber(i-1,c-1));
            }
            pascalNumbers.push_back(temp);
        }
        return pascalNumbers;
    }
};