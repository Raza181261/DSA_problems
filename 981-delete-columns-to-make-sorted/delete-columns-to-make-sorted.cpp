class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int colNum = strs[0].size();
        int rowNum = strs.size();
        int delCount = 0;

        for(int col = 0; col<colNum; col++){
            for(int row = 0; row<rowNum-1; row++){
                if(strs[row][col] > strs[row+1][col]){
                delCount++;
                break;
                }
            }
        }
        return delCount;

    }
};