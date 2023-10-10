class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        int s = 0;
        int e = n-1;
        int mid = s+(e-s)/2;
        while(s <= e){
            if(matrix[mid][0] == target){
                return true;
            }else if(matrix[mid][0] < target){
                s = mid+1;
            }else{
                e = mid-1;
            }
            mid = s+(e-s)/2;
        }

        int row = mid-1;
        if(row < 0){
            return false;
        }
        s = 0;
        e = m-1;

        while(s <= e){
            int mid = s+(e-s)/2;
            if(matrix[row][mid] == target){
                return true;
            }else if(matrix[row][mid] < target){
                s = mid+1;
            }else{
                e = mid-1;
            }
        }
        return false;
    }
};