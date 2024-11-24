class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int colSize = strs[0].size();
        int rowSize = strs.size();
        int delCount = 0;

        for(int col = 0; col<colSize; col++){
            for(int row = 0; row<rowSize-1; row++){
                if(strs[row][col] > strs[row+1][col]){
                delCount++;
                break;
                }
            }
        }
        return delCount;

    }
};