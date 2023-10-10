class Solution {
public:
    int findMax(vector<vector<int>>& mat, int n, int mid){
        int mx = INT_MIN;
        int row = -1;
        for(int i = 0; i < n; i++){
            if(mat[i][mid] > mx){
                mx = mat[i][mid];
                row = i;
            }
        }
        return row;
    }

    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        int s = 0;
        int e = m-1;
        while(s <= e){
            int mid = s+(e-s)/2;
            int row = findMax(mat,n,mid);
            int left = (mid-1) >= 0 ? mat[row][mid-1] : -1;
            int right = (mid+1) < m ? mat[row][mid+1] : -1;
            if(mat[row][mid] > left && mat[row][mid] > right){
                return {row,mid};
            }else if(mat[row][mid] < left){
                e = mid-1;
            }else{
                s = mid+1;
            }
        }
        return {-1,-1};
    }
};