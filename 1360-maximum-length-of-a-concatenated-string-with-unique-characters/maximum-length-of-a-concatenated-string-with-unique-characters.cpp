class Solution {
public:

    bool hashDuplicate(string &s1, string &s2){
        int arr[26] ={0};

        for(char &ch : s1){
            if(arr[ch-'a'] > 0)
            return true;
            arr[ch-'a']++;
        }

        for(char &ch : s2){
            if(arr[ch-'a'] > 0)
            return true;
        }
        return false;
    }

    int solve(vector<string>& arr, string temp, int n, int i){
        if(i >= n)
        return temp.length();

        int exclude = 0;
        int include = 0;

        if(hashDuplicate(arr[i], temp)){
            exclude = solve(arr, temp, n, i+1);
        }else{
            exclude = solve(arr, temp, n, i+1);
            include = solve(arr, temp+arr[i], n, i+1);
        }

        return max(include, exclude);
    }
    int maxLength(vector<string>& arr) {
        string temp = "";
        int n = arr.size();
        int i = 0;

        return solve(arr, temp, n, i);
    }
};