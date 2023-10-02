class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        // int n = matrix.size();
        // int m = matrix[0].size();

        // for(int i = 0; i < n; i++){
        //     for(int j = 0; j < m; j++){
        //         if(matrix[i][j] == 0){
        //             matrix[0][j] = 0;
        //             matrix[i][0] = 0;
        //         }
        //     }
        // }

        // for(int i = 1; i < n; i++){
        //     if(matrix[i][0] == 0){
        //         for(int j = 0; j < m; j++){
        //             matrix[i][j] = 0;
        //         }
        //     }
        // }

        // for(int i = 0; i < m; i++){
        //     if(matrix[0][i] == 0){
        //         for(int j = 0; j < n; j++){
        //             matrix[j][i] = 0;
        //         }
        //     }
        // }

        // if(handle){
        //     for(int i = 0; i < m; i++){
        //         matrix[0][i] = 0;
        //     }
        // }

        int n = matrix.size();
        int m = matrix[0].size();
        vector<bool> arr1(n,false);
        vector<bool> arr2(m,false);

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(matrix[i][j] == 0){
                    arr1[i] = true;
                    arr2[j] = true;
                }
            }
        }

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(arr1[i] == true || arr2[j] == true){
                    matrix[i][j] = 0;
                }
            }
        }

    }
};