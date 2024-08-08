class Solution {
    void rotate(vector<vector<int>>& matrix){
        int n = matrix.size();
        for(int i = 0; i<n; i++){
            for(int j = 0; j<i; j++){
                int temp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = temp;
            }
        }

        int start = 0;
        int end = matrix.size()-1;
        while(start<=end){
            for(int row = 0; row<matrix.size(); row++){
                int temp = matrix[row][start];
                matrix[row][start] = matrix[row][end];
                matrix[row][end] = temp;
            }
            start++;
            end--;
        }
    }
    bool check(vector<vector<int>>& matrix, vector<vector<int>>& target){
            for(int i =0; i<matrix.size(); i++){
                for(int j = 0; j<matrix.size(); j++){
                    if(matrix[i][j] != target[i][j]){
                        return  false;
                    }
                }
            }
            return true;
        }
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        
        for(int i = 0; i<4; i++){
            if(check(mat,target)){
                return true;
            }
            rotate(mat);
        }
        return false;
    }
};