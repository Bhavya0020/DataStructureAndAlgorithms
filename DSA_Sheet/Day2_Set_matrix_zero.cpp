// Problem Statement: https://leetcode.com/problems/set-matrix-zeroes/
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int col0 = 1, row = matrix.size(), col = matrix[0].size();
        for(int i = 0; i < row; i++){
            if(matrix[i][0] == 0) col0=0;
            for(int j = 1; j < col; j++){
                if(matrix[i][j] == 0){
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
//       Important: j is always take from 1 as column 0 is left for row_mapping
        for(int i = row-1; i >= 0; i--){
            for(int j = col-1; j >= 1; j--){
                if(matrix[i][0] == 0 || matrix[0][j] == 0){
                    matrix[i][j] = 0;
                }
            }
            if(col0==0){
                matrix[i][0] = 0;
            }
        }
    }
};
