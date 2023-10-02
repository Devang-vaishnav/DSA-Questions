class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
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
                if(arr1[i] == true && arr2[j] == true){
                    for(int k = 0; k < m; k++){
                        matrix[i][k] = 0;
                    }
                    for(int k = 0; k < n; k++){
                        matrix[k][j] = 0;
                    }
                }
            }
        }

    }
};