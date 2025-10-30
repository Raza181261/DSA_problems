class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> arr;
        for (int num : nums) {
            arr.push_back(to_string(num));
        }

        // Custom sort: xy > yx means x should come before y
        sort(arr.begin(), arr.end(), [](const string &a, const string &b) {
            return a + b > b + a;
        });

        // Edge case: all numbers are 0
        if (arr[0] == "0") return "0";

        string result;
        for (string &s : arr) {
            result += s;
        }
        return result;
    }
};
