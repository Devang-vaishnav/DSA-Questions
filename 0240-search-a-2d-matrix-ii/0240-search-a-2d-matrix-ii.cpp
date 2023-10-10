class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        int row = 0;
        int col = m-1;
        while( row < n && col >= 0){
            int num = matrix[row][col];
            if(num == target){
                return 1;
            }else if(num < target){
                row++;
            }else{
                col--;
            }
        }
        return 0;
    }
};