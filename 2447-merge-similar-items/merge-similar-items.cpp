class Solution {
public:
    vector<vector<int>> mergeSimilarItems(vector<vector<int>>& items1, vector<vector<int>>& items2) {
        map<int,int>mergedItem;

        for(auto num1: items1){
            mergedItem[num1[0]] += num1[1];
        }

        for(auto num2: items2){
            mergedItem[num2[0]] += num2[1];
        }

        vector<vector<int>> result;
        for(auto [value,weight] : mergedItem){
            result.push_back({value,weight});
        }

        return result;
    }
};